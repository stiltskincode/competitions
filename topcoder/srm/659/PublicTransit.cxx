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


typedef vector<vector<int>> VVI;

#define INF 1000000001
typedef vector<int> vi;
typedef vector<vi> vvi;

class PublicTransit {
public:
	int minimumLongestDistance(int, int);
};

int PublicTransit::minimumLongestDistance(int R, int C) {
	int mx = max(R, C);
	int mi = min(R, C);

	return ((mx - 1) /2) + mi - 1;
}

