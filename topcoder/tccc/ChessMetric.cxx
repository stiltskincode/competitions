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

#define MOVES 16
int movesxx[MOVES] = { -1, 1, -2, -1, 0, 1, 2, -1, 1, -2, -1, 0, 1, 2, -1, 1 };
int movesyy[MOVES] = { 2, 2, 1, 1, 1, 1, 1, 0, 0, -1, -1, -1, -1, -1, -2, -2 };

class ChessMetric {
public:
	long long howMany(int, vector <int>, vector <int>, int);
};

long long ChessMetric::howMany(int size, vector <int> start, vector <int> end, int numMoves) {
	vector<vector<long long >> v(size + 1, vector<long long>(size + 1, 0));
	vector<vector<long long>> nv(size + 1, vector<long long>(size + 1, 0));

	v[start[0]][start[1]] = 1;


	for (int m = 0; m < numMoves; ++m){
		for (int x = 0; x < size; ++x){
			for (int y = 0; y < size; ++y){
				for (int move = 0; move < MOVES; ++move){
					int nx = x + movesxx[move];
					int ny = y + movesyy[move];

					if (nx >= 0 && nx <= size && ny >= 0 && ny <= size){
						nv[nx][ny] += v[x][y];
					}
				}
			}
		}

		v = nv;
		fill(nv.begin(), nv.end(), vector<long long>(size + 1, 0));
	}

	
	return v[end[0]][end[1]];
}