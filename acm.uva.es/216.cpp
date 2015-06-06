// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#define _CRT_SECURE_NO_DEPRECATE
#pragma warning (disable : 4996)
#include <stdio.h>
#include "stdafx.h"
#include <vector>
#include <iostream>
#include <string>
#include <iomanip> 

using namespace std;

#define max(a,b) a>b ? a : b
#define min(a,b) a<b ? a : b
typedef vector<int> VI;

#define MAX_N 8
#define INF 1000000001
#define SIZE(x) ((x).size())

#define pb push_back

#define VAR(v, n) auto v = (n)
#define FOR(x, b, e) for(int x = b; x <= (e); ++x)
#define FOREACH(i, c) for(VAR(i, (c).begin()); i != (c).end(); ++i)

typedef vector<int> vi;
int n;
double MIN = INF;

struct point
{
	int x;
	int y;
	point(int _x, int _y) : x(_x), y(_y){}
};

void SWAP(int &a, int &b){
	int tmp = a;
	a = b;
	b = tmp;
}

void reverse(vi &P){
	int l = 0, r = P.size() - 1;
	while (l < r){
		SWAP(P[l++], P[r--]);
	}
}

vi pmin;

double dist(point a, point b){
	int x_max = max(a.x, b.x);
	int x_min = min(a.x, b.x);

	int y_max = max(a.y, b.y);
	int y_min = min(a.y, b.y);


	return sqrt((x_max - x_min)*(x_max - x_min) + (y_max - y_min)*(y_max - y_min));
}

void checkmin(VI & v, vector<point> &po) {
	double _min = 0;
	for (int i = 0; i < n-1; i++){
		_min += dist(po[v[i]], po[v[i + 1]]);
	}

	if (MIN > _min){
		pmin = v;
		MIN = _min;
	}
}

void PermMinTrAdj(VI & p, vector<point> &po, void(*fun) (VI &, vector<point> &po)) {
	int x, k, i = 0, s = SIZE(p);
	VI c(s, 1);
	vector<bool> pr(s, 1);
	c[s - 1] = 0;

	fun(p, po);

	while (i < s - 1) {
		i = x = 0;
		while (c[i] == s - i) {
			if (pr[i] = !pr[i]) x++;
			c[i++] = 1;
		}

		if (i < s - 1) {
			k = pr[i] ? c[i] + x : s - i - c[i] + x;
			swap(p[k - 1], p[k]);
			fun(p, po);
			c[i]++;
		}

	}

}
int _tmain(int argc, _TCHAR* argv[])
{
	freopen("output.txt", "w", stdout);
	freopen("input.txt", "r", stdin);

	int x, y, k = 0;

	while (1)
	{
		cin >> n; if (!n) return 0;
		k++;
		vi P(n);
		vector<point> Po(n, point(0, 0));		
		pmin = vi(n);


		point _p(0, 0);
		for (int i = 0; i < n; ++i){
			
			P[i] = i;
			cin >> x >> y;

			_p.x = x;
			_p.y = y;
			Po[i] = _p;
		}

		PermMinTrAdj(P, Po, checkmin);

		cout << std::fixed << std::setprecision(2);
		cout << "**********************************************************" << endl;
		cout << "Network #" << k << endl;

		for (int i = 0; i < n -1; ++i){
			cout << "Cable requirement to connect (" << Po[pmin[i]].x << ", " << Po[pmin[i]].y << ") to (" << Po[pmin[i + 1]].x << ", " << Po[pmin[i + 1]].y << ") is " << 16 + dist(Po[pmin[i]], Po[pmin[i + 1]]) << " feet ." << endl;
		}

		cout << "Number of feet of cable required is " << ((16 * (n -1)) + MIN )<< endl;

		MIN = INF;

	}
	return 0;
}

