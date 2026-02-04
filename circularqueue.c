#include<stdio.h>
#include<stdlib.h>
int N;
int *queue;
int front=-1;
int rear=-1;
int count=0;

void enqueue(int x){
    if(rear==-1&&front==-1){
        front=rear=0;
        queue[rear]=x;
        printf("New call enqued %d\n",x);
        count++;
    }else if((rear+1)%N==front){
        printf("Queue full...over flow\n");
    }else{
        rear=(rear+1)%N;
        queue[rear]=x;
        printf("new call enqued %d\n",x);
        count++;
        }
    }

void dequeue(){
    if(front==-1&&rear==-1){
        printf("under flow\n");
     }else if(front==rear){
        printf("call dequed %d\n",queue[front]);
        front=rear=-1;
        count--;
     }else{
        printf("call dequed %d\n",queue[front]);
        front=(front+1)%N;
        count--;
     }
}

void display(){
    printf("the calls are :\n");
    int i =front;
    while(i!=rear){
        printf("%d\n",queue[i]);
        i=(i+1)%N;
    }printf("%d\n",queue[i]);
}

int main(){
    int id;
    printf("enter the size of queue\n");
    scanf("%d",&N);
    
    queue=(int *)malloc(N*sizeof(int));
    if(queue==NULL){
        printf("allocation failed\n");
        return 1;
    }
    int choice;
    while(1){
        printf("==call center queue syatem==\n");
        printf("1.new call enqueue\n2.remove call dequeue\n3.display\n4.exit\n");
        printf("enter choice : ");
        scanf("%d",&choice);
        switch(choice){
            case 1: printf("enter call id :");
                    scanf("%d",&id);
                    enqueue(id);
                    break;
            case 2: dequeue();
                    break;
            case 3: display();
                    break;
            case 4: exit(0);
            default:printf("invalid choice\n");
                    break;
        }

    }
}