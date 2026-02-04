#include<stdio.h>
#include<stdlib.h>
struct node{
    char name[10];
    int usn;
    char program[25];
    int sem;
    double phone;
    struct node *next;
}*head=NULL,*temp=NULL;

struct node* create(){
    struct node *nn;
    nn=(struct node*)malloc(sizeof(struct node));
    printf("Enter details:\n");
    scanf("%s%d%s%d%lf",&nn->name,&nn->usn,&nn->program,&nn->sem,&nn->phone);
    nn->next=NULL;
    return nn;
}
void insertend(){
    struct node *nn=create();
    if(head==NULL)
        head=temp=nn;
    else {
        printf("inserted at end\n");
        temp->next=nn;
        temp=nn;
    }
}
void inseratfront(){
    struct node *nn =create();
    if(head==NULL)
        head=nn;
    else{
        nn->next=head;
        head=nn;
    }
}
void deletend(){
    struct node *prenode=head,*emp=head->next;
    if(head==NULL){
        printf("no elements\n");
    }else{
    while(emp!=NULL){
        prenode=emp;
        emp=emp->next;
    }
    prenode->next=NULL;
}}
void deletefront(){
    if(head==NULL){
        printf("no elements\n");
    }else{
        head=head->next;
    }
}
void display(){
    struct node *t=head;
    if(head==NULL){
        printf("no records found\n");
    }else{
        printf("===student records===\n");
        printf("--------------------------------------------------\n");
        while(t!=NULL){
            printf("name:%s|USN: %d|program: %s|SEM: %d|Phone number: %lf\n",t->name,t->usn,t->program,t->sem,t->phone);
            t=t->next;
        } 
}
}
int main(){
    int choice;
    while(1){
        printf("---records---\n");
        printf("1.insertend\n2.insertfront\n3.deleteend\n4.deletefront\n5.display\n6.exit\n");
        printf("enetr choice :");
        scanf("%d",&choice);
        switch(choice){
            case 1: insertend();
                    break;
            case 2: inseratfront();
                    break;
            case 3: deletend();
                    break;
            case 4: deletefront();
                    break;
            case 5 :display();
                    break;
            case 6:exit(0);
            default:printf("invalid choice");
                    break;
        }
    }
    return 0;
}