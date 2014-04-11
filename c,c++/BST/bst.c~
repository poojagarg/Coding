#ifndef STDIO_H_
	#define STDIO_H_
	#include<stdio.h>
#endif
#ifndef BSTDEF_H_
	#define BSTDEF_H_
	#include"bstDef.h"
#endif
#ifndef LINKEDLISTSTACKDEF_H_
	#define LINKEDLISTSTACKDEF_H_
	#include"linkedlistStackDef.h"
#endif
void debug(){int i;	scanf("%d",&i);}
binarySearchNode* insertRec(binarySearchNode* tree, int e);
binarySearchNode* insertItr(binarySearchNode* tree, int e);
binarySearchNode* del(binarySearchNode* tree, int e);
binarySearchNode* findMax(binarySearchNode* tree);
binarySearchNode* delNode(binarySearchNode* n);
void displayBinaryTree(binarySearchNode* tree);
void displayInorderBinaryTree(binarySearchNode* tree);
void displayPreorderBinaryTree(binarySearchNode* tree);
void displayPostOrderBinaryTree(binarySearchNode* tree);
int global=0;
binarySearchNode* linkedListToBST(node* s){
	node* n=findMiddle(s);	
	if(n==NULL) {printf("returning NULL"); return NULL;} //no elements
	if(n->next==NULL){printf("returning  n->value->data:%d\n", n->value->data); n->value->left=n->value->right=NULL; return n->value;}	//single element
	binarySearchNode* root=n->next->value;
	node* q=n->next->next;
	n->next=NULL;
	if(s==NULL)
		root->left=NULL;
	else
		root->left=linkedListToBST(s);
	if(q==NULL)
		root->right=NULL;
	else
		root->right=linkedListToBST(q);
	printf("returning %d\n", root->data);
	return root;
}
binarySearchNode* insertRec(binarySearchNode* tree, int e){
	if(tree==NULL){ 	
	binarySearchNode* n=(binarySearchNode*)malloc(sizeof(binarySearchNode));
	n->data=e;
	n->left=n->right=NULL;
	return n;
	}	
	else 
		if(tree->data>e){
			tree->left=insertRec(tree->left,e);
		}
		else{
			tree->right=insertRec(tree->right,e);
		}
	return tree;
}
binarySearchNode* insertItr(binarySearchNode* tree, int e){
	binarySearchNode* n=(binarySearchNode*)malloc(sizeof(binarySearchNode));
	n->data=e;
	n->left=n->right=NULL;	
	if(tree==NULL){ 	
		return n;
	}
	binarySearchNode* t=tree;	
	while(1){
		if(t->data>e){
			if(!t->left){ t->left=n; return tree;}
			else t=t->left;
			}
		else{
			if(!t->right){ t->right=n; return tree;}
			else t=t->right;
			}
}//end of while
}//end of func
binarySearchNode* del(binarySearchNode* tree, int e){
	if(tree->data==e){
		return delNode(tree);//that becomes the root node
	}
	binarySearchNode* t=tree;
	while(t){
		if(t->data<e){
			if(!t->right) {t=NULL; break;}
			if(t->right->data==e){
				t->right=delNode(t->right); break;}
			else t=t->right;
			}//end of if
		else{	if(!t->left) {t=NULL; break;}
			if(t->left->data==e){
				t->left=delNode(t->left); break;}
			else t=t->left;
			}//end of else
}//end of while
	if(t==NULL) printf("%d: not found\n",e);
	return tree;
}
binarySearchNode* findMax(binarySearchNode* tree){
	if(tree==NULL) return tree;
	binarySearchNode* t=tree;
	while(t->right) t=t->right;
	return t;
}
binarySearchNode* delNode(binarySearchNode* n){
	if(!n->left) {free(n); return n->right;}
	if(!n->right) {free(n); return n->left;}
	binarySearchNode* t=findMax(n->left);
	n->data=t->data;
	n->left=del(n->left,t->data);
}
void displayBinaryTree(binarySearchNode* tree){//preorder
	if(tree==NULL) return;
	printf(" <%d> ",tree->data);
	//debug();
	if(tree->left){displayBinaryTree(tree->left);}
	//else{printf("left tree is null for <%d> ",tree->data);}
	if(tree->right){displayBinaryTree(tree->right);}
	//else{printf("right tree is null for <%d> ",tree->data);}
}
void displayInorderBinaryTree(binarySearchNode* tree){
	if(!tree) return;
	
	int i;
	FILE* fp=fopen("inorder.txt","w");
	fprintf(fp,"BST to list to BST:");
	binarySearchNode* root=tree;
	linkedlistStack* s=create();
	while(root||(!isEmptyStack(s))){
		//printf("E:"); scanf("%d",&i);
		while(root!=NULL){
				//printf("pushing %d",root->data);
				push(root,s); 
				root=root->left; 
	}
		root=pop(s);
		
		fprintf(fp,"<%d>", root->data);
		root=root->right;
}
close(fp);
}
void BSTtoDDL(binarySearchNode* tree){
	if(!tree) return;
	int i;
	FILE* fp=fopen("BSTtoDDL.txt","w");
	binarySearchNode* root=tree;
	linkedlistStack* s=create();
	binarySearchNode* start,*end;
	start=end=NULL;	
	while(root||(!isEmptyStack(s))){
		//printf("E:"); scanf("%d",&i);
		while(root!=NULL){
				//printf("pushing %d",root->data);
				push(root,s); 
				root=root->left; 
	}
		root=pop(s);
		if(!start){
			start=end=root;}
		else{
			end->right=root; 
			root->left=end;
			end=root;
		}
		fprintf(fp,"<%d>", root->data);
		root=root->right;
}
	start->left=end;
	end->right=start;
	root=start;
	fprintf(fp,"start:%d\n",start->data);		
	fprintf(fp,"end:%d\n",end->data);
	while(start!=end){
		fprintf(fp,"<%d>", start->data);
		start=start->right;}
	fprintf(fp,"end\n");
		
	while(end!=root){
	fprintf(fp,"<%d>", end->data);
		end=end->left;
}
close(fp);
}
void rangePrinter(binarySearchNode* tree, int min, int max){
if(!tree) return;
	int i;
	FILE* fp=fopen("rangePrinter.txt","w");
	binarySearchNode* root=tree;
	linkedlistStack* s=create();
	while(root||(!isEmptyStack(s))){
		//printf("E:"); scanf("%d",&i);
		while(root!=NULL){
				//printf("pushing %d",root->data);
				push(root,s); 
				root=root->left; 
	}
		root=pop(s);
		if(root->data>=min){
		if(root->data>max) break;	
		fprintf(fp,"<%d>", root->data);}
		root=root->right;
}
close(fp);
	
}
binarySearchNode* inorderSuccessor(binarySearchNode* tree, int key){
	binarySearchNode* n=NULL;
	while(tree){
		if(tree->data>key){n=tree; tree=tree->left;}
		else if(tree->data<=key){tree=tree->right;}
		}	
return n;
}
binarySearchNode* inorderPredecessor(binarySearchNode* tree, int key){
	binarySearchNode* n=NULL;
	while(tree){
		if(tree->data>=key){tree=tree->left;}
		else if(tree->data<key){n=tree; tree=tree->right;}
		
}	
return n;
}
void BSTtoLinkedListStack(binarySearchNode* tree){
if(!tree) return;
	int i;
	node* n=NULL,*tmp=NULL;
	FILE* fp=fopen("BSTtoList.txt","w");
	binarySearchNode* root=tree;
	linkedlistStack* s=create();
	while(root||(!isEmptyStack(s))){
		//printf("E:"); scanf("%d",&i);
		while(root!=NULL){
				//printf("pushing %d",root->data);
				push(root,s); 
				root=root->left; 
	}
		root=pop(s);
		tmp=(node*)malloc(sizeof(node));
		tmp->value=root;
		tmp->next=n;
		n=tmp;
		fprintf(fp,"<%d>", root->data);
		root=root->right;
}
close(fp);
tree=linkedListToBST(n);
displayInorderBinaryTree(tree);
}
void displayPreorderBinaryTree(binarySearchNode* tree);
void displayPostOrderBinaryTree(binarySearchNode* tree);
