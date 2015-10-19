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



class SquareScoresDiv2{
public:
	int getscore(string s){
		vector<long long> f(101, 0);

		for (int i = 1; i <= 100; ++i)
			f[i] = f[i - 1] + i;


		char b = ' ';
		int cnt = 0;
		int total = 0;
		for (int i = 0; i < s.size(); ++i){
			if (b != s[i]){
				total += f[cnt];
				cnt = 1;
				b = s[i];
			}
			else{
				cnt++;
			}
		}

		total += f[cnt];
	
		return total;
	}
};
