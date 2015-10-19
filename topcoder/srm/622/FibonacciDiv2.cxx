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

int  memo[0x7FFF];

class FibonacciDiv2 {
public:
	int find(int);
};

int FibonacciDiv2::find(int N) {
	memo[1] = memo[2] = 1;

	int s = 0;

	int i = 2;
	while (s < N){
		i++;
		s = memo[i - 1] + memo[i - 2];
		memo[i] = s;
		
	}

	return min(N - memo[i - 1], memo[i] - N);
}
