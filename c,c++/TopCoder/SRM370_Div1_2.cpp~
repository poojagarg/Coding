#include<iostream>
#include<vector>
using namespace std;
class DrawingMarbles{
public:
double f(int n,int total,int c){//return ccn/totalcn
	cout<<"<"<<n<<","<<total<<","<<c<<">";
	if(c<n) return 0;
	double r=1;
	for(int i=0; i<n; i++){
		r*=(double)c/total;
		c--; total--;
	}
	cout<<"<"<<r<<">";
	return r;
}
double sameColor(vector <int> colors, int n){
	int s=colors.size();
	double p=0; int total=0;
	for(int i=0; i<s; i++){
		total+=colors[i];
	}
	for(int i=0; i<s; i++){
		p+=f(n,total,colors[i]);
	}
	return p;
}
};
int main(){
	DrawingMarbles m;
	vector<int> colors;
	colors.push_back(5);
	colors.push_back(6);
	colors.push_back(7);
	cout<<m.sameColor(colors,2);
}
