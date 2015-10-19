#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

class HappyLetterDiv2 {
public:
	char getHappyLetter(string);
};

char HappyLetterDiv2::getHappyLetter(string letters) {
	int n = (int)'z';

	vector<int> k(n + 1, 0);
	char letter = '.';
	int cnt = 0;

	int p = letters.size() / 2 + 1;
	for (int i = 0; i <  letters.size(); ++i){
		k[letters[i]]++;
	}

	for (int i = 'a'; i <= 'z'; ++i){
		if (k[i] > p) p = k[i], letter = i, cnt = 0;
		if (k[i] == p) cnt++;
	}

	return cnt == 1 ? letter : '.';
}