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

class FixedDiceGameDiv2 {
public:
	double getExpectation(int, int);
};

double FixedDiceGameDiv2::getExpectation(int a, int b) {
	double sum = 0;
	int d = 0;
	for (int i = 2; i <= a; ++i){
		int t = i <= b ? i - 1 : b;
		sum += (t * i);
		d += t;
	}

	return sum / d;
}
