/*
ID: machops1
LANG: C++11
TASK: beads 
*/

#include <stdio.h>
#include <algorithm>

using namespace std;

int n;
char B[350];
int MAX = 0;
#define RC ' '

int main(){
	FILE *fin = fopen("beads.in", "r");
	FILE *fout = fopen("beads.out", "w");

	fscanf(fin, "%d", &n);
	fscanf(fin, "%s", B);

	int i, size_l = 0, size_r = 1, 
		size_tmp =  0;

	char tmp = RC, l = B[0], r;

	for (i = 1; i < (n*2); ++i){
		r = B[(i%n)];

		if (l == r){
			size_r++;
			if (r == 'w') size_tmp++;
			MAX = max(size_l + size_r, MAX);
		}
		else{
			if (r == tmp){
				size_r++;
				size_tmp = 0;
				tmp = RC;
				MAX = max(size_l + size_r, MAX);
			} 
			else if (r == 'w'){
				size_r++; size_tmp++; tmp = l;
			}
			else if (r == 'w'){
				size_r++; size_tmp++; tmp = l;
				MAX = max(size_l + size_r, MAX);
			}
			else if (l == 'w'){
				MAX = max(size_l + size_r, MAX);
				tmp = r;
				size_l = size_r - size_tmp;
				size_r = ++size_tmp;
				size_tmp = 0;
				tmp = RC;
			}
			else{
				MAX = max(size_l + size_r, MAX);
				size_l = size_r - size_tmp;
				size_r = 1 + size_tmp;
				size_tmp = 0;
				tmp = RC;
			}
		}
		
		l = r;
	}

	fprintf(fout, "%d\n", MAX > n ? n : MAX);

	return (0);
}