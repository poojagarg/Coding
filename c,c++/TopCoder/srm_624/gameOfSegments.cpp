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

class GameOfSegments {
public:
	int winner(int);
};

int GameOfSegments::winner(int n) {
	vector<int> v(n+1);
	v[3]=3;
	for(int i=4; i<=n; i++){
		v[i]=v[i-1]+2;
		cout<<"winner for"<<i<<":"<<v[i]<<endl;
	}
}
int main(){
	GameOfSegments g;
	g.winner(15);
}

