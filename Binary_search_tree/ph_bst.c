#include<stdio.h>
#include<stdlib.h>
unsigned static int N = 0;

struct tree
{
	int data;
	struct tree *left;
	struct tree *right;
};
typedef struct tree TREE;

TREE * insert_into_bst(TREE *, int);
void inorder(TREE *);
void preorder(TREE *);
void postorder(TREE *);
TREE * delete_from_bst(TREE *, int);


/*
Function Name: insert_into_bst
Input Params:  Root of the tree and data item to be inserted
Return Type:   Updated root of the tree
Description:   Inserts a node into a binary search tree at
               appropriate position
*/

TREE * insert_into_bst(TREE * root, int data)
{
	TREE *newnode,*currnode,*parent;

	// Dynamically allocate the memory using malloc
	newnode=(TREE*)malloc(sizeof(TREE));

	// Check if the memory allocation was successful
	if(newnode==NULL)
	{
        printf("Memory allocation failed\n");
        return root;
	}

	// Initialize the tree node elements
	newnode->data = data;
	newnode->left = NULL;
	newnode->right = NULL;

	// When the first insertion happens which is the root node
	if(root == NULL)
	{
		root = newnode;
		printf("Root node inserted into tree\n");
		return root;
	}

	// Traverse through the desired part of the tree using
	// currnode and parent pointers
	currnode = root;
	parent = NULL;
	while(currnode != NULL)
	{
		parent = currnode;
		if(newnode->data < currnode->data)
			currnode = currnode->left;
		else
			currnode = currnode->right;
	}

    // Attach the node at appropriate place using parent
	if(newnode->data < parent->data)
		parent->left = newnode;
	else
		parent->right = newnode;

    // print the successful insertion and return root
    printf("Node inserted successfully into the tree\n");
    return root;
}

/*
Function Name: inorder
Input Params:  Root of the tree
Return Type:   void
Description:   Recursively visits the tree in the order of
               Left, Root, Right
*/
void inorder(TREE *troot)
{
	if(troot != NULL)
    	{
        	inorder(troot->left);
        	printf("%d\t",troot->data);
        	inorder(troot->right);
	}
}

/*
Function Name: preorder
Input Params:  Root of the tree
Return Type:   void
Description:   Recursively visits the tree in the order of
                Root, Left, Right
*/

void preorder(TREE *troot)
{
	if(troot != NULL)
	{
        	printf("%d\t",troot->data);
        	preorder(troot->left);
        	preorder(troot->right);
	}
}


/*
Function Name: postorder
Input Params:  Root of the tree
Return Type:   void
Description:   Recursively visits the tree in the order of
               Left, Right, Root
*/
void postorder(TREE *troot)
{
	if(troot != NULL)
	{
        	postorder(troot->left);
        	postorder(troot->right);
        	printf("%d\t",troot->data);
	}
}


/*
Function Name: delete_from_bst
Input Params:  Root of the tree, item data to be deleted
Return Type:   Updated root of the tree
Description:   Deletes the specified data and re-adjusts the
               tree structure according to bst tree constraints
*/

TREE * delete_from_bst(TREE * root, int data)
{
    TREE * currnode, *parent, *successor, *p;

    // Check if the tree is empty
    if(root == NULL)
    {
        printf("Tree is empty\n");
        return root;
    }

    // Traverse and reach the appropriate part of the tree
    parent = NULL;
    currnode = root;
    while (currnode != NULL && data != currnode->data)
    {
        parent = currnode;
        if(data < currnode->data)
            currnode  = currnode->left;
        else
            currnode = currnode->right;
    }

    // If the data is not present in the tree
    if(currnode == NULL)  {
        printf("Item not found\n");
        return root;
    }

    // Check and manipulate if either left subtree is absent,
    // or right subtree is absent
    // or both are present
    if(currnode->left == NULL)
        p = currnode->right;
    else if (currnode->right == NULL)
        p = currnode->left;
    else
    {
	 // Process of finding the inorder successor
        successor = currnode->right;
        while(successor->left != NULL)
            successor = successor->left;

        successor->left = currnode->left;
        p = currnode->right;
    }

    // The case of root deletion
    if (parent == NULL) {
        free(currnode);
        return p;
    }

    if(currnode == parent ->left)
        parent->left = p;
    else
        parent->right = p;

    free(currnode);
    return root;
}

void degree_of_root_node(TREE* head){
    int cnt = 0;
    if(head->left != NULL )
        cnt++;
    if(head->right != NULL)
        cnt++;
    printf("The degree of the root node is %d \n",cnt);
    return;
}

// deleting the values of node less than n;

// TREE* delete_tree(TREE* node){
//     if(node ->right == NULL && node->left == NULL){
//         return node;
//     }  
//     node->left = delete_tree(node->left);
//     node->right = delete_tree(node->right);
//     free(node);
//     return NULL;
// }

