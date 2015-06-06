// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#define _CRT_SECURE_NO_DEPRECATE
#pragma warning (disable : 4996)
#include <stdio.h>
#include "stdafx.h"
#include <vector>
#include <iostream>
#include <string>

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

double MIN;

struct point {
	int x;
	int y;

	point() : point(0, 0){}

	point(int _x, int _y) {
		x = _x;
		y = _y;
	};
};

double dis(point a, point b){
	int max_x = max(a.x, b.x);
	int min_x = min(a.x, b.x);

	int max_y = max(a.y, b.y);
	int min_y = min(a.y, b.y);

	return  sqrt(((max_x - min_x)*(max_x - min_x)) + ((max_y - min_y)*(max_y - min_y)));
};


void PermMinTrAdj(VI & p, vector<point> &vp, void(*fun) (VI &, vector<point> &)) {
	int x, k, i = 0, s = SIZE(p);
	VI c(s, 1);
	vector<bool> pr(s, 1);
	c[s - 1] = 0;
	fun(p, vp);
	while (i < s - 1) {
		i = x = 0;
		while (c[i] == s - i) {
			if (pr[i] = !pr[i]) x++;
			c[i++] = 1;

		}
		if (i < s - 1) {
			k = pr[i] ? c[i] + x : s - i - c[i] + x;
			swap(p[k - 1], p[k]);
			fun(p, vp);
			c[i]++;
		}
	}
}

void Display(VI & v, vector<point> & vp) {
	double _min = 0;
	for (int i = 0; i < SIZE(v); i += 2){
		_min += dis(vp[v[i]], vp[v[i + 1]]);
	}
	MIN = MIN > _min ? _min : MIN;
}

int _tmain(int argc, _TCHAR* argv[])
{
	freopen("output.txt", "w", stdout);
	freopen("input.txt", "r", stdin);

	int n, x, y;
	string name;
	point _poi;
	cin >> n;
	while (n){
		MIN = INF;
		VI p;
		vector<point> A((n*2) + 1, point(0,0));
		FOR(x, 1, 2 * n) {
			p.pb(x);
			cin >> name >> A[x].x >> A[x].y;
		}

		PermMinTrAdj(p,A, Display);
		cout << MIN << endl;
		cin >> n;
		
	}
	return 0;
}

