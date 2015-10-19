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

class LongWordsDiv2 {
public:
	string find(string);
};

string LongWordsDiv2::find(string word) {
	int s = word.size();
	if (s == 1) return "Likes";
	else if (s == 2) {
		if (word[0] == word[1]) return "Dislikes";
	}
	else if (s == 3){
		if (word[0] == word[1] || word[1] == word[2])
			return "Dislikes";
	}
	else{
		for (int i = 0; i < s - 3; ++i){
			for (int j = i + 1; j < s - 2; ++j){
				if (i + 1 == j)
					if (word[i] == word[j]) return "Dislikes";

				for (int n = j + 1; n < s - 1; ++n){
					for (int m = n + 1; m < s; ++m){
						if (word[i] == word[n] && word[j] == word[m])
							return "Dislikes";
					}
				}
			}
		}
	}
	return "Likes";
}