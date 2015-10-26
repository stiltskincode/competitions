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

class SRMCards
{
public:
	int maxTurns(vector <int> c)
	{
		sort(c.begin(), c.end());
		int n = c.size();
		int count = n;
		for (int i = 0; i < n - 1; ++i){
			if (c[i] + 1 == c[i + 1]) count--, i++;
		}

		return count;
	}
};
