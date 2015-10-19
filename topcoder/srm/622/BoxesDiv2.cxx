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

unsigned int roundUpToNextPowerOfTwo(unsigned int x)
 {
		 x--;
	   x |= x >> 1;  // handle  2 bit numbers
	   x |= x >> 2;  // handle  4 bit numbers
	   x |= x >> 4;  // handle  8 bit numbers
	   x |= x >> 8;  // handle 16 bit numbers
	   x |= x >> 16; // handle 32 bit numbers
	   x++;
	
	 return x;
}

class BoxesDiv2 {
public:
	int findSize(vector <int>);
};

int BoxesDiv2::findSize(vector <int> candyCounts) {
	int n = candyCounts.size();
	int sum = 0;
	for (int i = 0; i < n; ++i){
		sum+= roundUpToNextPowerOfTwo(candyCounts[i]);
	}


	
	return roundUpToNextPowerOfTwo(sum);
}