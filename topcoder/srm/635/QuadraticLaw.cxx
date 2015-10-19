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

class QuadraticLaw {
public:
	long long getTime(long long);
};

long long QuadraticLaw::getTime(long long d) {
	long long t = sqrt(d);
	while (t*(1 + t) > d){
		--t;
	}

	return t;
}

