/*
ID: machops1
LANG: C++11
TASK: ride 
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

#define Sh 64

int main(){
	ofstream fout("ride.out");
	ifstream fin("ride.in");

	string c, g;
	fin >> c >> g;
	int a = 1, b = 1, i;

	for (i = 0; i < c.size(); ++i){
		a *= ((int)c[i] - Sh);
	}
	for (i = 0; i < g.size(); ++i){
		b *= ((int)g[i] - Sh);
	}

	fout << ((a % 47 == b % 47) ? "GO" : "STAY") << "\n";

	return (0);
}