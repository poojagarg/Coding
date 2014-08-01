#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main(){
	int l;
	scanf("%d",&l);
	while(l){
		l--;
		int count=0;
		char s[100];
		scanf("%s",s);
		int j=0;
		int p=0; 
		while(s[j]!='\0'){
			int t=s[j]-'a';
			int c;
			int a;
			if(t>=p){
				c=t-p;
				a=26-c;
			}
			else{
				a=p-t;
				c=26-a;
			}
			if(a>=c){
					printf("%d ",c);
					p=t;
			}
			else{
				printf("%d ",-1*a);
				p=t;
			}
			j++;
		}
		printf("\n");
	}
}
