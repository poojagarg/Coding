//BATCH 12
//TEAM MEMBERS-NIKITA BHALLA-2011A7PS122P
//POOJA GARG-2011A7PS056P
#define ParameterSize 10
typedef union value{
	char stringValue[20];
	int matrixValue[10][10];
	}value;
typedef struct typeID{
	int type; 
	int offset; 
	int initialized;
	int length[2];//if matrix size[0]*size[1], of string the size=size[0], type is confirmed using type field
	value val;
	}typeID;
typedef struct typeFunctionID{
	int input[ParameterSize];
	int inputSize;
	int output[ParameterSize];
	int outputSize;
}typeFunctionID;
typedef union typeNodeUnion{
	typeID id; 
	typeFunctionID fid;
	}typeNodeUnion;
typedef struct SymbolTableEntryNode{
	char lexeme[256]; //lexeme- key(unique but since a hashtable, different lexemes may give same key), token- value
	int i;//i=0 fid, i=1 id
	typeNodeUnion type;
	struct SymbolTableEntryNode* next;
}SymbolTableEntryNode;
typedef struct SymbolTableEntry{
	int count; //count of no. of nodes for 1 key
	struct SymbolTableEntryNode* next;
}SymbolTableEntry;
typedef struct SymbolTable{
	int count; //no of different lexemes in the hash table
	int size; // actual size of hash table
	char symbolTableName[256];
	SymbolTableEntry* table;
	int offset;
	int outputParameter;
	char outputParameterLexeme[100][100];
	SymbolTableEntry* parentTable;
}SymbolTable;






