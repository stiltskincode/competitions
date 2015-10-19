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

class EightRooks {
public:
	string isCorrect(vector <string>);
};

string EightRooks::isCorrect(vector <string> board) {
	int n = board.size();
	int r = 0;
	vector<int> h(n, 0);
	vector<int> v(n, 0);

	for (int i = 0; i < n; ++i){
		for (int j = 0; j < n; ++j){
			if (board[i][j] == 'R'){
				if ((!h[j] && !v[i])){
					h[j] = v[i] = 1; r++;
				}
				else
				{
					return "Incorrect";
				}
			}
		}
	}
	return r  == n ? "Correct" : "Incorrect";
}