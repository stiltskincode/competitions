#include <vector>

using namespace std;

namespace PermMInTr{
	vector<int> *v;

	void(*fun)(vector<int>&);

	void perm(int m){
		if (m == 1) fun(*v);
		else{
			for (int i = 0; i < m; ++i){
				perm(m - 1);
				if (i < m - 1)  swap((*v)[(!(m & 1) && m > 2) ? 
					(i < m - 1) ? i : m - 3 : m - 2], (*v)[m - 1]);
				
			}
		}
	}

	void gen(vector<int>& vi, void(*f)(vector<int>&)){
		v = &vi;
		fun = f;
		perm(v->size() - 1);
	}
}
