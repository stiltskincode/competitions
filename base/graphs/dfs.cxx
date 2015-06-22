#include <vector>

using namespace std;

template <class V, class E> struct Graph{
	struct Ed : E{
		int v;
		Ed(E d, int w) : E(d), v(w){

		}
	};

	struct Ve : V, vector<Ed>{

	};

	vector<Ve> g;

	Graph(int n = 0) : g(n){}

	void EdgeD(int b, int e, E d = E()){
		g[b].push_back(Ed(d, e));
	}

	void EdgeU(int b, int e, E d = E()){
		Ed eg(d, e);
		eg.rev = g[e].size() + (b == e);
		g[b].push_back(eg);
		eg.rev = g[eg.v = b].size() - 1;
		g[e].push_back(eg);
	}


	void Dfs(int e = -1){
		vector<int> st(g.size());
		int t = -1, b = 0, i = 0;
		for (int s = 0; s < g.size(); ++s) g[s].s = g[s].f = g[s].d = -1;

		e == -1 ? e = g.size() - 1 : b = e;

		for (int s = b; s <= e; ++s) if (g[s].d == -1){
			g[st[i++] = s].d = ++t;
			g[s].f = g[s].size();
			while (i){
				int s = st[i - 1];
				if (!g[s].f){
					g[s].f = ++t;
					--i;
				}
				else{
					if (g[s = g[s][--g[s].f].v].d == -1){
						g[s].s = st[i - 1];
						g[s].f = g[s].size();
						g[st[i++] = s].d = ++t;

					}
				}
			}
		}
	}
};



struct Ve{
	int rev;
};

struct Vs{
	int s, d, f;
};
