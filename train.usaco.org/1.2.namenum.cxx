/*
ID: machops1
LANG: C++11
TASK: namenum 
*/


#define _CRT_SECURE_NO_DEPRECATE
#pragma warning (disable : 4996)
#pragma optimize( "", off )


#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm> 

using namespace std;

ofstream fout("namenum.out");
ifstream fin("namenum.in");
ifstream dict("dict.txt");

#define MAX 3

int n;
vector<int> k;
string s, p;
vector<int> digits;
bool f = false;

vector<vector<char>> chars = {
	{ ' ' }, {' '},
	{ 'A', 'B', 'C' },
	{ 'D', 'E', 'F' },
	{ 'G', 'H', 'I' },
	{ 'J', 'K', 'L' },
	{ 'M', 'N', 'O' },
	{ 'P', 'R', 'S' },
	{ 'T', 'U', 'V' },
	{ 'W', 'X', 'Y' }};


inline void processString(string str){
	while (!dict.eof()){
		int cmprd = p.compare(str);
		if (cmprd == 0){
			fout << str << endl;
			f = true;
			break;
		}
		else if (cmprd < 0){
				dict >> p;
		}
		else{
			break;
		}
	}
}

void display(){
	s = "";
	for (int j = 0; j < n; ++j){
		s += chars[digits[j]][k[j] - 1];
	}

	processString(s);
};

void perm(int idx){
	if (idx == n){
		display();
	}
	else{
		for (int j = 1; j <= MAX; ++j){
			k[idx] = j;
			perm(idx + 1);
		}
	}
}

int main(){
	int i;

	fin >> s;
	n = s.length();

	int d = 0;
	for (i = 0; i < n; ++i){
		digits.push_back(s[i] - '0');
	}

	for (i = 0; i < n; ++i)
		k.push_back(0);

	perm(0);

	if (!f) fout << "NONE" << endl;
	return (0);
}