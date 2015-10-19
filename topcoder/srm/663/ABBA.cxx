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

class ABBA {
public:
	string canObtain(string, string);
};

string ABBA::canObtain(string initial, string target) {
	while (target.length() >= initial.length()){
		if (target == initial) return "Possible";

		if (target[target.length() - 1] == 'A'){
			target.erase(target.end() - 1);
		}
		else{
			target.erase(target.end() - 1);
			reverse(target.begin(), target.end());
		}
	}

	return "Impossible";
}