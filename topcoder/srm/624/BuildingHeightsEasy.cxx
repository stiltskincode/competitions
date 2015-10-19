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

int BuildingHeightsEasy::minimum(int M, vector <int> heights) {
	int n = heights.size();
	sort(heights.begin(), heights.end());

	int t = 1000000001;

	for (int i = 0; i <= n - M; ++i){
		int _t = 0;
		for (int j = i; j < i + M - 1; ++j){
			_t += heights[i + M - 1] - heights[j];
		}

		t = min(t, _t);
	}
	
	return t;
}