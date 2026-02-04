#include<stdio.h>
#include<ctype.h>
#include<string.h>
#define MAX 100
char stack[MAX];
int top=-1;

void push(char c){
    stack[++top]=c;
}
char pop(){
    return stack[top--];
}

int precedence(char op){
    if(op=='^')
        return 3;
    else if(op=='*'|| op=='/')
        return 2;
    else if (op=='+'||op=='-')
        return 1;
    else 
        return 0;
}
void infixtopostfix(char infix[],char postfix[]){
    int i,k=0;
    char c;
    for(i=0;i<strlen(infix);i++){
         c=infix[i];
        if(isalnum(c)){
            postfix[k++]=c;
        }else if(c=='('){
            push(c);
        }else if(c==')'){
            while(stack[top]!='('){
                postfix[k++]=pop();
            }pop();
        }else{
            while(top!=-1&&precedence(stack[top])>=precedence(c))
                postfix[k++]=pop();
            push(c);
            
        }}
        while(top!=-1){
        postfix[k++]=pop();
        }

postfix[k]='\0';
}
int main(){
    char postfix[MAX],infix[MAX];
    printf("enetr infix expression:\n");
    scanf("%s",infix);
    infixtopostfix(infix,postfix);
    printf("postfix is %s",postfix);
    return 0;

}