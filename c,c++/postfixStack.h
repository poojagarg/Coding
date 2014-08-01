#ifndef _LINKEDLISTSTACKDEF_H
	#include"linkedlistStackDef.h"
#endif
linkedlistStack* create();
void push(int value,linkedlistStack* s);
int pop(linkedlistStack* s);
int isEmptyStack(linkedlistStack* s);
void deleteStack(linkedlistStack* s);
