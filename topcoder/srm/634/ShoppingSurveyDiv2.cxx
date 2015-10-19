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

class ShoppingSurveyDiv2 {
public:
	int minValue(int, vector <int>);
};

int ShoppingSurveyDiv2::minValue(int N, vector <int> s) {
	vector<int> k(N, 0);

	for (int i = 0; i < s.size(); ++i){
		sort(k.begin(), k.end());

		for (int j = 0; j < N; ++j){
			if (s[i]){
				k[j]++;
				s[i]--;
			}
		}
	}

	int cnt = 0;
	for (int i = 0; i < N; ++i){
		if (k[i] == s.size()) cnt++;
	}

	return cnt;
}
