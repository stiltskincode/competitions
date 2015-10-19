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


#define INF 1000000001

pair<int, int> a[10000];

class CatsOnTheLineDiv2 {
public:
	string getAnswer(vector <int>, vector <int>, int);
};

string CatsOnTheLineDiv2::getAnswer(vector <int> position, vector <int> count, int time) {
	int n = position.size();

	//map<int, int> a;
	for (int i = 0; i < n; ++i){
		a[i] = make_pair(position[i], count[i]);
	}

	sort(a, a + n);

	int curr = -INF;

	for (int i = 0; i < n; ++i){
		if (curr < a[i].first - time){
			curr = a[i].first - time + a[i].second - 1;
			if (curr - a[i].first > time) return "Impossible";
		}
		else{
			curr = curr + a[i].second;
			if (curr - a[i].first > time) return "Impossible";
		}
	}
	

	return "Possible";
}
