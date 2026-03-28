#include <stdio.h>
#include <string.h>
#define MAX 100
char stack[MAX];
int top=-1;
void push(char x){
    stack[++top]=x;
}

char pop(){
    return stack[top--];
}

int isBal(char expr[]){
    int i=0;

    while (expr[i]!='\0'){
        if (expr[i]=='('){
            push(expr[i]);
        }
        else if (expr[i]==')'){
            if (top==-1){
                return 0;
            }
            char topChar=pop();

            if (expr[i]==')' && topChar!='('){
                return 0;
            }
        }

        i++;
    }

    return (top==-1);
}

int main(){
    char expr[MAX];

    printf("Enter Expression: ");
    scanf("%s", expr);

    top=-1;

    if (isBal(expr))
        printf("Balanced Expression");
    else{
        printf("Unbalanced Expression");
    }

    return 0;
}