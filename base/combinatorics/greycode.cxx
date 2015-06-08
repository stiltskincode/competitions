#include <vector>
using namespace std;

void greycode(int n, void(*fun)(vector<bool>&, int)){
	vector<bool> B(n, 0);
	fun(B, -1);

	for (int i = 0, p = 0, j; p < n;){
		for (p = 0, j = ++i; j & 1; p++) j >>= 1;
		if (p < n){
			B[p] = !B[p];
			fun(B, p);
		}
	}
}