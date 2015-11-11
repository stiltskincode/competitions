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
int dp[51];
class ProblemsToSolve {
public:
	int minNumber(vector <int>, int);
};

int ProblemsToSolve::minNumber(vector <int> pleasantness, int variety) {
	for (int i = 0; i <= 51; ++i) dp[i] = INF;

	int n = pleasantness.size();

	int ret = n;

	for (int i = 0; i < n - 1; ++i){
		for (int j = i + 1; j < n; ++j){
			int _a = max(pleasantness[i], pleasantness[j]);
			int _b = min(pleasantness[i], pleasantness[j]);

			if (_a - _b >= variety){
				int _pre = i % 2 == 0 ? i / 2 : i / 2 + 1;
				int _post = (j - i) % 2 == 0 ? ((j - i) / 2) + 1 : ((j - i) / 2) + 2;
				ret = min(ret, _pre + _post);
			}
		}
	}

	return ret;
}
