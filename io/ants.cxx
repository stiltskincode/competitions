#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <cstdio>
#include <iostream>
#include <vector>


using namespace std;



struct Ant{
	int v; // vertex
	bool m; //can move?
	int sum = 0;
};

struct Edge{
	int v;
};

struct Vertex : vector<Edge>{
	int s = -1;
	int t;
	struct Ant* ant = 0;
};


struct Graph{
	vector<Vertex> g;
	Graph(int n = 0) : g(n){}
};


struct Graph* createGraph(int n){
	struct Graph* graph = new Graph(n + 1);

	int a, b;
	for (int v = 0; v < n - 1; ++v){
		cin >> a >> b;

		Edge edge;
		edge.v = b;
		graph->g[a].push_back(edge);
		edge.v = a;
		graph->g[b].push_back(edge);
	}

	return graph;
}


vector<Ant*>* createAnts(struct Graph* graph, int k){
	
	vector<Ant*>* ants = new vector<Ant*>();

	int p;
	for (int i = 0; i < k; ++i){
		cin >> p;
		Ant* a = new Ant();
		a->v = p;
		graph->g[p].ant = a;
		ants->push_back(a);
	}
	return ants;
}

void Bfs(struct Graph* graph, vector<bool> vis, int s, int n){
	vector<int> st(n + 1);
	int b = 0, e = 0;

	st[b] = s;
	graph->g[s].t = 0;

	while (b <= e){
		int v = st[b++];
		vis[v] = 1;
		//if(graph->g[v].ant != 0) graph->g[v].t = -1;

		for (auto it = graph->g[v].begin(); it != graph->g[v].end(); ++it){
			if (!vis[it->v]){
				st[++e] = it->v;
				graph->g[it->v].s = v;

				bool cm = (graph->g[v].ant != 0 || graph->g[v].t == -1);

				graph->g[it->v].t =  cm ? -1 : graph->g[v].t + 1; // tutaj sprawdz czy w parencie jest mrowka lub byla po drodze gdzies jezeli tak to czas ustaw na -1
				if (graph->g[it->v].ant != 0) graph->g[it->v].ant->m = !cm; // tutaj ustaw mrowke na to czy moze sie ruszyc jezeli jest mrowka
			}
		}
	}
}

bool canMove(struct Graph* graph, int v, int s){
	if (v != s){

		v = graph->g[v].s;

		while (v != -1){
			if (graph->g[v].ant != 0) return false;
			v = graph->g[v].s;
		}
	}

	return true;
}

void move(struct Graph* graph, struct Ant* a, int s){
	//zmien miejscami mrowke 
	if (a->v != s){
		int _edge = a->v;
		a->v = graph->g[_edge].s;
		graph->g[a->v].ant = graph->g[_edge].ant;
		graph->g[_edge].ant = 0;
	}
}


int main(){
	freopen("input.in", "r", stdin);
	freopen("output.out", "w+", stdout);
	
	int n; //V and E 
	int k;//ants 
	int l;//ladybugs
	int s;//ladybug
	bool f;//finded

	cin >> n;
	Graph* graph = createGraph(n);

	cin >> k;
	vector<Ant*>* ants = createAnts(graph, k);

	vector<bool> vis(n + 1, 0);

	cin >> l;
	for (int i = 0; i < l; ++i){
		cin >> s;
		graph->g[s].s = -1;
		Bfs(graph, vis, s, n); // wyznacz drogi chyba ze stoi mrowka to wyznacz na -1
		f = false;

		while (!f){ // do puki nie znaleziono biedronki
			for (auto  a = ants->begin(); a != ants->end(); ++a){ //dla kazdej mrowki
				//sprawdz czy moze sie ruszyc
				if ((*a)->m && canMove(graph, (*a)->v, s)){
					//rusz ja o jeden
					move(graph, (*a), s);
					//jezeli znalazla biedronke:
					if ((*a)->v == s){
						f = true;//oznacz f na true
						(*a)->sum++;//dodaj jej ilosc o jeden
						//break;//break z petli? wlasnie tego nie wiem 
					}
				}
			}
		}
	}

	for (auto a = ants->begin(); a != ants->end(); ++a){
		cout << (*a)->v << " " << (*a)->sum << endl;
	}
	return 0;
}