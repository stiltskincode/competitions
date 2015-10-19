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


map<char, char> m = 
{
	{ '(', ' ' },
	{ '[', ' ' },
	{ '{', ' ' },
	{ ')', '(' },
	{ ']', '[' },
	{ '}', '{' }
};


class BracketExpressions {
public:
	string ifPossible(string);
	bool calc(string, stack<char> s);
};

bool BracketExpressions::calc(string expression, stack<char> s) {
	for (int i = 0; i < expression.size(); ++i){
		if (expression[i] == 'X'){
			string sub = expression.substr(i + 1, expression.size());

			if (calc('(' + sub, s)
				|| calc(')' + sub, s)
				|| calc('[' + sub, s)
				|| calc(']' + sub, s)
				|| calc('{' + sub, s)
				|| calc('}' + sub, s)
				) 
				return true; 
			else return false;
		}
		else{
			if (m[expression[i]] == ' '){
				s.push(expression[i]);
			}
			else{
				if (!s.empty() && m[expression[i]] == s.top() ){
					s.pop();
				}
				else{
					return false;
				}
			}
		}
	}

	return s.empty();
}

string BracketExpressions::ifPossible(string expression) {
	stack<char> s;
	
	bool x = calc(expression, s);

	return x ? "possible" : "impossible";
}

