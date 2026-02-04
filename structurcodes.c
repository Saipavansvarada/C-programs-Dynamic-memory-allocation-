#include<stdio.h>
#include<string.h>
struct day
{
    char name[10];
    int date;
    char activity[30];
};

void create (struct day planner[],int size){
    for(int i=0;i<size;i++){
        strcpy(planner[i].name,"");
        planner[i].date=0;
        strcpy(planner[i].activity,"");
    }
}

void read (struct day planner[],int size){
    for (int i =0;i<size;i++){
        printf("Day %d: \n",i+1);
        printf("enter details: name, date,activity\n");
        scanf("%s%d%s",&planner[i].name,&planner[i].date,&planner[i].activity);
    }
}

void display(struct day planner[],int size){
    printf("====Weekly planner====\n");
    printf("%-10s%-6s%-30s\n","day","date","activity");
    printf("---------------------------------\n");
    for (int i=0;i<size;i++){
        printf("%-10s%-6d%-30s\n",planner[i].name,planner[i].date,planner[i].activity);
    }
}

int main(){
    int sz=3;
    struct day planner[sz];
    create(planner,sz);
    read(planner,sz);
    display(planner,sz);
    
}