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

class LongLongTripDiv2 {
public:
	string isAble(long long, int, int);
};

string LongLongTripDiv2::isAble(long long D, int T, int B) {
	int n = D / B;
	int r = D % B;

	int total = n + r;

	

	if (total == T) return "Possible";
	else if (total > T) return "Impossible";
	else{
		D -= total;
		do{
			total += (B - 1);
			D -= (B - 1);
			if (total == T ) return "Possible";
		} while (total < T && D > 0);

		return "Impossible";
	}


}
