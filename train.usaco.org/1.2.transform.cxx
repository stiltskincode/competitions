/*
ID: machops1
LANG: C++11
TASK: transform 
*/


#define _CRT_SECURE_NO_DEPRECATE
#pragma warning (disable : 4996)
#pragma optimize( "", off )


#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

int n;

vector<char> orig(121);
vector<char> trans(121);

bool rot90(){
	int k = 0;
	//7 8 9 
	for (int i = n - 1; i >= 0; --i)
	for (int j = n; j > 0; --j){
		if (trans[k++] != orig[(n*j - i) - 1]) return false;
	}
	return true;
}

bool rot180(){
	for (int i = 0; i < n*n; ++i){
		if (trans[i] != orig[(n*n - i) - 1]) return false;
	}
	return true;
}

bool rot270(){
	int k = 0;
	for (int i = 0; i < n; ++i){
		for (int j = 1; i <= n; ++j){
			if (trans[k++] != orig[j*n - i]) return false;
		}
	}
	return true;
}




void combine(){
	int l, r;
	for (int i = 0; i < n; ++i){
		l = i*n; r = (i* n) + n-1;
		while (l <= r){
			char tmp = orig[l];
			orig[l] = orig[r];
			orig[r] = tmp;
			l++; r--;
		}
	}
}

bool Nochange(){
	for (int i = 0; i < n*n; ++i){
		if (trans[i] != orig[i]) return false;
	}
	return true;
}

int main(){
	FILE *fin = fopen("transform.in", "r");
	FILE *fout = fopen("transform.out", "w");

	int i;

	fscanf(fin, "%d", &n);



	for(i = 0; i < n; ++i){
		fscanf(fin, "%s", &orig[i*n]);
	}

	for (i = 0; i < n; ++i){
		fscanf(fin, "%s", &trans[i*n]);
	}

	if (rot90()){
		fprintf(fout, "%d\n", 1);
	} else if (rot180()){
		fprintf(fout, "%d\n", 2);
	}
	else if (rot270()){
		fprintf(fout, "%d\n", 3);
	}
	else if (Nochange()){
		fprintf(fout, "%d\n", 6);
	}
	else{
		combine();
		if (Nochange()){
			fprintf(fout, "%d\n", 4);
		}
		else if (rot90() || rot180() || rot270()){
			fprintf(fout, "%d\n", 5);
		}
		else{
			fprintf(fout, "%d\n", 7);
		}
	}
	return (0);
}