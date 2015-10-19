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
#include <unordered_set>
using namespace std;

class SortishDiv2 {
public:
	int ways(int, vector <int>);
};

int SortishDiv2::ways(int sortedness, vector <int> seq) {
	int n = seq.size();

	vector<int> perm(n);
	vector<int> pos;
	int i = 0;

	do{
		perm[i++] = i;
	} while (i < n);
	

	for (int i = 0; i < n; ++i){
		if (seq[i] > 0){
			perm[seq[i] - 1] = 0;
		}
		else{
			pos.push_back(i);
		}
	}

	sort(perm.begin(), perm.end());
	perm.erase(perm.begin(), perm.begin() + perm.size() - pos.size());

	int res = 0;
	do{
		vector<int> seq2 = seq;
		for (int i = 0; i < pos.size(); ++i){
			seq2[pos[i]] = perm[i];
		}

		long long ss = 0;
		for (int i = 0; i < n - 1; ++i){
			for (int j = i + 1; j < n; ++j){
				if (seq2[i] < seq2[j]) 
					ss++;
			}
		}

		if (ss == sortedness) res++;
	} while (next_permutation(perm.begin(), perm.end()));


	return res;

}

