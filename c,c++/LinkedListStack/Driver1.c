#ifndef _LINKEDLISTSTACK_H
	#include"linkedlistStack.h"
#endif
#ifndef _STDIO_H
	#include<stdio.h>
#endif
linkedlistStack* create();
void push(int value,linkedlistStack* s);
int pop(linkedlistStack* s);
void deleteStack(linkedlistStack* s);
int main(){
	linkedlistStack* s=create();
	int i,size=5;
	char a[20];
	printf("input a string\n");
	scanf("%s",a);
	i=0;
	while(a[i]!='\0'){
		push((char)a[i],s);
		i++;
		}
	printf("no. of elements pushed %d", i);
	while(s->top!=NULL){
		printf("%c",(char)pop(s));
		//scanf("%d",&i);	
	}
	deleteStack(s);
	return 0;
}

