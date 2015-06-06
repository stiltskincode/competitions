#define _CRT_SECURE_NO_DEPRECATE
#pragma warning (disable : 4996)
#pragma optimize( "", off )

#include <stdio.h>
#include "stdafx.h"
#include <vector>
#include <iostream>
#include <string>
#include <iomanip> 
#include <map>
#include <algorithm>

using namespace std;

#define max(a,b) a>b ? a : b
#define min(a,b) a<b ? a : b
#define MAX_N 8
#define INF 1000000001
#define SIZE(x) ((x).size())
#define pb push_back
#define VAR(v, n) auto v = (n)
#define ALL(c) (c).begin(), (c).end()
#define REP(x, n) for(int x = 0; x < (n); ++x)
#define FOR(x, b, e) for(int x = b; x <= (e); ++x)
#define FORD(x, b, e) for(int x = b; x >= (e); --x)
#define FOREACH(i, c) for(VAR(i, (c).begin()); i != (c).end(); ++i)

//std::copy(ALL(A), std::ostream_iterator<std::string>(std::cout, ", "));

typedef vector<int> VI;
typedef vector<VI> VVI;


int N;
int n;
double MIN = INF;


struct point
{
	int x;
	int y;
	point(int _x, int _y) : x(_x), y(_y){}
	point() : point(0, 0){}
};

void SWAP(int &a, int &b){
	int tmp = a;
	a = b;
	b = tmp;
}

void reverse(VI &P){
	int l = 0, r = P.size() - 1;
	while (l < r){
		SWAP(P[l++], P[r--]);
	}
}

double dist(point a, point b){
	int x_max = max(a.x, b.x);
	int x_min = min(a.x, b.x);

	int y_max = max(a.y, b.y);
	int y_min = min(a.y, b.y);


	return sqrt((x_max - x_min)*(x_max - x_min) + (y_max - y_min)*(y_max - y_min));
}


bool compfunct(string str1, string  str2) { 
	
	int s1 = str1.size(), s2 = str2.size();

	if (s1 == s2) return str1 > str2;
	return s1 < s2;

}

 namespace PermAntyLex {
	VI *V;
	int T;
	int S;
	VI *P;
	VI *PR;


	vector<string> *A;
	void(*fun) (VI &, vector<string> &, int, VI & , VI &);
	 void Perm(int m) {
		 if (!m) fun(*V, *A, T, *P, *PR);
		 else FOR(i, 0, m) {
			 Perm(m - 1);
			 if (i < m) {
				 SWAP((*V)[i], (*V)[m]);
				 reverse(&(*V)[0], &(*V)[m]);
			}
		}
	}
	 void Gen(vector<string> & v, int t, VI & PROCH,  void(*f) (VI &, vector<string> &, int t, VI &, VI &)) {
		 A = &v;
		 fun = f;
		 T = t;
		 P = &PROCH;
		 PR = new VI(1 << 16, 0);

		 S = SIZE(v);
		 VI k(S);
		 REP(i, S) k[i] = i;
		 
		 V = &k;
		 Perm(S - 1);
	}
};

 void onGen(VI & v, vector<string> & A, int t, VI & P, VI & PR) {
	 string str;
	 int x = 0;
	 FORD(i, SIZE(v) - 1, SIZE(v) - t + 1){
		 int dd = (1 << v[i]) | (1 << v[i - 1]);
		 if (P[dd]) return;

		 x |= (1 << v[i]);
		 str += A[v[i]] + " ";
	 }

	 str += A[v[SIZE(v) - t]];
	 x |= (1 << v[SIZE(v) - t]);
	 if (PR[x]) return;
	 PR[x] = 1;
	 cout << str << endl;
 }

int _tmain(int argc, _TCHAR* argv[])
{
	freopen("output.txt", "w", stdout);
	freopen("input.txt", "r", stdin);

	
	cin >> N;
	
	REP(k, N){
		string s;
		int t, p;
		

		cin >> n >> p >> t;
		vector<string> A(n);
		map<string, int> AM;

		VI PROCH(1 << 16, 0);
		REP(i,n){
			cin >> s;
			transform(s.begin(), s.end(), s.begin(), toupper);
			A[i] = s;
			//AM[s] = i;
		}

		sort(ALL(A), compfunct);

		REP(i, n){
			AM[A[i]] = i;
		}

		REP(i, p){
			string str1, str2;
			cin >> str1 >> str2;

			int x1, x2;
			x1 = AM[str1]; x2 = AM[str2];

			PROCH[(1 << x1)|(1 << x2)] = 1;
		}

		

		cout << "Set " << k + 1 << ":" << endl;
		PermAntyLex::Gen(A, t, PROCH, &onGen);
		cout << endl;
	}
	return 0;
}

