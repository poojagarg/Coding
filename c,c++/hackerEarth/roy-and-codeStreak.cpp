#include<iostream>
#include<cstdio>
#include<map>
#include<utility>
#include<set>
using namespace std;
typedef pair<long, int> ii;
int main(){
	int t;
	scanf("%d",&t);
	while(t){
		t--;
		long n,s;
		set<long> submission;
		scanf("%lu",&n);
		long count=0; int f=0;
		int tempCount=0;
		pair<set<long>::iterator,bool> ret;
		for(int i=0; i<n; i++){
			int r;
			scanf("%lu",&s);
			scanf("%d",&r);
			if(r==1){
				ret=submission.insert(s);
				if(f==0){
					f=1; tempCount=1;
				}
				else{
					tempCount++;
				}
				if(ret.second==false){
					tempCount--;
				}				
			}
			else if(r==0){
				count=count>=tempCount?count:tempCount;
				f=0;
				tempCount=0;
			}
				
		}
		count=count>=tempCount?count:tempCount;		
		printf("%lu\n",count);
		
	}
}
