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
#define MIN(a, b) a < b ? a : b

class CandyMaking {
public:
	double findSuitableDensity(vector <int>, vector <int>);
};

double CandyMaking::findSuitableDensity(vector <int> containerVolume, vector <int> desiredWeight) {
	double g_min = INF;
	int n = containerVolume.size();

	int min_i = 0;

	for (int i = 0; i < n; ++i){
		g_min = MIN(g_min, desiredWeight[i] / (double)containerVolume[i]);
		min_i = (desiredWeight[i] / containerVolume[i]) < (desiredWeight[min_i] / containerVolume[min_i]) ? i : min_i;
	}


	double total = 0;
	for (int i = 0; i < n; ++i){
		if (i != min_i){
			total += desiredWeight[i] - (double)((containerVolume[i] * desiredWeight[min_i]) / (double)containerVolume[min_i]);
		}
	}
	return total;
}

