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

class ExactTreeEasy {
public:
	vector <int> getTree(int, int);
};

vector <int> ExactTreeEasy::getTree(int n /*nodes*/, int m /*leaves*/) {
	vector<int> k;

	int i;

	--m; --n;
	for (i = 1; i <= m; ++i){
		k.push_back(0);
		k.push_back(i);
		--n;
	}


	for (int j = i; j < n + i; ++j){
		k.push_back(j - 1);
		k.push_back(j);
	}

	return k;
	
}