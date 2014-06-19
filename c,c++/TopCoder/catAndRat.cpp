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
#define PI 3.141592653589793238
using namespace std;

class CatAndRat {
public:
	double getTime(int, int, int, int);
	double min(double a, double b){
		if(a>b)
			return a;
		else
			return b;
	}
};

double CatAndRat::getTime(int R, int T, int r, int c) {
	if(r>=c){
		return -1.0;
	}
	else{
		double tt=min(T*r, PI*R);
		return tt/(c-r);
	}
}

<%:testing-code%>
//Powered by [KawigiEdit] 2.0!
