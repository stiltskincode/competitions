#include <vector>
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
		Ed eg(d, e);// eg.r = b;
		eg.rev = SIZE(g[e]) + (b == e);
		g[b].PB(eg);
		eg.rev = SIZE(g[eg.v = b]) - 1;// eg.r = e;
		g[e].PB(eg);
	}


	int s;
	VPII *X;

	void Bridges(VPII &res){
		res.clear();
		X = &res;
		s = 0;
		
		FOREACH(it, g) it->d = -1;
		REP(i, g.size()) if (g[i].d == -1) 
			BriSearch(i, -1);
	}

	void BriSearch(int v, int u){
		g[v].d = g[v].low = s++;
		FOREACH(it, g[v]){
			int w = it->v;
			if (g[w].d == -1){
				BriSearch(w, v);
				if (g[w].low > g[v].d){
					X->push_back(MP(min(v, w), max(v, w)));
				}
				else g[v].low = min(g[v].low, g[w].low);
			}
			else if (w != u) g[v].low = min(g[v].low, g[w].d);
		}
	}

};

struct V{
	int d, low;
};

struct E{
	int rev;// r;
	int dcc, bridge;
};