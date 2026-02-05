#include<stdio.h>
#define MAX 20
int ht[MAX],m;

void linerprobing(int key){
    int index=key%m;
    int i=index;
    while(ht[i]!=-1){
        i=(i+1)%m;
    if(i==index){
        printf("hastable is full\n");
        return;
    }
    }ht[i]=key;
}
void quadraticprobling(int key){
    int index=key%m;
    int i,h;
    for(i=0;i<m;i++){
        h=(index+i*i)%m;
        if(ht[h]==-1){
            ht[h]=key;
            return;
        }
    }printf("table full\n");
}
void display(){
    printf("hash table:\n");
    for(int i=0;i<m;i++){
        printf("index %d:%d\n",i,ht[i]);
    }
}
int main(){
    int n,key,choice;
    printf("enter hashtable size:\n");
    scanf("%d",&m);
    printf("no fo vehicals\n");
    scanf("%d",&n);
    for(int i=0 ;i<=m;i++){
        ht[i]=-1;
    }
    printf("liner or quadratic:\n");
    scanf("%d",&choice);
    printf("enter registration numbers:\n");
    for(int i=0;i<=n;i++){
        scanf("%d",&key);
        if(choice==1){
            linerprobing(key);
        }else{
            quadraticprobling(key);
        }
    }
    display();
    return 0;
}