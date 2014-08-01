#ifndef AVLDEF_H_
	#define AVLDEF_H_
	#include"AVLDef.h"
#endif
AVLNode* singleRotateLeft(AVLNode* root);
AVLNode* singleRotateRight(AVLNode* root);
AVLNode* DoubleRotateLeft(AVLNode* root);
AVLNode* DoubleRotateRight(AVLNode* root);
int max(int a, int b);
AVLNode* insert(AVLNode* root, int data);
void displayAVLTree(AVLNode* tree);
