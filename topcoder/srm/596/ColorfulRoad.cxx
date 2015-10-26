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
inline char nextt(char c) {
	return c == 'R' ? 'G' : c == 'G' ? 'B' : c == 'B' ? 'R' : ' ';
};

class ColorfulRoad {
public:
	int getMin(string);
};

int ColorfulRoad::getMin(string road) {
	int n = road.length();

	vector<int> dp(n, INF);

	dp[0] = 0;

	
	for (int i = 0; i < n; ++i){
		if (dp[i] != INF){
			for (int j = 1; j < n; ++j){
				if (nextt(road[i]) == road[j]){
					int k = j - i;
					dp[j] = min(dp[j], dp[i] + k*k);
				}
			}
		}
	}

	return dp[n - 1] != INF ? dp[n - 1] : -1;
}