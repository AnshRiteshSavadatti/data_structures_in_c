// avl trees implementation 

#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* right;
    struct node* left;
    int height;
};
typedef struct node* Node;

Node create(int data){
    Node newnode = (Node)malloc(sizeof(struct node));
    newnode->data = data;
    int height = 0;
    newnode->left = newnode->right = NULL;
    return newnode;
}

int height(Node head){
    if(head == NULL){
        return -1;
    }
    return head->height;
}

Node rightRotate(Node x){
    Node y = x->left;
    Node z = y->right;

    y->right = x;
    x->left = z;

    y->height = (height(y->left) > height(y->right) ? height(y->left) : height(y->right)) + 1;
    x->height = (height(x->left) > height(x->right) ? height(x->left) : height(x->right)) + 1;
    return y;
}

Node leftRotate(Node x){
    Node y = x->right;
    Node z = y->left;

    y->left = x;
    x->right = z;

    y->height = (height(y->left) > height(y->right) ? height(y->left) : height(y->right)) + 1;
    x->height = (height(x->left) > height(x->right) ? height(x->left) : height(x->right)) + 1;
    return y;
}

Node rotate(Node node) {
  if (height(node->left) - height(node->right) > 1) {
    // left heavy
    if (height(node->left->left) - height(node->left->right) > 0) {
      // left left case
      return rightRotate(node);
    }
    if (height(node->left->left) - height(node->left->right) < 0) {
      // left right case
      node->left = leftRotate(node->left);
      return rightRotate(node);
    }
  }

  if (height(node->left) - height(node->right) < -1) {
    // right heavy
    if (height(node->right->left) - height(node->right->right) < 0) {
      // right right case
      return leftRotate(node);
    }
    if (height(node->right->left) - height(node->right->right) > 0) {
      // left right case
      node->right = rightRotate(node->right);
      return leftRotate(node);
    }
  }

  return node;
}

Node insert(int data, Node head){
    Node newnode = create(data);
    if(head == NULL){
        return newnode;
    }
    if(data < head->data){
        head->left = insert(data, head->left);
    }else{
        head->right = insert(data, head->right);
    }
    return rotate(head);
}

void inorder(Node head){
    if(head != NULL){
    inorder(head->left);
    printf("%d ", head->data);
    inorder(head->right);
    }
    return;
}

int main(){
    int n;
    printf("Enter the number of nodes\n");
    scanf("%d",&n);
    Node head = NULL;
    for(int i =0; i<n; i++){
        int x;
        scanf("%d",&x);
        head = insert(x, head);
    }
    inorder(head);
    return 0;
}