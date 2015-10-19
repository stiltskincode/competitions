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

#define INF  1000000001

#define MAX 65

int dp[MAX][MAX][MAX];

class MutaliskEasy {
public:
	int minimalAttacks(vector <int>);
	int calc(int x, int y, int z);
};

int MutaliskEasy::calc(int x, int y, int z){

	if (x < 0) return calc(0, y,  z);
	if (y < 0) return calc(x, 0, z);
	if (z < 0) return calc(x, y, 0);


	int& ltr = dp[x][y][z];
	if (ltr != -1) return ltr;

	 

	if (!x && !y && !z) return ltr = 0;

	ltr = INF;

	ltr = min(ltr, calc(x - 9, y - 3, z - 1));
	ltr = min(ltr, calc(x - 9, y - 1, z - 3));

	ltr = min(ltr, calc(x - 3, y - 9, z - 1));
	ltr = min(ltr, calc(x - 3, y - 1, z - 9));

	ltr = min(ltr, calc(x - 1, y - 9, z - 3));
	ltr = min(ltr, calc(x - 1, y - 3, z - 9));
	
	
	ltr++;
	return ltr;
}


int MutaliskEasy::minimalAttacks(vector <int> x) {

	if (x.size() == 1) return ceil(x[0] / (float)9);

	memset(dp, -1, sizeof(dp));
	if (x.size() == 2) return calc(x[0], x[1], 0);
	
	return  calc(x[0], x[1], x[2]);

}