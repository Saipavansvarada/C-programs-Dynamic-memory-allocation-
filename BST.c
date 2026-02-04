/*Binary Search tree sing functions(create(),insert(),search(),
            inorder(),preorder(),postorder())*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node{
    int data;
    char title[50];
    struct node*left,*right;
}*root=NULL;

struct node *create(int val,char t[]){
    struct node*newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    strcpy(newnode->title,t);
    newnode->title[49] = '\0';
    newnode->data=val;
    newnode->left=newnode->right=NULL;
    return newnode;
}
struct node *insert(struct node *root,int val,char t[]){
if (root==NULL){
   return create(val,t);
}
if(val<root->data){
    root->left=insert(root->left,val,t);
}
else if(val>root->data){
    root->right=insert(root->right,val,t);
}
return root;
}

struct node *search(struct node*root,int key){
    if(root==NULL||root->data==key){
        return root;
    }
    if(key<root->data){
        return search(root->left,key);
    }
    else if (key>root->data){
        return search(root->right,key); 
       }
}
void inorder(struct node*root){
    if(root==NULL){
        return;
    }else{
    inorder(root->left);
    printf("%d",root->data);
    inorder(root->right);
}
}
void postorder(struct node*root){
    if(root==NULL){
        return;
    }else{
    postorder(root->left);
    postorder(root->right);
    printf("%d",root->data);
}
}
void preorder(struct node*root){
    if(root==NULL){
        return;
    }else{
    printf("%d",root->data);    
    preorder(root->left);
    preorder(root->right);
    
}
}
// Utility for memory cleanup
void freeBST(struct node *node) {
    if (node != NULL) {
        freeBST(node->left);
        freeBST(node->right);
        free(node);
    }
}

int main(){
    int choice;
    char title_input[50]; // Renamed 'a' to 'title_input' for clarity
    int val_input;
    int key_input;
    struct node *result_node;

    printf("--- Library Book Database (BST) ---\n");

    while(1) {
        printf("\n\nSelect an operation:\n");
        printf("1. Insert a book (ID/Key and Title)\n");
        printf("2. Search for a book by ID/Key\n");
        printf("3. Traverse (Inorder)\n");
        printf("4. Traverse (Preorder)\n");
        printf("5. Traverse (Postorder)\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
       scanf("%d",&choice);
        

        switch (choice) {
            case 1: 
                printf("Enter Book ID/Key (integer): ");
                scanf("%d", &val_input);
                
                printf("Enter the book title: ");
                scanf("%s",title_input);
                
                root = insert(root, val_input, title_input); 
                printf("Book ID %d inserted successfully.\n", val_input);
                break;

            case 2: 
                printf("Enter Book ID/Key to search: ");
                scanf("%d", &key_input);
                result_node = search(root, key_input);
                    if (result_node != NULL) {
                        printf("\n--- Book Found ---\n");
                        printf("ID: %d\nTitle: %s\n", result_node->data, result_node->title);
                        printf("------------------\n");
                    } else {
                        printf("Book with ID %d NOT found.\n", key_input);
                    }
                break;

            case 3: 
                printf("\n--- Inorder Traversal (Sorted by ID) ---\n");
                if (root == NULL) {
                    printf("BST is empty.\n");
                } else {
                    inorder(root);
                }
                printf("\n");
                break;

            case 4: 
                printf("\n--- Preorder Traversal ---\n");
                if (root == NULL) {
                    printf("BST is empty.\n");
                } else {
                    preorder(root);
                }
                printf("\n");
                break;

            case 5:
                printf("\n--- Postorder Traversal ---\n");
                if (root == NULL) {
                    printf("BST is empty.\n");
                } else {
                    postorder(root);
                }
                printf("\n");
                break;

            case 6: // Exit
                printf("Exiting program. Clearing memory...\n");
                freeBST(root);
                break;

            default:
                printf("Invalid choice. Please select a number between 1 and 6.\n");
        }
    } 
return 0;
}
