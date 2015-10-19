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

class PotentialGeometricSequence {
public:
	int numberOfSubsequences(vector <int>);
};

int PotentialGeometricSequence::numberOfSubsequences(vector <int> d) {
	int n = d.size();

	int cnt = 0;
	for (int i = 0; i < n - 1; ++i){
		int j = i + 1;

		int diff = (d[i] - d[j]);
		cnt++;

		while (j < n - 1){
			if (d[j] - d[j + 1] == diff) cnt++, j++; 
			else break;
		}
	}

	return cnt + d.size();
}