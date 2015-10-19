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

class PathGameDiv2 {
public:
	int calc(vector <string>);
	int cntLvl(vector <string>& board, int lvl, int n){
		int s = 0;
		
		int i = 0;

		do{
			if (board[lvl][i] == '#'){
				lvl = !lvl;
			}
			else{
				++i;
			}
			++s;
		} while (i<n);

		return s;
	}

};

int PathGameDiv2::calc(vector <string> board) {
	int n = board[0].size();

	int c = min(cntLvl(board, 0, n), cntLvl(board, 1, n));

	int b = 0;

	for (int i = 0; i < n; ++i){
		if (board[0][i] == '#')b++;
		if (board[1][i] == '#')b++;
	}

	return (n*2) - c - b;
}
