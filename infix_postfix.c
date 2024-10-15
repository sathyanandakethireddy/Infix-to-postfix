#include "main.h"
#include <string.h>

int Infix_Postfix_conversion(char *Infix_exp, char *Postfix_exp, Stack_t *stk)
{
   int j=0;
   for(int i=0;i<strlen(Infix_exp);i++)
   {
       char ch=Infix_exp[i];
       if(ch>='0' && ch<='9')
       {
           Postfix_exp[j++]=ch;
           //Postfix_exp[j++]=' ';
       }
       else
       {
           if(stk->top==-1)
           {
               push(stk,ch);
           }
           else
           {
               if(ch=='(')
               {
                   push(stk,ch);
               }
               else if(ch==')')
               {
                   while(stk->stack[stk->top]!='(')
                   {
                       Postfix_exp[j++]=peek(stk);
                       //Postfix_exp[j++]='';
                       pop(stk);
                   }
                   pop(stk);
               }
               else
               {
                  if(priority(peek(stk))>=priority(ch))
                  {
                      Postfix_exp[j++]=peek(stk);
                      //Postfix_exp[j++]='';
                      pop(stk);
                      push(stk,ch);
                  }
                  else
                  {
                      push(stk,ch);
                  }
               }
           }
       }
   }
   while(stk->stack[stk->top]!=-1)
   {
       Postfix_exp[j++]=peek(stk);
       pop(stk);
   }
   Postfix_exp[j]='\0';
   return 0;
}
