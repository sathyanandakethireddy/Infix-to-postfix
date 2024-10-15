#include<string.h>
#include "main.h"
int operator(char ch);
int Postfix_Eval(char *Postfix_exp, Stack_t *stk) {
    char ch;
    for (int i = 0; i < strlen(Postfix_exp); i++) {
        ch = Postfix_exp[i];
        if (ch >= '0' && ch <= '9')
        {
            push(stk, ch - '0'); 
        } 
       
        else if (operator(ch))
        {
            int res2 = stk->stack[stk->top--];
            int res1 = stk->stack[stk->top--];

            switch (ch) {
                case '+':
                    push(stk, res1 + res2);
                    break;
                case '-':
                    push(stk, res1 - res2);
                    break;
                case '*':
                    push(stk, res1 * res2);
                    break;
                case '/':
                    if (res2 == 0) 
                    { 
                       
                        return -1; 
                    }
                    push(stk, res1 / res2);
                    break;
            }
        }
    }
    return stk->stack[stk->top]; 
}
