//BATCH 12
//TEAM MEMBERS-NIKITA BHALLA-2011A7PS122P
//POOJA GARG-2011A7PS056P
#ifndef LEXERDEF_H
#define LEXERDEF_H
	#include"lexerDef.h"
#endif
typedef struct ASTnode{
	int label;
	token t;	
	struct ASTnode** array;
	int arraySize;
	}ASTnode;
