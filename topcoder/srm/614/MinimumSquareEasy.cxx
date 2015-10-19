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


#define INF 1000000001
class MinimumSquareEasy {
public:
	long long minArea(vector <int>, vector <int>);
	long long area(vector<int> xx, vector<int> yy){
		int n = xx.size();

		int minx = INF, maxx = -INF;
		int miny = INF, maxy = -INF;
	
		for (int i = 0; i < n; ++i){
			minx = min(minx, xx[i]);
			maxx = max(maxx, xx[i]);

			miny = min(miny, yy[i]);
			maxy = max(maxy, yy[i]);
		}

		long long side = max(abs(maxx - minx + 2), abs(maxy - miny + 2));

		return side*side;
	}


};