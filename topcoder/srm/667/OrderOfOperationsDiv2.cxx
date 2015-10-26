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

#ifdef _MSC_VER
#  include <intrin.h>
#  define __builtin_popcount __popcnt
#endif


pair<int, int> arr[20];

class OrderOfOperationsDiv2 {
public:
	int minTime(vector <string>);
};

int OrderOfOperationsDiv2::minTime(vector <string> s) {
	int n = s.size();
	int k = s[0].size();


	for (int i = 0; i < n; ++i){
		int t = 0;
		for (int j = 0; j < k; ++j){
			if (s[i][j] == '1') t |= 1 << j;
		}

		arr[i] = make_pair(__builtin_popcount(t), t);
	}

	sort(arr, arr + n);

	int sum = 0;

	for (int i = 0; i < n; ++i){
		sum += pow(arr[i].first, 2);
		for (int j = i + 1; j < n; ++j){
			int k = arr[j].second ^ (arr[j].second & arr[i].second);

			arr[j] = make_pair(__builtin_popcount(k), k);
		}
	}

	return sum;
}
