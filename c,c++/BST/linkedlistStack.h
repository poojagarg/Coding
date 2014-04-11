#ifndef _LINKEDLISTSTACKDEF_H
	#include"linkedlistStackDef.h"
#endif
#ifndef BSTDEF_H_
	#define BSTDEF_H_
	#include"bstDef.h"
#endif
linkedlistStack* create();
void push(binarySearchNode* value,linkedlistStack* s);
binarySearchNode* pop(linkedlistStack* s);
int isEmptyStack(linkedlistStack* s);
void deleteStack(linkedlistStack* s);
void display(node* n);
node* findMiddle(node* s);
