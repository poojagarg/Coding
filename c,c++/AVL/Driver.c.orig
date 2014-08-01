#ifndef STDIO_H_
	#define STDIO_H_
	#include<stdio.h>
#endif

#ifndef AVL_H_
	#define AVL_H_
	#include"AVL.h"
#endif
int main(){
	AVLNode* tree=NULL;
	int i=0;
	FILE* fp=fopen("insertAVL.txt","r");
	if(!fp) return;
	while(!feof(fp)){
		fscanf(fp,"%d",&i);
		tree=insert(tree,i);
	}
	displayAVLTree(tree);
}
