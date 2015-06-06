#include <vector>

using namespace std;

int sgn(vector<int> p){
	int n = p.size();
	int i,j, s = 1;
	vector<bool> NEW(n, true);

	for (i = 0; i < n; ++i){
		if (NEW[i]){
			j = p[i];
			while (j != i){
				NEW[j] = false;
				s = -s;
				j = p[j];
			}
		}
	}

	return s;
}
