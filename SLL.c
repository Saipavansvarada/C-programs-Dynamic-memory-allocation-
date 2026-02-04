/*Singly linklist(SLL) using Dynamic memory allocation and using some functions 
create,dispaly,insert node from front and end,delete form front and end*/



#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    char usn[20];
    char name[50];
    struct node *next;
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
        temp->next=newnode;
        temp=newnode;
        }
    }
}
void display(){
    struct node* temp=head;
    int cut=0;
    while(temp!=NULL){
        printf("name of student:%s\n",temp->name);
        printf("usn of student: %s\n",temp->usn);
        printf("%d\n",temp->data);

        temp=temp->next;

        cut++;
    }
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
        free(temp);

}
void main(){
    create();
    display();
    insertend();
    insertfront();
    display();
    deleteend();
    display();
    deletefront();
    display();
}