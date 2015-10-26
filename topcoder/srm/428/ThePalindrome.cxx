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

class ThePalindrome {
public:
	int find(string);
	bool isPalindrome(string s){
		int l = 0, r = s.size() - 1;

		while (l <= r){
			if (s[l] == s[r]) l++, r--;
			else return false;
		}
		return true;
	}
};

int ThePalindrome::find(string s) {
	int n = s.size();

	if (isPalindrome(s)) return s.size();

	string s1;
	for (int i = 0; i < n; ++i){
		string s2 = s[i] + s1;
		if (isPalindrome(s + s2)) return n + i + 1;
		s1 = s2;
	}
}
