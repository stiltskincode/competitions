#include <vector>

using namespace std;

namespace PermAntyLex{
	vector<int> *v;

	void(*fun)(vector<int>&);

	void perm(int m){
		if (!m) fun(*v);
		else{
			for (int i = 0; i < m; ++i){
				perm(m - 1);
				if (i < m){
					swap((*v)[i], (*v)[m]);
					reverse(&(*v)[0], &(*v)[m]);
				}
			}
		}
	}

	void gen(vector<int>& vi, void(*f)(vector<int>&)){
		v = &vi;
		fun = f;
		perm(v->size() - 1);
	}
}
