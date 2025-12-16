/*Doubly linklist using Dynamic memory allocation and using some functions 
create,dispaly,insert node from front and end,delete form front and end*/

#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    char usn[20];
    char name[50];
    struct node *next;
    struct node*prev;
    }*head;

void create(){
    struct node *newnode,*temp;
    int choice;
    printf("enter the number of students :\n");
    scanf("%d",&choice);
    for(int i=1;i<=choice;i++){
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("enetr the name of student:");
    scanf("%s",&newnode->name);
    printf("enetr the usn of student:");
    scanf("%s",&newnode->usn);
    printf("enetr data:\n");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    if(head==NULL){
        head=temp=newnode;
        }
    else{
        newnode->prev=temp;
        temp->next=newnode;
        temp=newnode;
        }
    }
}
void display(){
    struct node* temp=head;
    int cut=0;
    printf("first to last\n");
    while(temp->next!=NULL){
        printf("name of student:%s\n",temp->name);
        printf("usn of student: %s\n",temp->usn);
        printf("%d\n",temp->data);

        temp=temp->next;

        cut++;
    }
    printf("name of student:%s\n",temp->name);
        printf("usn of student: %s\n",temp->usn);
        printf("%d\n",temp->data);

    printf("count=%d\n",cut);
}
void insertfront(){
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("enetr the name of student:");
    scanf("%s",&newnode->name);
    printf("enetr the usn of student:");
    scanf("%s",&newnode->usn);
    printf("enetr data:\n");
    scanf("%d",&newnode->data);
    head->prev=newnode;
    newnode->next=head;
    head=newnode;
}
void insertend(){
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("enetr the name of student:");
    scanf("%s",&newnode->name);
    printf("enetr the usn of student:");
    scanf("%s",&newnode->usn);
    printf("enetr data:\n");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    struct node*temp=head;
    while(temp->next!=NULL){
        temp=temp->next;}
    temp->next=newnode;
    newnode->prev=temp;
}
void deletefront(){
    struct node *temp=head;
    head=head->next;
    free(temp);
}
void deleteend(){
    struct node*temp,*pre;
    temp=pre=head;
    while(temp->next!=NULL){
        pre=temp;
        temp=temp->next;}
        pre->next=NULL;
        free(temp);

}
void main(){
    int ch;
    for(;;){
    printf("1.create\n2.display\n3.insert end\n4.inser front\n5.delete end\n6.delete front\n");
    scanf("%d",&ch);
    switch (ch)
    {
    case 1:create();
        break;
    case 2:display();
        break;
    case 3:insertend();
        break;
    case 4:insertfront();
        break;
    case 5 :deleteend();
        break;
    case 6:deletefront();
        break;
    case 7: return 0;

    default:printf("invalide choice.");
        break;
    }}
}