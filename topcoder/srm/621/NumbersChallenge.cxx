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

class NumbersChallenge {
public:
	int MinNumber(vector <int>);
};

int NumbersChallenge::MinNumber(vector <int> S) {
	int n = S.size();
	vector<long int> t;

	
	for (long flag = 0; flag < 1 << n; ++flag){
		long k = 0;
		for (int i = 0; i < n; ++i){
			if (flag&(1 << i)){
				k += S[i];
			}
		}
		t.push_back(k);
	}

	sort(t.begin(), t.end());
	if (t[0] > 1) return 1;

	for (int i = 1; i < t.size() - 1; ++i){
		if (t[i] + 1 < t[i + 1]) return t[i] + 1;
	}
	return t[t.size()-1] + 1;
}
