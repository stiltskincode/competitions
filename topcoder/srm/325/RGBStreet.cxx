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


int dp[21][3];

class RGBStreet {
public:
	int estimateCost(vector <string>);
};

int RGBStreet::estimateCost(vector <string> houses) {

	for (int i = 0; i <= 21; ++i){
		dp[i][0] = 0;
		dp[i][1] = 0;
		dp[i][2] = 0;
	}

	std::istringstream iss(houses[0]);
	int r;
	int g;
	int b;

	iss >> r;
	iss >> g;
	iss >> b;



	dp[0][0] = r;
	dp[0][1] = g;
	dp[0][2] =b;


	int n = houses.size();


	for (int i = 1; i < n; ++i){
		std::istringstream is(houses[i]);
		int r;
		int g;
		int b;
		
		is >> r;
		is >> g;
		is >> b;

		dp[i][0] = min(dp[i - 1][1] + r, dp[i - 1][2] + r);

		dp[i][1] = min(dp[i - 1][0] + g, dp[i - 1][2] + g);
		dp[i][2] = min(dp[i - 1][0] + b, dp[i - 1][1] + b);
	}

	return min(dp[n-1][0], min(dp[n-1][1], dp[n-1][2]));
}
