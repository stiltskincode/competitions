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

class RandomPancakeStackDiv2 {
public:
	double expectedDeliciousness(vector<int> d);
};

double RandomPancakeStackDiv2::expectedDeliciousness(vector<int> d){
	int n = d.size();
	
	long long ret = 0;
	vector<int> a;
	for (int i = 0; i < n; ++i){
		a.push_back(i + 1);
	}

	long long ways = 0;
	do{
		int cur = n + 1;
		for (int i = 0; i < n; ++i){
			if (a[i] > cur)
				break;
			ret += d[a[i] - 1];
			cur = a[i];
		}
		ways++;
	
	} while (next_permutation(a.begin(), a.end()));
	 

	return (double)ret / ways;;
}
