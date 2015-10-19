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

vector< int > sti(const string  &a) {
	vector< int > oot;
	for (int i = 0; i < a.size(); i++) {
		if (a[i] != ' ')
			oot.push_back(a[i] - '0');
	}
	return oot;
}

class AvoidRoads {
public:
	long long numWays(int, int, vector <string>);
};

long long AvoidRoads::numWays(int width, int height, vector <string> bad) {
	vector < vector<long long>> arr(width + 2, vector<long long>(height + 2, 0));

	arr[0][0] = 1;

	set < pair<pair<int, int>, pair<int, int>>> nt;

	for (int i = 0; i < bad.size(); ++i){
		vector<int> b = sti(bad[i]); 
		nt.insert(make_pair(make_pair(b[0], b[1]), make_pair(b[2], b[3])));
		nt.insert(make_pair(make_pair(b[2], b[3]), make_pair(b[0], b[1])));
	}
	for (int i = 0; i <= width; ++i){
		for (int j = 0; j <= height; ++j){
			
			int cnt = 0;

			if (!nt.count(make_pair(make_pair(i, j), make_pair(i + 1, j)))){
				arr[i + 1][j] += arr[i][j];
			}

			if (!nt.count(make_pair(make_pair(i, j), make_pair(i, j + 1)))){
				arr[i][j + 1] += arr[i][j];
			}
		}
	}

	return arr[width][height];
}

