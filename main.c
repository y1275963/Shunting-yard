#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main(){
    val container[stack_size] = {0};
    struct buffer_stack head_con;
    struct buffer_stack * head;
    head = & head_con;
    init(container,head);
    //val temp;

    val flo_container[stack_size] = {0};
    struct buffer_stack  flo_con;
    struct buffer_stack * flo;
    flo = & flo_con;
    init(flo_container,flo);

    push('1',head);
    push('/',head);
    push('3',head);
    push('3',head);

  /*  if( 1 ){
        float temp = eval(head);
        char c[50]="0";
        stack2str(c,head);
        printf("%d\n",head_loc(head));
       printf("%d",atoi(c));
       // printf("%f",temp);
      //  printf("%c",peek(head));
       // eval(head);
       // printf("%f",two_eval(3.1,'-',12));
        //eval(head);
    }*/
    construct_buffer(head,flo);
    float temp = eval(flo);
    printf("%f",temp);

    //buffer_reverse(head);
  //  temp_debug(head);


  /*  while(temp != 'e'){
        switch(temp){
            case '#':{
                    pop(&temp,head);
                    i--;
                    break;
                }
            case 'f':{
                scanf(" %c",&temp);
                continue;
                }
            default :{
                push(temp,head);
                i++;
                break;
                }
        }
        if( i <= stack_size -1 ){
            //maximum capacity stack_size -1
            scanf(" %c",&temp);
        }
        else{
            printf("full");
            init(container,head);
            i = 0;
            temp = 'f';
        }
    }
    temp_debug(head);*/
    return 0;
}
