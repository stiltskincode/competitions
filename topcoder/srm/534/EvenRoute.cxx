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
long long  dp[50][50];

class EvenRoute {
public:
	string isItPossible(vector <int>, vector <int>, int);
};

string EvenRoute::isItPossible(vector <int> x, vector <int> y, int wantedParity) {
	int n = x.size();

	for (int i = 0; i < 50; ++i)
		for (int j = 0; j < 50; ++j)
			dp[i][j] = 0;

	for (int i = 0; i < n; ++i){
		dp[0][i] = abs(x[i]) + abs(y[i]);
	}


	for (int i = 1; i < n; ++i){ // dla kazdego kroku

		for (int j = 0; j < n; ++j){ // dla kazdego poprzedniego punktu
			for (int k = 0; k < n; ++k){ // dla kazdego nowego punktu
				if (j != k){ // jezeli punkty nie sa takie same (czyli nie idziemy z tego samego punktu do tego samego)
					int lx = abs(x[k]) + abs(x[j]);
					int ly = abs(y[k]) + abs(y[j]);

					dp[i][j] = max(dp[i][k], dp[i - 1][j] + (abs(x[k]) + abs(x[j]) + abs(y[k]) + abs(y[j])));
				}
			}
		}


	}


	
	for (int i = 0; i < n; ++i){
		if (dp[n - 1][i] % 2 == wantedParity)
				return "CAN";
	}
	
	return "CANNOT";
}