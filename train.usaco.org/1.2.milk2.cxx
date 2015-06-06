/*
ID: machops1
LANG: C++11
TASK: milk2 
*/


#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

int n;


struct point{
	int x;
	int y;
	point(int _x, int _y) : x(_x), y(_y){};
	point() : x(0), y(0){};
};

int main(){
	FILE *fin = fopen("milk2.in", "r");
	FILE *fout = fopen("milk2.out", "w");

	int i, max_m;
	point p;
	vector<point> prs;

	fscanf(fin, "%d", &n);
	for (i = 0; i < n; ++i){
		fscanf(fin, "%d %d", &p.x, &p.y);
		prs.push_back(p);

	}

	sort(prs.begin(), prs.end(), [](point a, point b) -> bool { return a.x < b.x; });

	point work;
	int max_n = prs[0].y - prs[0].x, max_i = 0;

	work.x = prs[0].x;
	work.y = prs[0].y;

	for (i = 1; i < n; ++i){
		max_i = max(prs[i].x - work.y, max_i);
		if (prs[i].x > work.y){
			work.x = prs[i].x;
			work.y = prs[i].y;
		}
		else{
			if (prs[i].y > work.y) work.y = prs[i].y;
		}

		max_n = max(max_n, work.y - work.x);
	}

	fprintf(fout,"%d %d\n", max_n, max_i);

	return (0);
}