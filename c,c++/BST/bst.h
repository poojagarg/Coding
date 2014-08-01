#ifndef BSTDEF_H_
	#define BSTDEF_H_
	#include"bstDef.h"
#endif
binarySearchNode* insertRec(binarySearchNode* tree, int e);
binarySearchNode* insertItr(binarySearchNode* tree, int e);
binarySearchNode* del(binarySearchNode* tree, int e);
binarySearchNode* findMax(binarySearchNode* tree);
binarySearchNode* delNode(binarySearchNode* n);
void displayBinaryTree(binarySearchNode* tree);
void displayInorderBinaryTree(binarySearchNode* tree);
void displayPreorderBinaryTree(binarySearchNode* tree);
void displayPostOrderBinaryTree(binarySearchNode* tree);
void rangePrinter(binarySearchNode* tree, int min, int max);
binarySearchNode* inorderSuccessor(binarySearchNode* tree, int key);
binarySearchNode* inorderPredecessor(binarySearchNode* tree, int key);
