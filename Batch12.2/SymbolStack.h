//BATCH 12
//TEAM MEMBERS-NIKITA BHALLA-2011A7PS122P
//POOJA GARG-2011A7PS056P
#ifndef SYMBOLSTACKDEF_H
	#define SYMBOLSTACKDEF_H
	#include"SymbolStackDef.h"
#endif
SymbolStack* createSymbolStack();
void pushSymbolStack(SymbolTable* value,SymbolStack* s);
SymbolTable* popSymbolStack(SymbolStack* s);
int isEmptySymbolStack(SymbolStack* s);
void deleteSymbolStack(SymbolStack* s);
SymbolTable* topSymbolStack(SymbolStack* s);
