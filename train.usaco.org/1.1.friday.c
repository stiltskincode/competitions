/*
ID: machops1
LANG: C++11
TASK: friday 
*/

#include <stdio.h>

using namespace std;

int n;
int d[7];



int main(){
	FILE *fin = fopen("friday.in", "r");
	FILE *fout = fopen("friday.out", "w");

	int days[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	fscanf(fin, "%d", &n);

	int i ,leap = 0, y=1900, x, xx = 0, dd = 0, m = 0;

	for (i = 1; i <= (12 * n);  ++i){
		leap = m == 1 && (!(y % 100) ? !(y % 400) : !(y % 4));
		x = days[m] + leap;

		
		dd = (xx + 13) % 7;
		d[dd]++;

		xx = ((x + xx) %7);

		m = ++m % 12;
		y += !(i % 12);

	}

	fprintf(fout, "%d", d[6]);
	for (i = 0; i < 6; ++i){
		fprintf(fout, " %d", d[i]);
	}
	
	fprintf(fout, "\n");
	return (0);
}