#include<iostream>
#include<map>
#include<string>
#include<cstdio>
using namespace std;
#define dividend 1000000007
long fact(long n){
	long r=1;
	for(int i=2; i<=n; i++){
		r=r*i;
	}
	return r;
}
long comb(long n, long p){
	return fact(n)/fact(n-p);
}
int main(){
	int test;
	scanf("%d",&test);
	while(test){
		map<char, int> bday;
		for(int i=0; i<26; i++){
			bday['a'+i]=0;
		}
		test--;
		string s;
		cin>>s;
		for(int i=0; i<s.length(); i++){
			bday[s[i]]++;
		}
		long noc=0,nov=0;
		nov=bday['a']+bday['e']+bday['i']+bday['o']+bday['u'];
		noc=s.length()-nov;
		if(nov>noc+1){
			cout<<-1<<endl;
			continue;
		}
		long r=fact(noc);
		for(int i=1; i<26; i++){
			switch('a'+i){
			case 'e':
			case 'i':
			case 'o':
			case 'u':break;
			default: r=r/bday['a'+i];
			}
		r=r*comb(noc+1,nov);
		r=r*fact(nov);
		r=r/fact(bday['a']);
		r=r/fact(bday['e']);
		r=r/fact(bday['i']);
		r=r/fact(bday['o']);
		r=r/fact(bday['u']);
		cout<<r<<endl;
		}
	}
}
