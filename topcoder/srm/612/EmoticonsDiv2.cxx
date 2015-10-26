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
class EmoticonsDiv2 {
public:
	int printSmiles(int);
};

int EmoticonsDiv2::printSmiles(int smiles) {
	vector<int> v(smiles + 1, INF);

	v[0] = 0;
	v[1] = 0;

	
	for (int i = 1; i <= smiles; ++i){
		int steps = v[i] + 1;
		int sum = i;


		while (sum + i <= smiles){
			steps++;
			sum += i;
			v[sum] = steps;
		}
	}

	return v[smiles];

}
