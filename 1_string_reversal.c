#include<stdio.h>
#include<string.h>

char stack[100];      
int top=-1;            

void push(char ch){
    if (top==99){
        printf("Stack overflow");
        return;
    }

    top++;
    stack[top]=ch;
}

void pop(){
    if(top==-1){
        printf("Stack underflow");
    }
    else{
        printf("%c", stack[top]);
        top--;
    }
}

int main(){

    char word[100];
    printf("Enter a word: ");
    scanf("%s", word);
 
    int len=strlen(word);

    for(int i=0;i<len;i++){
        push(word[i]);
    }

    for(int i=0;i<len;i++){
        pop();
    }

    return 0;
}