#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <ctype.h>
#include <stack>
#include <iostream>
#include <queue>
#include <set>
#include<utility>
using namespace std;
int main(){
	char line[1001];
	set<char> s;
	int j=0;
	int c;
	do{
		c=getchar();
		line[j]=c;
		j++;
	}while(c!='}');
	line[j]='\0';
	//printf("%s",line);
	c=0;
	if(line[1]=='}'){
		printf("%d",0);
		return 0;
		}
	else {
	for(int i=1; ;i=i+3){
		s.insert(line[i]);
		if(line[i+1]=='}')
			break;
		}
	printf("%lu",s.size());
	}
}
