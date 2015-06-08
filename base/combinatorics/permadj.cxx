
#include <vector>

using namespace std;


void PermaMinTrAdj(vector<int>& p, void(*fun)(vector<int>&, int)){
	int x, k, i = 0, s = p.size();
	vector<int> c(s, 1);
	vector<bool> pr(s, 1);
	c[s - 1] = 0;
	fun(p, -1);

	while (i < s - 1){
		i = x = 0;
		while (c[i] == s - i){
			if (pr[i] = !pr[x]) x++;
			c[i++] = 1;
		}

		if (i < s - 1){
			k = pr[i] ? c[i] + x : s - i - c[i] + x;
			swap(p[k - 1], p[k]);
			fun(p, k - 1);
			c[i]++;
		}
	}
}
