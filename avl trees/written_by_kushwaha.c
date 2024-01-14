#include <stdio.h>
#include <stdlib.h>

struct Node {
  int value;
  struct Node* left;
  struct Node* right;
  int height;
};

struct AVL {
  struct Node* root;
};

struct Node* createNode(int value) {
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
  if (newNode == NULL) {
    printf("Memory allocation failed!\n");
    exit(EXIT_FAILURE);
  }

  newNode->value = value;
  newNode->left = newNode->right = NULL;
  newNode->height = 0;

  return newNode;
}

int height(struct Node* node) {
  if (node == NULL) {
    return -1;
  }
  return node->height;
}

struct Node* rightRotate(struct Node* p) {
  struct Node* c = p->left;
  struct Node* t = c->right;

  c->right = p;
  p->left = t;

  p->height = (height(p->left) > height(p->right) ? height(p->left) : height(p->right)) + 1;
  c->height = (height(c->left) > height(c->right) ? height(c->left) : height(c->right)) + 1;

  return c;
}

struct Node* leftRotate(struct Node* c) {
  struct Node* p = c->right;
  struct Node* t = p->left;

  p->left = c;
  c->right = t;

  p->height = (height(p->left) > height(p->right) ? height(p->left) : height(p->right)) + 1;
  c->height = (height(c->left) > height(c->right) ? height(c->left) : height(c->right)) + 1;

  return p;
}

struct Node* rotate(struct Node* node) {
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

struct Node* insert(struct Node* node, int value) {
  if (node == NULL) {
    return createNode(value);
  }

  if (value < node->value) {
    node->left = insert(node->left, value);
  }

  if (value > node->value) {
    node->right = insert(node->right, value);
  }

  node->height = (height(node->left) > height(node->right) ? height(node->left) : height(node->right)) + 1;
  return rotate(node);
}

void populate(struct AVL* tree, int nums[], int length) {
  for (int i = 0; i < length; i++) {
    tree->root = insert(tree->root, nums[i]);
  }
}

void display(struct Node* node, const char* details) {
  if (node == NULL) {
    return;
  }
  printf("%s%d\n", details, node->value);
  display(node->left, "Left child of ");
  display(node->right, "Right child of ");
}

int main() {
  struct AVL avlTree;
  avlTree.root = NULL;

  int nums[] = {3, 1, 5, 2, 4, 6};
  int length = sizeof(nums) / sizeof(nums[0]);

  populate(&avlTree, nums, length);

  display(avlTree.root, "Root Node: ");

  return 0;
}
