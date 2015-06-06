/*
ID: machops1
LANG: C++11
TASK: gift1 
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <math.h>

using namespace std;

int n;

map<string, int> _map;
vector<string> _vect;

int main(){
	ofstream  fout("gift1.out");
	ifstream  fin("gift1.in");

	int i, e, k, c, r;
	string key, p;

	fin >> n;

	_vect.resize(n);

	for (i = 0; i < n; ++i){
		fin >> key;
		_map[key] = 0;
		_vect[i] = key;
	}

	while (fin >> p){
		fin >> e >> k;
		if (e != 0 && k != 0) {

			r = e%k;
			c = floor(e / (double)k);
			_map[p] -= (e - r);

			for (i = 0; i < k; ++i){
				fin >> p;
				_map[p] += c;
			}
		}
	}

	for (i = 0; i < n; ++i){
		fout << _vect[i] << " " << _map[_vect[i]] << "\n";
	}
	return (0);
}