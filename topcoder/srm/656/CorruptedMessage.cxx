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

class CorruptedMessage {
public:
	string reconstructMessage(string, int);
};

string CorruptedMessage::reconstructMessage(string s, int k) {
	int n = (int)s.size() - k;

	map<char, int> cnt;

	for (char i = 'a'; i <= 'z'; ++i) cnt[i];
	for (int i = 0; i < s.size(); ++i)cnt[s[i]]++;
	for (auto c : cnt) 
		if (c.second == n) 
			return string(k + n, c.first);
}

