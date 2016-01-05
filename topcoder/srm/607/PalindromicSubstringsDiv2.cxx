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

class PalindromicSubstringsDiv2 {
public:
	int count(vector <string>, vector <string>);
};

int PalindromicSubstringsDiv2::count(vector <string> S1, vector <string> S2) {
	string s1, s2; 
	s1 = accumulate(S1.begin(), S1.end(), s1);
	s2 = accumulate(S2.begin(), S2.end(), s2);

	string s = s1 + s2;


	int n = s.size();

	int ret = 0;

	int l, r;
	for (int i = 0; i < n; ++i){
		l = i, r = i;
		while (l >= 0 && r < n && s[l--] == s[r++]) 
			ret++;

		l = i, r = i + 1;
		while (l >= 0 && r < n && s[l--] == s[r++])
			ret++;
	}
	return ret;
}
