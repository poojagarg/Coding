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

class BuildingHeightsEasy {
public:
	int minimum(int, vector <int>);
};

int BuildingHeightsEasy::minimum(int m, vector <int> h) {
	sort(h.begin(), h.end());
	int n=h.size();
	vector<int> f(n,0);
	int min=32767;
	for(int i=m-1; i<n; i++){
		for(int j=i-(m-1); j<i; j++){
			f[i]+=(v[i]-v[j]);
		}
		min=f[i]<min?f[i]:min;
	}
	return min;
}

<%:testing-code%>
//Powered by [KawigiEdit] 2.0!
