#include<stdio.h>
#include<stdlib.h>
#define size 6
int stack[size];
int top=-1;

void push(int id){
    if(top==size-1){
        printf("Stack full:over flow condition\n");
    }else{
        printf("Pushed %d into stack\n ",id);
        stack[++top]=id;
    }
}
void pop(){
    if(top==-1){
        printf("Stack is empty, under flow\n");
    }
    else{
        printf("poped %d\n",stack[top]);
        top--;
    }
}
void display(){
    printf("elements are \n");
    for(int i=top;i>=0;i--){
        printf("%d\n",stack[i]);
    }
}
int main(){
    int choice,id;
    while(1){
    printf("----parcel storage system----\n");
    printf("1.to push \n 2.to pop\n 3.to display\n 4.to exit\n");
    printf("enter choice :");
    scanf("%d",&choice);
    switch(choice){
        case 1: printf("Enter parcel ID to add\n");
                scanf("%d",&id);
                push(id);
                break;
        case 2: pop();
                break;
        case 3: display();
                break;
        case 4:exit(0);
    }
}
return 0;
}