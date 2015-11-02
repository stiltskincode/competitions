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

bool isBaseOf5(long long k){
	if(k == 1) return true;

	while (k > 1){
		if (k % 5) return false;;
		k /= 5;
	}

	return k == 1;
}
int dp[51];
class CuttingBitString {
public:
	int getmin(string);
	int clc(string S, int start){
		int n = S.size();

		if (dp[start] < INF) return dp[start];

		if (n == start)  return 0;
		int k = 0;
		int w = -1;
		for (int i = start; i < n; ++i){
			if (!k && S[i] == '0') return INF;
			k = (S[i] == '1') ? (k << 1) | 1 : (k << 1) | 0;

			if (isBaseOf5(k)){

				dp[start] = min(dp[start], clc(S, i + 1) + 1);

			}
		}

		return dp[start];
	}
	
};

int CuttingBitString::getmin(string S) {
	for (int i = 0; i < 51; ++i)dp[i] = INF;


	int w = clc(S, 0);
	return w == INF ? -1 : w ;
}
