#include <vector>

using namespace std;

#define REP(x, n) for(int x = 0; x < (n); ++x)
#define FORD(x, b, e) for(int x = b; x >= (e); --x)

void Display(vector<int> & v) {
 static int calc = 0;
	 if (!(++calc % 6)) cout << "\n";
	 for (auto it = v.begin(); it != v.end(); ++it)
	 cout << *it << " ";
	 cout << "\t";
	
}

 void SubsetKLex(int k, int n, void(*fun) (vector<int> &)) {
	 int i, p = k;
	 vector<int> A(k);
	 REP(x, k) A[x] = x;
	 while (p) {
		 fun(A);
		 A[k - 1] == n - 1 ? p-- : p = k;
		 if (p) FORD(i, k, p) A[i - 1] = A[p - 1] + i - p + 1;
	}
}