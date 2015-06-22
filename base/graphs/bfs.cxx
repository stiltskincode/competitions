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


	void Bfs(int s){
		vector<int> qu(g.size()); 
		int  e, b;
		for (int i = 0; i < g.size(); ++i) g[i].t = g[i].s = -1;
		g[s].t = 0;
		qu[b = e = 0] = s;


		while (b <= e){
			s = qu[b++];
			
			for (auto it = g[s].begin(); it != g[s].end(); ++it)
				if (g[it->v].t == -1){
					g[qu[++e] = it->v].t = g[s].t + 1;
					g[it->v].s = s;
			}
		}
	}
};



struct Ve{
	int rev;
};

struct Vs{
	int s, t;
};