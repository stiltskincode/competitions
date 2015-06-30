#include <vector>
#include <iostream>
#include <deque>
#include <algorithm> 


using namespace std;

#define VAR(v, n) auto v = (n)
#define FOREACH(i, c) for(VAR(i, (c).begin()); i != (c).end(); ++i)
#define SIZE(x) ((int)(x).size())
#define PB push_back
#define REP(x, n) for(int x = 0; x < (n); ++x)
typedef pair<int, int> PII;
typedef vector<PII> VPII;
#define MP make_pair
#define ST first
#define ND second

template<class V, class E> struct Graph{
	struct Ed : E {
	 int v;
	 Ed(E p, int w) : E(p), v(w) { }
		
	};
	struct Ve : V, vector<Ed> { };
	vector<Ve> g;

	Graph(int n = 0) : g(n) { }

	void EdgeD(int b, int e, E d = E()) {
		g[b].PB(Ed(d, e));
	}

	void EdgeU(int b, int e, E d = E()) {
		Ed eg(d, e); 
		eg.rev = SIZE(g[e]) + (b == e);
		g[b].PB(eg);
		eg.rev = SIZE(g[eg.v = b]) - 1;
		g[e].PB(eg);
	}

	int id, l;
	typedef typename vector<Ed>::iterator EIT;
	vector<EIT> qu;

#define DccMark(bri) e->dcc = g[e->v][e->rev].dcc = id, \
	e->bridge = g[e->v][e ->rev].bridge = bri;

	void Dcc(){
		id = l = 0;
		qu.clear();
		FOREACH(it, g) it->d = -1;
		REP(i, g.size()) if (g[i].d == -1) 
			DccSearch(i, -1);

	}

	void DccSearch(int v, int u){
		EIT e;
		g[v].d = g[v].low = l++;
		FOREACH(it, g[v]){
			int w = it->v;
			if (g[w].d == -1){
				qu.push_back(it);
				DccSearch(w, v);

				if (g[w].low >= g[v].d){
					int cnt = 0;
					do{
						e = qu.back();
						DccMark(0);
						qu.pop_back();
						cnt++;
					} while (e->r == it->r && e->v == it->v);
					if (cnt == 1) DccMark(1);
					id++;
				}
				else g[v].low == min(g[v].low, g[w].low);
			}
			else if (g[w].d < g[v].d && w != u)
				qu.push_back(it), g[v].low = min(g[v].low, g[w].d);
		}
	}
	

};

struct V{
	int d, low;

};

struct E{
	int rev; int r;
	int dcc; int bridge;
};