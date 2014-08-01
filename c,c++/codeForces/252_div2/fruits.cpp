#include<iostream>
#include<stdio.h>
#include<map>
using namespace std;
int main(){
	int n, v;
	scanf("%d",&n);
	scanf("%d",&v);
	map<int, int> fruit;	
	for(int i=0; i<n; i++){
		int d, c;
		scanf("%d",&d);
		scanf("%d",&c);
		map<int,int>::iterator it;
		it=fruit.find(d);
		if(it==fruit.end()){
			fruit[d]=c;
		}
		else{
			fruit[d]+=c;
		}
		}
	int count=0;
	map<int,int>::iterator it=fruit.begin();
	if(it->second<v){
		count+=it->second;
		it->second=0;
	}
	else{
		count+=v;
		it->second-=v;
	}
	map<int,int>::iterator prev=it;
	it++;
	for(; it!=fruit.end(); ++it){
		/*cout << it->first << " => " << it->second << '\n';
		cout << prev->first << " => " << prev->second << '\n';*/
		if(prev->first==(it->first-1)){
			int nv=v;
			if(prev->second<nv){
				count+=prev->second;
				nv-=prev->second;				
				prev->second=0;
				if(it->second<nv){
					count+=it->second;
					it->second=0;
				}
				else{
					count+=nv;
					it->second-=nv;
				}
			}
			else{
				count+=nv;
				prev->second-=nv;
			}
		}
		else{
			if(prev->second<v){
				count+=prev->second;
				prev->second=0;
			}
			else{
				count+=v;
				prev->second-=v;
			}
			if(it->second<v){
				count+=it->second;
				it->second=0;
			}
			else{
				count+=v;
				it->second-=v;
			}
		}
		//cout<<"<"<<count<<">";
		prev=it;
	}
	if(prev->second<v){
		count+=prev->second;
		prev->second=0;
	}
	else{
		count+=v;
		prev->second-=v;
	}
	    		
    	printf("%d",count);		
    }
	