// TREE* delete_less_than(TREE* head, int data){

//    TREE* curr = head;
//    while(curr->data != data && curr != NULL){
//         if(curr->data < data)
//             curr= curr->right;
//         else
//             curr = curr->left;
//    }
//    if(curr == NULL){
//         printf("Key not found \n");
//         return head;
//    }
//    curr = delete_tree(curr->left);
//    return head;
// }

TREE* delete_tree(TREE* node) {
    if (node == NULL) {
        return NULL;
    }

    // First, delete the left and right subtrees
    node->left = delete_tree(node->left);
    node->right = delete_tree(node->right);

    // Then, free the current node
    free(node);
    return NULL;  // Return NULL to indicate the node has been deleted
}

TREE* delete_less_than(TREE* head, int data) {
   TREE* curr = head;
   TREE* prev = NULL;

   while (curr != NULL) {
        if (curr->data < data) {
            // Delete the entire subtree rooted at 'curr'
            curr = delete_tree(curr);

            if (prev == NULL) {
                head = curr;
            } else if (prev->left == curr) {
                prev->left = NULL;
            } else {
                prev->right = NULL;
            }
        } else {
            prev = curr;
            curr = curr->right;
        }
   }

   return head;
}

// TREE* pos(TREE* head, int n){
//     TREE* curr = head;
    
//     while(curr != NULL && curr->data != n){
//         if(n < curr->data)
//             curr = curr->right;
//         else
//             curr = curr->left;
//     }
//     if(curr == NULL){
//         printf("Element not found\n");
//         return head;
//     }
//     return curr;
// }

TREE* pos(TREE* root, int value) {
    if (root == NULL || root->data == value) {
        return root;
    }

    if (value < root->data) {
        return pos(root->left, value);
    } else {
        return pos(root->right, value);
    }
}

TREE* cnt(TREE* head, int *c){
    if(head == NULL)
        return NULL;
    head->left = cnt(head->left, c);
    *c++;
    head->right = cnt(head->right,c);
}

int main()
{
	TREE * root;
    TREE * temp = root;
	root = NULL;
	int choice = 0;
	int data = 0;
	int count = 0;

	while(1)
	{
        printf("\n******** Menu *************\n");
        printf("1-Insert into BST\n");
        printf("2-Inorder Traversal\n");
        printf("3-Preorder Traversal\n");
        printf("4-Postorder Traversal\n");
        printf("5-Delete from BST\n");
        printf("6-print the out degree of root node\n");
        printf("7-print the out degree of root node\n");
        printf("8-print the degree of the binart search tree\n");
        printf("9-to count and print the number of nodes in tree\n");
        printf("10-to delete all the nodes less than n\n");
        printf("11-Count the number of nodes having a value greater than the given value K\n");
        printf("12-Find the minimum valued item from the tree\n");
        printf("13-Print the address of the root node\n");
        printf("Any other option to exit\n");
        printf("*****************************\n");

        printf("Enter your choice\n");
        scanf("%d", &choice);
        temp = root;

	 switch(choice)
	 {
            case 1: printf("Enter the item to insert\n");
                    scanf("%d", &data);
                    root = insert_into_bst(root, data);
                    N++;
                    break;

            case 2: if(root == NULL)
                        printf("Tree is empty\n");
                    else
                    {
                        printf("Inorder Traversal is...\n");
                        inorder(root);
                    }
                    break;

            case 3: if(root == NULL)
                        printf("Tree is empty\n");
                    else
                    {
                        printf("Preorder Traversal is...\n");
                        preorder(root);
                    }
                    break;

            case 4: if(root == NULL)
                        printf("Tree is empty\n");
                    else
                    {
                        printf("Postorder Traversal is...\n");
                        postorder(root);
                    }
                    break;

            case 5: printf("Enter the item to be deleted\n");
                    scanf("%d", &data);
                    root = delete_from_bst(root, data);
                    break;

            case 6 : degree_of_root_node(root);
                    break;

            case 7: printf("The out degree node is %d",0);
                    break;

            case 8 : printf("The number of edges of the tree is %d\n",N-1);
                    break;

            case 9: printf("The number of nodes in the tree is %d\n",N);
                    inorder(root);
                    break;

            case 10: printf("Enter the item lesser than which everything must be deleted\n");
                     scanf("%d",&data);
                    root = delete_less_than(root, data);
                    break;

            case 11: printf("Enter the number \n");
                    scanf("%d",&data);
                    temp = pos(root, data);
                    cnt(temp->left, &count);
                    printf("The number of elements lesser than %d are %d\n",data,count);
                    break;
            case 12: 
                    while(temp->right != NULL){
                        temp = temp->right;
                    }
                    printf("The maximum values is %d\n",temp->data);
                    break;
            case 13:
                    printf("The address of root node is %p\n",root);
                    break;

            default: printf("Exciting Code.\n");
                     exit(0);
        }
    }
    return 0;
}