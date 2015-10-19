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


class BichromeBoard{
public: 
	string ableToDraw(vector<string> board);
};


string BichromeBoard::ableToDraw(vector<string> board){
	int i = 0, j = 0;
	int y = board.size();
	int x = board[0].size();

	int n = x*y;

	char last = '?';
	for (i = 0; i < n; ++i){
		if (board[i / y][i%x] != '?'){
			last = board[i / y][i%x];
			break;
		}
	}

	last = 'B';
	for (int j = i + 1; j < n; ++j){
		if (board[j / y][j%x] == '?'){
			last = last == 'B' ? 'W' : 'B';
			board[j / y][j%x] = last;
		}
		else{
			if (last == board[j / y][j%x]){
				return "Inpossible";
			}
			else{
				last = board[j / y][j%x];
			}
		}
	}

	for (int j = 0; j < i + 1; ++j){
		if (board[j / y][j%x] == '?'){
			last = last == 'B' ? 'W' : 'B';
			board[j / y][j%x] = last;
		}
		else{
			if (last == board[j / y][j%x]){
				return "Inpossible";
			}
			else{
				last = board[j / y][j%x];
			}
		}
	
	}
	return "Possible";
}

