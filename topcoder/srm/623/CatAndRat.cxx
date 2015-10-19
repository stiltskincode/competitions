#define _USE_MATH_DEFINES

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

class CatAndRat {
public:
	double getTime(int, int, int, int);
};

double CatAndRat::getTime(int R, int T, int Vrat, int Vcat) {
	if (Vcat <= Vrat) return -1;

	double rat = Vrat * T;
	if (rat > R* M_PI) rat = R*M_PI;

	return rat / abs(Vcat - Vrat);
}