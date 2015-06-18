#include <vector>
using namespace std;

template<class V, class E> struct Graph{
	struct Ed : E{
		int v;
		Ed(E p, int w) : E(p), v(w){}
	};

	struct Ve : V, vector <Ed> {};

	vector<Ve> g;
	Graph(int n = 0) : g(n){}

	void EdgeD(int b, int e, E d = E()){
		g[b].push_back(Ed(d, e));
	}

	void EdgeU(int b, int e, E d = E()){
		Ed eg(d, e);
		ed.rev = g[e].size() + (b == e);
		g[b].push_back(ed);
		ed.rev = g[ed.v = b].size() - 1;
		g[e].push_back(ed);
	}
};