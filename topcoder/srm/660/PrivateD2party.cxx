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

class PrivateD2party {
public:
	int getsz(vector <int>);
};

int PrivateD2party::getsz(vector <int> a) {

	int n = a.size();
	vector<int> arr(n, 0);

	for (int i = 0; i < n; ++i){
		if (i != a[i])
			arr[a[i]]++;
	}

	int cnt = 0;
	for (int i = 0; i < n; ++i){
		int m11 = 0, m12 = 0;
		bool flag = true;

		for (int j = 0; j < n; ++j){
			if (m11 < arr[j]){
				m11 = a[j]; m12 = j;
			}
			if (arr[j] == 0){

				arr[j] = -1;
				arr[a[j]]--;
				cnt++;
				flag = false;
			}
		}
		if (flag){
			arr[m12] = -1;
			arr[m11]--;

		}
	}

	return cnt;
}