// Алгоритм прохода в глубину в C++
 
#include <iostream>
#include <list>
using namespace std;
 
class Graph {
  int numVertices;
  list<int> *adjLists;
  bool *visited;
 
   public:
  Graph(int V);
  void addEdge(int src, int dest);
  void DFS(int vertex);
};
 
// Инициализация графа
Graph::Graph(int vertices) {
  numVertices = vertices;
  adjLists = new list<int>[vertices];
  visited = new bool[vertices];
}
 
// Добавление ребер
void Graph::addEdge(int src, int dest) {
  adjLists[src].push_front(dest);
}
 
// Алгоритм 
void Graph::DFS(int vertex) {
  visited[vertex] = true;
  list<int> adjList = adjLists[vertex];
 
  cout << vertex << " ";
 
  list<int>::iterator i;
  for (i = adjList.begin(); i != adjList.end(); ++i)
    if (!visited[*i])
      DFS(*i);
}
 
int main() {
  Graph g(4);
  g.addEdge(0, 1);
  g.addEdge(0, 2);
  g.addEdge(1, 2);
  g.addEdge(2, 3);
 
  g.DFS(2);
 
  return 0;
}