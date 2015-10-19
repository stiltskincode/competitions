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


char alphaber[17] = {'O', 'I', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'A', 'B', 'C', 'D', 'E', 'F' };
class Hexspeak {
public:
	string decode(long long);
};

string Hexspeak::decode(long long ciphertext) {
	string s;
	while (ciphertext){
		int x = ciphertext % 16;
		if ((x >= 0 && x < 2) || (x > 9 && x < 17)){
			s += alphaber[x];
			ciphertext /= 16;
		}
		else{
			return "Error!";
		}
		
	}
	 std::reverse(s.begin(), s.end());
	 return s;
}