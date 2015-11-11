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

#define MX 1048576

int dp[MX];
int n = 0;

bool _canMove(int x, int flag){
	if (x&flag && !(x&(flag << 1))){
		return true;
	}
	return false;
}

int _move(int x, int flag){
	x ^= flag;
	x ^= (flag << 1);
	return x;
}

bool _canJump(int x, int flag){
	if (flag < (1 << (n - 3)) && x&flag && x&(flag << 1) && x&(flag << 2) && !(x&(flag << 3))){
		return true;
	}

	return false;
}

int _jump(int x, int flag){
	x ^= flag;
	x ^= (flag << 3);
	return x;
}

int _remlast(int x){
	if (x&(1 << (n - 1))){
		x ^= (1 << (n - 1));
	}


	return x;
}



class EllysCheckers {
public:
	string getWinner(string);
	int calc(int x){

		if (dp[x] != -1) return dp[x];

		bool f = false; // czy moze wybrac ruch

		bool f2 = false, f3 = false;
		for (int flag = 1; flag < (1 << n); flag <<= 1){
			if (x&flag){
				if (_canMove(x, flag)){
					f = true;

					int xx = _move(x, flag);
					xx = _remlast(xx);

					bool ff = false;
					for (int flag2 = 1; flag2 < (1 << n); flag2 <<= 1){
						if (_canMove(xx, flag2)){
							ff = true;
							f2 = true;
							int xxx = _move(xx, flag2);
							xxx = _remlast(xxx);
							dp[xxx] = calc(xxx);
							if (dp[xxx]) return 1;
							
						}

						if (_canJump(xx, flag)){
							ff = true;
							f2 = true;
							int xxx = _jump(xx, flag2);
							xxx = _remlast(xxx);
							dp[xxx] = calc(xxx);
							if (dp[xxx]) return 1;
						}
					}
				}

				if (_canJump(x, flag)){
					f = true;

					int xx = _jump(x, flag);
					xx = _remlast(xx);

					bool ff = false;

					for (int flag2 = 1; flag2 < (1 << n); flag2 <<= 1){
						if (_canMove(xx, flag2)){
							ff = true;
							f3 = true;
							int xxx = _move(xx, flag2);
							xxx = _remlast(xxx);
							dp[xxx] = calc(xxx);
							if (dp[xxx]) return 1;

						}

						if (_canJump(xx, flag)){
							ff = true;
							f3 = true;
							int xxx = _jump(xx, flag2);
							xxx = _remlast(xxx);
							dp[xxx] = calc(xxx);
							if (dp[xxx]) return 1;
						}
					}
				}
			}
		}

		return f ? ((f2 || f3) ? 0 : 1) : 0;
	}
};

string EllysCheckers::getWinner(string board) {

	for (int i = 0; i < MX; ++i) dp[i] = -1;
    n = board.size();

	int k = 0;
	for (int i = 0; i < n; ++i){
		if (board[i] == 'o'){
			k ^= (1 << i);
		}
	}

	k = _remlast(k);


	dp[k] = calc(k);
	

	return dp[k] ?  "YES" : "NO";
}
