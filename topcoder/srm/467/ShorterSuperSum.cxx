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

int arr[15][15];

class ShorterSuperSum {
public:
	int calculate(int, int);
};

int ShorterSuperSum::calculate(int K, int N) {
	memset(arr, 0, sizeof(arr));

	for (int i = 0; i < N + 1; ++i) arr[0][i] = i;

	for (int k = 1; k <= K; ++k){
		int s = 0;
		for (int n = 1; n <= N; ++n){
			s += arr[k - 1][n];
			arr[k][n] = s;
		}
	}

	return arr[K][N];
}