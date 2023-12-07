#include<stdio.h>
#include<stdlib.h>

struct node
{
    struct node *lchild;
    int data;
    struct node *rchild;
};

struct node *root = NULL;

void insert(struct node *root, int key)
{
    struct node *t = root;
    struct node *p, *r;

    if (root == NULL)
    {
        p = (struct node *)malloc(sizeof(struct node));
        p->data = key;
        p->lchild = p->rchild = NULL;
        root = p;
    }
    else
    {
        while (t != NULL)
        {
            r = t;
            if (key < t->data)
                t = t->lchild;
            else
                t = t->rchild;

        }
        p = (struct node *)malloc(sizeof(struct node));
        p->data = key;
        p->lchild = p->rchild = NULL;
        if (key < r->data)
            r->lchild = p;
        else
            r->rchild = p;
    }
    return;
}

void inorder(struct node *p)
{
    if (p != NULL)
    {
        inorder(p->lchild);
        printf("%d\n", p->data);
        inorder(p->rchild);
    }
   return;
}

int main()
{
    struct node* root = NULL;
    insert(root, 10);
    insert(root, 5);
    insert(root, 20);
    insert(root, 8);
    insert(root, 30);

    printf("The inorder traversal is \n");
    inorder(root);
    return 0;
}