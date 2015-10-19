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

class PairGameEasy {
public:
	string able(int, int, int, int);
	bool can(int a, int b, int c, int d){
		if (a == c && b == d) return true;
		else if (a > c || b > d) return false;
		else{
			return can(a + b, b, c, d) || can(a, b + a, c, d);
		}
	};
};

string PairGameEasy::able(int a, int b, int c, int d) {
	return (a == c && b ==d) || (can(a, b, c, d)) ? "Able to generate" : "Not able to generate";
}

