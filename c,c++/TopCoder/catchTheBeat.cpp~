#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;
typedef pair<int, int> ii;

class CatchTheBeatEasy {
public:
	string ableToCatchAll(vector <int>, vector <int>);
};

string CatchTheBeatEasy::ableToCatchAll(vector <int> x, vector <int> y) {
	int n=x.size();
	vector<ii> v;
	for(int i=0; i<n; i++){
		v.push_back(ii(y[i],x[i]));
	}
	sort(v.begin(), v.end());
	int t=0;
	int c=0; //current co-ordinate
	int i=0;
	while(i<n){
		int xc=	v[i].second;
		int yc=v[i].first-t;
		if(yc<0) return "Not able to catch";
		int tt=xc-c;
		if(tt<0) tt=-1*tt;
		if(tt>yc)
			return "Not able to catch";
		else{
			t+=tt;
			i++;
			c=xc;
		}	
	}
	return "Able to catch";
}
int main(){
	vector<int> x(10, 2);
	vector<int> y(10,0);
	y[0]=2;
	y[3]=1;
	y[1]=9;
	CatchTheBeatEasy c;
	cout<<c.ableToCatchAll(x,y);
}
