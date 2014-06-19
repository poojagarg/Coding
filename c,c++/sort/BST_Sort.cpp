#include<iostream>
#include<cstdio>
#include<malloc.h>
#define treeSize 10
using namespace std;
typedef struct node{int e; struct node *l, *r;}node;
void deleteNode(node* root);
node* createTree(int e){
	node* n=(node*)malloc(sizeof(node));
	n->e=e;
	n->l=n->r=NULL;
	return n;
}
void insert(node* root, int e){
	while(true){
	if(root->e>e){
		if(root->l!=NULL)
			root=root->l;
		else{
			root->l=(node*)malloc(sizeof(node));
			root->l->e=e;
			root->l->l=root->l->r=NULL;
			return;
		}
	}
	else{
		if(root->r!=NULL)
			root=root->r;
		else{
			root->r=(node*)malloc(sizeof(node));
			root->r->e=e;
			root->r->l=root->r->r=NULL;
			return;
		}
	}
	}
}
int isLeaf(node* root){
	if(root->l==NULL&&root->r==NULL)
		return 1;
	return 0;
}
void inorder(node* root){
	if(root!=NULL){
		inorder(root->l);
		cout<<root->e<<'\t';
		inorder(root->r);
		}
	return;
}
int deleteValue(node* root, node* parentRoot, int side, int n){
	if(root==NULL){//Not found
		return 0;
	}
	if(root->e==n){
		if(isLeaf(root)){
			if(parentRoot==NULL){
				free(root);
				return 1;
			}
			else{
				switch(side){
					//left
					case 0:parentRoot->l=NULL;
						break;
					//right
					case 1:parentRoot->r=NULL;
						break;
				}
				free(root);
			}
		}
		else{
			deleteNode(root);
			}
		return 2;			
	}
	if(root->e<n){
		deleteValue(root->r,root,1,n);
	}
	else{ 		
		deleteValue(root->l,root,0,n);
		}
}
node* maxP(node* root){
	if(root->r->r==NULL)
		return root;
	return maxP(root->r);
}
void deleteNode(node* root){
	int choice;
	if(root->l&&root->r){
		cout<<root->l->e<<':'<<root->r->e<<'\t';
		choice=0;
	}
	else if(root->l){
		choice=1;
	}
	else if(root->r){
		choice=2;
	}
	node *maxParent,*temp;
	switch(choice){
		case 0: if(isLeaf(root->l)){
				root->e=root->l->e;
				temp=root->l;
				root->l=NULL;
				free(temp);
			}
			else{
			maxParent=maxP(root->l);
			root->e=maxParent->r->e;
			temp=maxParent->r;
			maxParent->r=maxParent->r->l;
			free(temp);
			}
			break;
		case 1:root->e=root->l->e;
			root->r=root->l->r;
			temp=root->l;
			root->l=root->l->l;
			free(temp);
			break;
		case 2:root->e=root->r->e;
			root->l=root->r->l;
			temp=root->r;
			root->r=root->r->r;
			free(temp);
	}
}
int main(){
	int A[treeSize];
	FILE* fp=fopen("sort.txt","r");
	int i=0;
	while(i<treeSize){
		int d;
		char c;
		fscanf(fp,"%d%c",&d,&c);
		A[i]=d;
		i++;
	}
	node* root=createTree(A[0]);
	for(int i=1; i<treeSize;i++){
		insert(root,A[i]);
	}
	//inorder(root);
	int d=deleteValue(root, NULL, 0, 9);
	if(d==1){
		root=NULL;
	}
	if(d==0){
		cout<<"Not Found";
	}
	inorder(root);
}
