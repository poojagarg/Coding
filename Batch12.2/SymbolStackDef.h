//BATCH 12
//TEAM MEMBERS-NIKITA BHALLA-2011A7PS122P
//POOJA GARG-2011A7PS056P
#ifndef SYMBOLTABLEDEF_H
#define SYMBOLTABLEDEF_H 
	#include"SymbolTableDef.h"
#endif
typedef struct SymbolStackNode{SymbolTable* value; struct SymbolStackNode* next;}SymbolStackNode;
typedef struct SymbolStack{int count; SymbolStackNode* top;}SymbolStack;

