#include "cal.h"

float eval(struct buffer_stack * buffer){

    val flo_container[stack_size] = {0};
    struct buffer_stack  flo_con;
    struct buffer_stack * flo;
    flo = & flo_con;
    init(flo_container,flo);

    construct_buffer(buffer,flo);


    val container_oper[stack_size] = {0};
    val container_numb[stack_size] = {0} ;
    struct buffer_stack con_oper;
    struct buffer_stack con_numb;

    struct buffer_stack * oper;
    struct buffer_stack * numb;

    oper = & con_oper;
    numb = & con_numb;

    init(container_oper,oper);
    init(container_numb,numb);

    push('@',oper);
    push(0,numb);

    val inspector;
    int code;
    val exp1;
    val para;
    val exp2;

    float temp_result;

    do{
      //temp_debug(buffer);

      //stage 1
      if(head_loc(flo) != 0){
        pop(&inspector,flo);
        code = encoder(inspector);
        if(code == NUM)
        {
            push(inspector,numb);
        }
        else if( code > encoder(peek(oper)) )
        {
            push(inspector,oper);
        }
        else if( code <= encoder(peek(oper)) ){ //exp1 para exp2
            pop(&exp2,numb);
            pop(&para,oper);
            pop(&exp1,numb);
            temp_result = two_eval(exp1,para,exp2);
            push(temp_result,numb);
            push(inspector,flo);
        }
      }
      //stag two
      else if(peek(oper) != '@'){
            pop(&exp2,numb);
            pop(&para,oper);
            pop(&exp1,numb);
            temp_result = two_eval(exp1,para,exp2);
            push(temp_result,numb);
      }
      }while( peek(oper) != '@' || head_loc(flo) != 0 );

    pop(&temp_result,numb);
    return temp_result;
}

float two_eval(val exp1, val para, val exp2){

    char code = (char) para;
    switch(code){
        case '+' : return (exp1 + exp2); break;
        case '-' : return (exp1 - exp2); break;
        case '*' : return (exp1 * exp2); break;
        case '/' : return (exp1 / exp2); break;
        default :
            return -1;
    }
}

int encoder(val input){
    int output;
    int int_input = (char)input;
    switch(int_input){
        case '+' :
        case '-' : output = MIDDLE; break;
        case '@' : output = LOWEST; break;
        case '*' :
        case '/' : output = HIGHEST; break;
        default :
            output = NUM;
    }
    return output;
}

int construct_buffer(struct buffer_stack * input,struct buffer_stack * flo){
    val se_container[stack_size] = {0};
    struct buffer_stack  se_con;
    struct buffer_stack * se;
    se = & se_con;
    init(se_container,se);

    val temp;
    char c[50] = "0";


    while(head_loc(input) != 0){
        pop(&temp,input);
        if(encoder(temp) == NUM){
            push(temp,se);
        }else{
            buffer_reverse(se);
            stack2str(c,se);
            push(atoi(c),flo);
            push(temp,flo);
            init(se_container,se);
        }
    }
    buffer_reverse(se);
    stack2str(c,se);
    push(atoi(c),flo);

    return 0;
}
