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

double dp[51][101];

#define INF 1000000001

class PillarsDivTwo {
public:
	double maximalLength(vector <int>, int);
};

double PillarsDivTwo::maximalLength(vector <int> height, int w) {
	for (int i = 0; i < 51; ++i)
		for (int j = 0; j < 101; ++j)
			dp[i][j] = 0;



	int n = height.size();

	for (int i = 1; i < n; ++i){

		for (int j = 1; j <= height[i - 1]; ++j){
			for (int k = 1; k <= height[i]; ++k){

				double len = abs(k - j);

				double sqrtt = sqrt((len*len) + (w*w));

				dp[i][k] = max(dp[i][k], dp[i - 1][j] + sqrtt);
			}
		}
	}

	double ret = 0.0;
	for (int i = 1; i < 101; ++i){
		ret = max(ret, dp[n-1][i]);
	}

	return ret;
}
