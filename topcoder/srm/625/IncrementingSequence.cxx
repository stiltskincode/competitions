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

class IncrementingSequence {
public:
	string canItBeDone(int, vector <int>);
};

string IncrementingSequence::canItBeDone(int k, vector <int> A) {
	int n = A.size();
	int _max = 50 * 50 * 10;
	int total = 0;
	vector<int> seq(_max, 0);
	sort(A.begin(), A.end());

	for (int i = 0; i < n; ++i){
		seq[A[i]]++;
		total++;
	}

	for (int i = 1; i <= total; ++i){
		if (seq[i] == 0) return "IMPOSSIBLE";

		for (int j = seq[i]; j > 1; --j){
			seq[i]--;
			seq[seq[i] * k + i]++;
		}

	}

	return "POSSIBLE";
}
