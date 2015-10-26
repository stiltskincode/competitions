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

bool arr[1000][1000];

class BearPlaysDiv2 {
public:
	string equalPiles(int, int, int);

	bool process(vector<int> D){
		if (D[0] == D[1] && D[1] == D[2]) return true;
		sort(D.begin(), D.end());

		if (arr[D[0]][D[1]]) return false;
		

		
		arr[D[0]][D[1]] = true;

		
		vector<int> d1(D);
		d1[0] *= 2;
		d1[1] -= D[0];
		if (d1[1] >0)
			if (process(d1)) return true;
		
		vector<int> d2(D);
		d2[0] *= 2;
		d2[2] -= D[0];
		if (d2[2] > 0)
			if (process(d2)) return true;
		
		vector<int> d3(D);
		d3[1] *=2;
		d3[2] -= D[1];
		if (d3[2]>0)
		if (process(d3)) return true;
		
		return false;
	}
};

string BearPlaysDiv2::equalPiles(int A, int B, int C) {
	memset(arr, 0, sizeof(arr));

	vector<int> D = { A, B, C };

	return process(D) ? "possible" : "impossible";
	
}