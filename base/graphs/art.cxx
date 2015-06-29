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

	int t;
	VPII *br;

	int BriArtR(int v, int p){
		int l = g[v].d = ++t;
		FOREACH(it, g[v]) if (it->v != p)
			l = min(l, !g[it->v].d ? BriArtR(it->v, v) : g[it->v].d);

		if (g[p].d <= l) g[p].art = 1;
		if (g[p].d < l) br->PB(MP(min(v, p), max(v, p)));

		return l;
	}


	void BriArt(VPII& res){
		res.clear();
		br = &res;

		t = 0;
		REP(x, g.size()) g[x].art = g[x].d = 0;
		REP(x, g.size()) if (!g[x].d){
			g[x].d = ++t;
			int c = 0;
			FOREACH(it, g[x]) if(!g[it->v].d){
				c++;
				BriArtR(it->v, x);
			}
			g[x].art = (c > 1);
		}
	}
	

};

struct V{
	int d, art;
};

struct E{
	int rev;
};