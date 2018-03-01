#include<iostream>
#include<list>
using namespace std;

class graph{
	int V;
	list<int> *adj;
	
	void dfsutil(int v,bool visited[]);
	public:
		graph(int V);
		void add_edge(int v,int w);
		void dfs(int v);
};
graph::graph(int V){
	this->V=V;
	adj = new list<int>[V];
}
void graph::add_edge(int v,int w){
	adj[v].push_back(w);
}
void graph::dfsutil(int v,bool visited[]){
	visited[v]=true;
	cout<<v<<" ";
	list<int>::iterator i;
	for(i=adj[v].begin();i!=adj[v].end();i++){
		if(!visited[*i]){
			dfsutil(*i,visited);
		}
	}
}
void graph::dfs(int v){
	bool *visited = new bool[V];
	for(int i=0;i<V;i++){
		visited[i]=false;
	}
	dfsutil(v,visited);
}
int main()
{

    graph g(4);
    g.add_edge(0, 1);
    g.add_edge(0, 2);
    g.add_edge(1, 2);
    g.add_edge(2, 0);
    g.add_edge(2, 3);
    g.add_edge(3, 3);
 
    cout << "Following is Depth First Traversal"
            " (starting from vertex 2) \n";
    g.dfs(2);
 
    return 0;
}


