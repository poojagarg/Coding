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
	char line[200];
	scanf("%s",line);
	int k;
	scanf("%d",&k);
	int t=2*k;
	int ll=line.length();
	if(ll<=k){
		printf("%d",2*ll);
		return 0;
	}
	int t=2*k;
	for(int i=ll-(k+2); i>=0; i=i-2){
		t=t+2;
		for(int j=i; j<i+t/2&&j<<ll;j++){
			if(a[j]!=a[j+t/2])
				break;
		}
	}
