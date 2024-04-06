#include "stack_queue.h"

int getnum()
{
  int ch = 0;
  int num = 0;
  int ct = 0;
  while((ch = getchar())>='0' && ch <= '9')
  {
    ct++;
    ch -= '0';
    num = num * 10 + ch;
  }
  ungetc(ch, stdin);
  if (ct == 0)
      return -1;
  else
    return num;
}

int main(){
  //declaring variables
  queue qu;
  stack st;
  int stcount = 0, qucount = 0, buff, order[100] = {0}, numberOfCount[100] = {0}, numCountIt = 0, firstNum, secNum, product;
  int *s = (int *)malloc(100);
  int *s2 = s;
  order[0] = 5;
  printf("Please input your math expression with NO SPACES:\n");
  //the actual loop
  while((buff = getchar()) != '\n'){
  if(qucount == 0)
  {
    printf("\nIn Postfix: ");
  }
    ungetc(buff, stdin);
    //Placing order to each case
    if(qucount > 0)
    {
      buff = getchar();
      switch(buff){
        case '+':
        case '-':
          order[stcount] = 1;
          break;
        case '*':
        case '/':
          order[stcount] = 2;
          break;
        case '(':
          order[stcount] = 3;
          qucount--;
          qu.deq();
          break;
        case ')':
          order[stcount] = 4;
        break;
      }
      if (order[stcount] == 3)
      {
        numCountIt++;
        numberOfCount[numCountIt] = stcount;
      }
      else if (order[stcount] == 4)
      {
        for(int i = 1; stcount > numberOfCount[numCountIt]; i++)
        {
          *s = st.pop();
          printf("%c ", *s);
          s++;
          stcount--;
        }
        numberOfCount[numCountIt] = 0;
        numCountIt--;
      }
        else if(stcount > numberOfCount[numCountIt])
        {
          if(order[stcount] <= order[stcount-1])
          {
            while(order[stcount] <= order[stcount-1] && stcount > 0)
            {
              order[stcount-1] = order[stcount];
              order[stcount] = 0;
              *s = st.pop();
              printf("%c ", *s);
              s++;
              stcount--;
            }
            st.push(buff);
            stcount++;
          }
          else
          {
            st.push(buff);
            stcount++;
          }
        }
        else
        {
          st.push(buff);
          stcount++;
        }
        //printf("%c", st.getData(stcount));
      }
      //Gets and checks for number
      buff = getnum();
      qucount++;
      if(buff > -1)
      {
        qu.enq(buff);
        *s = qu.deq();
        printf("%d ", *s);
        s++;
      }
      //printf("%d", qu.getData(qucount));
    }
    for(int i = 1; stcount > 0; i++)
    {
      *s = st.pop();
      printf("%c ", *s);
      s++;
      stcount--;
    }
  //Solving the Postfix
  printf("\nSolved equation: ");
  
  for(; *(s2) != 0; s2++)
    {
      if(*s2 != '+' && *s2 != '-' && *s2 != '*' && *s2 != '/')
      {
        st.push(*s2);
        stcount++;
      }
      else if(*s2 == '+' || *s2 == '-' || *s2 == '*' || *s2 == '/')
      {
        qu.enq(*s2);
        qucount++;
        secNum = st.pop();
        firstNum = st.pop();
        stcount -= 2;
        
        switch(*s2){
          case '+':
            product = firstNum + secNum;
            st.push(product);
            break;
          case '-':
            product = firstNum - secNum;
            st.push(product);
            break;
          case '*':
            product = firstNum * secNum;
            st.push(product);
            break;
          case '/':
            product = firstNum / secNum;
            st.push(product);
            break;
        }
      }
    }
  printf("%d", st.pop());
}