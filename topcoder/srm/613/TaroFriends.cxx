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

#define MAX_LONG_LONG 0x7fffffffffffffff
#define MIN(a, b) a<b?a:b
#define MAX(a, b) a>b?a:b
class TaroFriends {
public:
	int getNumber(vector <int>, int);
	int getLength(vector <int> coordinates){
		long long mi = MAX_LONG_LONG, ma = -MAX_LONG_LONG;

		for (int i = 0; i < coordinates.size(); ++i){
			mi = MIN(mi, coordinates[i]);
			ma = MAX(ma, coordinates[i]);
		}

		return ma - mi;
	}
};

int TaroFriends::getNumber(vector <int> coordinates, int X) {
	int n = coordinates.size();
	long long t = MAX_LONG_LONG;
	reverse(coordinates.begin(), coordinates.end());


	for (int flag = 0; flag < 1 << n; ++flag){
		vector <int> cp = coordinates;
		

		for (int j = 0; j < n; ++j){
			if (flag& (1<<j)){
				cp[j] += X;
			}
			else{
				cp[j] -= X;
			}
		}

		t = MIN(t, abs(getLength(cp)));

	}
	return (int)t;
}

