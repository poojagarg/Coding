#include<iostream>
#include<queue>
#include<string>
#include<cstring>
#include<stdio.h>
#include<set>
using namespace std;
#define tr(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++) 
void print(queue<string> q);
queue<string> permute(char* a){
	int n=strlen(a);
	queue<string> q[2];
	string s;
	s+=a[0];
	q[0].push(s);
	int i=0;
	int p=1;
	while(p<n){
	//print(q[i]);
	//cout<<endl;
	while(!q[i].empty()){
		s=q[i].front();
		q[i].pop();
		s+=a[p]; 
		q[(i+1)%2].push(s);		
		int slen=s.length();
		for(int j=slen-1;j>0; j--){
			char t=s[j];
			s[j]=s[j-1];
			s[j-1]=t;
			q[(i+1)%2].push(s);
		}
	}
	p++;
	i=(i+1)%2;
	}
	return q[i];
	}
set<string> permuteRep(char* a){
	int n=strlen(a);
	set<string> q[2];
	string s;
	s+=a[0];
	q[0].insert(s);
	int i=0;
	int p=1;
	while(p<n){
		tr(q[i],it){
		s=*it;
		s+=a[p]; 
		q[(i+1)%2].insert(s);		
		int slen=s.length();
		for(int j=slen-1;j>0; j--){
			char t=s[j];
			s[j]=s[j-1];
			s[j-1]=t;
			q[(i+1)%2].insert(s);
		}
	}
	q[i].clear();
	p++;
	i=(i+1)%2;
	}
	return q[i];
	}
void print(set<string> s){
	cout<<s.size()<<'\n';
	tr(s,it){
		cout<<*it<<'\t';
	}
	s.clear();
}
void print(queue<string> q){
	while(!q.empty()){
		string n=q.front();
		q.pop();
		cout<<n<<'\t';
	}
}
int main(){
	char a[100];
	scanf("%s",a);
	set<string> q=permuteRep(a);
	print(q);
}
