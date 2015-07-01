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

	bool EulerD(vector<int> &r){
		int v = -1, kr = 1, h;
		r.clear();
		vector<int> l, st(g.size(), 0);

		FOREACH(it, g){
			FOREACH(it2, *it){
				++st[it2->v];
			}
		}

		REP(x, g.size()){
			if ((h = g[x].size()) > st[x]) v = x;
			else if (h && v == -1) v = x;
			kr += st[x] = h;
		}

		if (v != -1) l.push_back(v);

		while (l.size())
		{ 
			if (!st[v = l.back()]){
				l.pop_back();
				r.push_back(v);
			}
			else l.push_back(v = g[v][--st[v]].v);
		}

		reverse(r.begin(), r.end());
		return r.size() == kr;
	}
};

struct V{
	int d, v;

};

struct E{
	int rev; int r;
	int dcc; int bridge;
};