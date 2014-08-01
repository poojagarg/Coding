#ifndef STDIO_H_
	#define STDIO_H_
	#include<stdio.h>
#endif

#ifndef AVLDEF_H_
	#define AVLDEF_H_
	#include"AVLDef.h"
#endif
int max(int a, int b){
	if(a>=b) return a;
	else return b;
}
AVLNode* singleRotateLeft(AVLNode* x){
	AVLNode* w=x;
	x=w->left;
	w->left=x->right;
	x->right=w;
	w->height=max(w->left->data, w->right->data)+1;
	x->height=max(x->left->data, x->right->data)+1;
	return x;
}
AVLNode* singleRotateRight(AVLNode* x){
	AVLNode* w=x->right;
	x->right=w->left;
	w->left=x;
	w->height=max(w->left->data, w->right->data)+1;
	x->height=max(x->left->data, x->right->data)+1;
	return w;	
}
AVLNode* DoubleRotateLeft(AVLNode* root){
	root->left=singleRotateRight(root->left);
	return singleRotateLeft(root);
}
AVLNode* DoubleRotateRight(AVLNode* root){
	root->left=singleRotateLeft(root->right);
	return singleRotateRight(root);
}
AVLNode* insert(AVLNode* root, int data){
	if(root==NULL){
		root=(AVLNode*)malloc(sizeof(AVLNode));
		root->data=data;
		root->left=root->right=NULL;
		return root;
	}
	if(root->data>data){
		root->left=insert(root->left, data);
		if(root->left->height-root->right->height==2){
			if(root->left->data>data){
				root=singleRotateLeft(root);		
		}
			else	root=DoubleRotateLeft(root);	
		}//end of inner if
	}// end of if
	else if(root->data<data){
		root->right=insert(root->right, data);
		if(root->left->height-root->right->height==2){
			if(root->right->data<data){
				root=singleRotateRight(root);		
		}
			else	root=DoubleRotateRight(root);	
		}//end of inner if
	}//end of else
root->height=max(root->left->height, root->right->height)+1;
return root;
}
void displayAVLTree(AVLNode* tree){//preorder
	if(tree==NULL) return;
	printf(" <%d> ",tree->data);
	//debug();
	if(tree->left){displayAVLTree(tree->left);}
	//else{printf("left tree is null for <%d> ",tree->data);}
	if(tree->right){displayAVLTree(tree->right);}
	//else{printf("right tree is null for <%d> ",tree->data);}
}
