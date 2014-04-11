#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<string>
#include<stack>
#include<vector>
#include<algorithm>
#include<iostream>
//#include<limits.hi
#define INT_MAX 1000000
using namespace std;
//#define push_back pb
//vector<int>::iterator it
//#define tr(container, it) \ 
//      for(typeof(container.begin()) it = container.begin(); it != container.end(); it++) 
#define all(c) c.begin(), c.end() 
#define present(container, element) (container.find(element) != container.end()) //in set
#define cpresent(container, element) (find(all(container),element) != container.end()) //in vector

#include<cstdio>
#include<cmath>
using namespace std;

int fac = INT_MAX;

bool sq(int n)
{
    int root = sqrt(n);
    if(root*root == n) return true;
    else return false;
}

int factor(int n)
{   if(n==1) return 0;
    int a[65]={2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127,131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271,277,281, 283, 293, 307, 311, 313};
	//for(int i=0; i<65; i++){printf("%d\t",a[i]);}
	int prod=1; int count=0; int i=0; int p=a[0]; 	//printf("%d\n",n);
	while(n>1){
		count=0;
		while(n%p==0){
			n=n/p; count++; 
			if(n==1) return prod*(count+1);} 
		prod*=(count+1); 
		while(n%p!=0) {i++;  if(i>64) return prod; p=a[i];}
		}
	return prod;
}


int makenum(vector<int> v)
{
    int s = v.size();
    int m = 1;
    int ret = 0;
    for(int i=s-1;i>=0;i--)
    {
        ret = ret+ v[i]*m;
        m*=10;
    }
    return ret;
}

int main()
{
    vector<int> input;
    char c='a';
    int number=0;

    while(c!='\n')
    {
        int a;
        cin>>a;
        input.push_back(a);
        scanf("%c",&c);
    }
    sort(all(input)); number=input[0];
   do
    {
      //  cout<<input[0]<<input[1]<<input[2];
      int n = makenum(input);
      //printf("%d ",factor(n));
	int tmp=factor(n);
      if(fac>tmp)
      {
        number = n; 
        fac = tmp;
      }
      //cout<<n<<endl;
    }while(next_permutation(all(input)));

    cout<<number<<endl;
    return 0;
}







