#ifndef STDIO_H_
	#define STDIO_H_
	#include<stdio.h>
#endif
#ifndef BST_H_
	#define BST_H_
	#include"bst.h"
#endif

int main(){
	binarySearchNode* tree=NULL;
	int i=0;
	FILE* fp=fopen("insertBST.txt","r");
	if(!fp) return;
	while(!feof(fp)){
		fscanf(fp,"%d",&i);
		tree=insertItr(tree,i);
	}

	/*for(i=-1;i<40; i++){
		int t;
		binarySearchNode* b=inorderSuccessor(tree, i);
		if(b==NULL) t=-1;
		else{t=b->data;}
		printf("i:%d, key:%d\n",i,t);
			}//end of for
*/
	BSTtoLinkedListStack(tree);
	
	//rangePrinter(tree,3,11); 
	close(fp);
	/*fp=fopen("deleteBST.txt","r");
	if(!fp) return;
	while(!feof(fp)){
		fscanf(fp,"%d",&i);
		tree=del(tree,i);
		displayBinaryTree(tree);
		scanf("%d",&i);
	}
	close(fp);*/
}
