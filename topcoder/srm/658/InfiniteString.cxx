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

class InfiniteString {
public:
	string equal(string, string);
};

string InfiniteString::equal(string s, string t) {
	string s1 = (s.length() <= t.length()) ? s : t; // min
	string s2 = s.length() > t.length() ? s : t; // max

	int idx = s2.length() - 1;
	for (int i = s1.length()-1; i >= 0; --i){
		if (s1[i] != s2[idx]) return "Not equal";
		--idx;
	}


	return s.length() == t.length() ? "Equal" : equal(s2.substr(0, s2.length() - s1.length()), s1);
}