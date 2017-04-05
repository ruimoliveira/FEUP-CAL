/*
 * Graph.h
 */
#ifndef GRAPH_H_
#define GRAPH_H_

#include <vector>
#include <queue>
using namespace std;

template <class T, class U> class Edge;
template <class T, class U> class Graph;

/* 8888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888
 * Vertex
 * 8888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888 */
template <class T, class U>
class Vertex {
	T info;
	vector<Edge<T, U> > adj;
	bool visited;
	void addEdge(Vertex<T, U> *dest, double w);
	bool removeEdgeTo(Vertex<T, U> *d);
public:
	Vertex(T in);
	friend class Graph<T, U>;
	T getInfo();
};

template <class T, class U>
T Vertex<T, U>::getInfo(){
	return this->info;
}

template <class T, class U>
bool Vertex<T, U>::removeEdgeTo(Vertex<T, U> *d) {
	typename vector<Edge<T, U> >::iterator it= adj.begin();
	typename vector<Edge<T, U> >::iterator ite= adj.end();
	while (it!=ite) {
		if (it->dest == d) {
			adj.erase(it);
			return true;
		}
		else it++;
	}
	return false;
}

template <class T, class U>
Vertex<T, U>::Vertex(T in): info(in), visited(false){}

template <class T, class U>
void Vertex<T, U>::addEdge(Vertex<T, U> *dest, double w) {
	Edge<T, U> edgeD(dest,w);
	adj.push_back(edgeD);
}

/* 8888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888
 * Edge
 * 8888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888 */
template <class T, class U>
class Edge {
	Vertex<T, U> * dest;
	double weight;
public:
	Edge(Vertex<T, U> *d, double w);
	friend class Graph<T, U>;
	friend class Vertex<T, U>;
};

template <class T, class U>
Edge<T, U>::Edge(Vertex<T, U> *d, double w): dest(d), weight(w){}

/* 8888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888
 * Graph
 * 8888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888 */
template <class T, class U>
class Graph {
	vector<Vertex<T, U> *> vertexSet;
	void dfs(Vertex<T, U> *v, vector<T, U> &res) const;
public:
	bool addVertex(const T &in);
	bool addEdge(const T &sourc, const T &dest, double w);
	bool removeVertex(const T &in);
	bool removeEdge(const T &sourc, const T &dest);
	vector<T, U> dfs() const;
	vector<T, U> bfs(Vertex<T, U> *v) const;
	int maxNewChildren(Vertex<T, U> *v, T &inf) const;
	vector<Vertex<T, U> * > getVertexSet() const;
	int getNumVertex() const;
};

template <class T, class U>
int Graph<T, U>::getNumVertex() const {
	return vertexSet.size();
}

template <class T, class U>
vector<Vertex<T, U> * > Graph<T, U>::getVertexSet() const {
	return vertexSet;
}

template <class T, class U>
bool Graph<T, U>::addVertex(const T &in) {
	typename vector<Vertex<T, U>*>::iterator it= vertexSet.begin();
	typename vector<Vertex<T, U>*>::iterator ite= vertexSet.end();
	for (; it!=ite; it++)
		if ((*it)->info == in) return false;
	Vertex<T, U> *v1 = new Vertex<T, U>(in);
	vertexSet.push_back(v1);
	return true;
}

template <class T, class U>
bool Graph<T, U>::removeVertex(const T &in) {
	typename vector<Vertex<T, U>*>::iterator it= vertexSet.begin();
	typename vector<Vertex<T, U>*>::iterator ite= vertexSet.end();
	for (; it!=ite; it++) {
		if ((*it)->info == in) {
			Vertex<T, U> * v= *it;
			vertexSet.erase(it);
			typename vector<Vertex<T, U>*>::iterator it1= vertexSet.begin();
			typename vector<Vertex<T, U>*>::iterator it1e= vertexSet.end();
			for (; it1!=it1e; it1++) {
				(*it1)->removeEdgeTo(v);
			}
			delete v;
			return true;
		}
	}
	return false;
}

