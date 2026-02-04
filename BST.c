#include<stdio.h>
#include<stdlib.h>
struct node{
    struct node *right,*left;
    int isbn;
    char title[50];
};

struct node *create(int isbn){
    struct node *nn=(struct node*)malloc(sizeof(struct node));
    nn->left=nn->right=NULL;
    printf("Enter book tilte:\n");
    scanf("%s",nn->title);
    nn->isbn=isbn;
    return nn; 
}

struct node *insert(struct node *root,int isbn){
    if(root==NULL)
        return create(isbn);
    else if (isbn<root->isbn)
        root->left=insert(root->left,isbn);
    else if(isbn>root->isbn)
        root->right=insert(root->right,isbn);

    return root;
}
 void inorder(struct node* root){
    if(root==NULL){
        return;
    }else{
    inorder(root->left);
    printf("%d %s\n",root->isbn,root->title);
    inorder(root->right);
    }
 }
void preorder(struct node* root){
    if(root==NULL){
        return;
    }else{
    printf("%d %s\n",root->isbn,root->title);
    preorder(root->left);
    preorder(root->right);
    }
 }
 void postorder(struct node* root){
    if(root==NULL){
        return;

    }else{
    postorder(root->left);
    postorder(root->right);
    printf("%d %s\n",root->isbn,root->title);
    }
 }
 void search(struct node *root ,int isbn){
    while(root!=NULL){
        if(root->isbn==isbn){
            printf("key found");
            return;
        }else if(isbn>root->isbn){
            root=root->right;
        }else{
            root=root->left;
        }
    }printf("key not found");
    return;
 }
 int main(){
    struct node *root=NULL;
    int choice,isbn;
    while(1){
        printf("enter\n");
        printf("1.insert\n2.pre\n3.post\n4.inorder\n5.search\n6.exit\n");
        scanf("%d",&choice);
        switch(choice){
            case 1: printf("enter isbn:");
                    scanf("%d",&isbn);
                    root= insert(root,isbn);
                    break;
            case 2: preorder(root);
                    break;
            case 3:postorder(root);
                    break;
            case 4:inorder(root);
                    break;
            case 5:printf("enter isbn to search:");
                    scanf("%d",&isbn);
                    search(root,isbn);
                    break;
            case 6:exit(0);
            default:printf("invalid choice");
            break;
                }   
     }
 }