template <class T, class U>
bool Graph<T, U>::addEdge(const T &sourc, const T &dest, double w) {
	typename vector<Vertex<T, U>*>::iterator it= vertexSet.begin();
	typename vector<Vertex<T, U>*>::iterator ite= vertexSet.end();
	int found=0;
	Vertex<T, U> *vS, *vD;
	while (found!=2 && it!=ite ) {
		if ( (*it)->info == sourc )
			{ vS=*it; found++;}
		if ( (*it)->info == dest )
			{ vD=*it; found++;}
		it ++;
	}
	if (found!=2) return false;
	vS->addEdge(vD,w);
	return true;
}

template <class T, class U>
bool Graph<T, U>::removeEdge(const T &sourc, const T &dest) {
	typename vector<Vertex<T, U>*>::iterator it= vertexSet.begin();
	typename vector<Vertex<T, U>*>::iterator ite= vertexSet.end();
	int found=0;
	Vertex<T, U> *vS, *vD;
	while (found!=2 && it!=ite ) {
		if ( (*it)->info == sourc )
			{ vS=*it; found++;}
		if ( (*it)->info == dest )
			{ vD=*it; found++;}
		it ++;
	}
	if (found!=2) return false;
	return vS->removeEdgeTo(vD);
}




template <class T, class U>
vector<T, U> Graph<T, U>::dfs() const {
	typename vector<Vertex<T, U>*>::const_iterator it= vertexSet.begin();
	typename vector<Vertex<T, U>*>::const_iterator ite= vertexSet.end();
	for (; it !=ite; it++)
		(*it)->visited=false;
	vector<T, U> res;
	it=vertexSet.begin();
	for (; it !=ite; it++)
	    if ( (*it)->visited==false )
	    	dfs(*it,res);
	return res;
}

template <class T, class U>
void Graph<T, U>::dfs(Vertex<T, U> *v,vector<T, U> &res) const {
	v->visited = true;
	res.push_back(v->info);
	typename vector<Edge<T, U> >::iterator it= (v->adj).begin();
	typename vector<Edge<T, U> >::iterator ite= (v->adj).end();
	for (; it !=ite; it++)
	    if ( it->dest->visited == false )
	    	dfs(it->dest, res);
}

template <class T, class U>
vector<T, U> Graph<T, U>::bfs(Vertex<T, U> *v) const {
	vector<T, U> res;
	queue<Vertex<T, U> *> q;
	q.push(v);
	v->visited = true;
	while (!q.empty()) {
		Vertex<T, U> *v1 = q.front();
		q.pop();
		res.push_back(v1->info);
		typename vector<Edge<T, U> >::iterator it=v1->adj.begin();
		typename vector<Edge<T, U> >::iterator ite=v1->adj.end();
		for (; it!=ite; it++) {
			Vertex<T, U> *d = it->dest;
			if (d->visited==false) {
				d->visited=true;
				q.push(d);
			}
		}
	}
	return res;
}

template <class T, class U>
int Graph<T, U>::maxNewChildren(Vertex<T, U> *v, T &inf) const {
	vector<T, U> res;
	queue<Vertex<T, U> *> q;
	queue<int> level;
	int maxChildren=0;
	inf =v->info;
	q.push(v);
	level.push(0);
	v->visited = true;
	while (!q.empty()) {
		Vertex<T, U> *v1 = q.front();
		q.pop();
		res.push_back(v1->info);
		int l=level.front();
		level.pop(); l++;
		int nChildren=0;
		typename vector<Edge<T, U> >::iterator it=v1->adj.begin();
		typename vector<Edge<T, U> >::iterator ite=v1->adj.end();
		for (; it!=ite; it++) {
			Vertex<T, U> *d = it->dest;
			if (d->visited==false) {
				d->visited=true;
				q.push(d);
				level.push(l);
				nChildren++;
			}
		}
		if (nChildren>maxChildren) {
			maxChildren=nChildren;
			inf = v1->info;
		}
	}
	return maxChildren;
}



#endif /* GRAPH_H_ */
