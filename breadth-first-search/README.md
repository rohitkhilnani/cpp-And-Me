# Breadth First Search

Class Bfs implements breadth first search using adjacency list representation of a graph.
	
Methods/ Operations implemented:

	Bfs(int n, int m, std::vector<std::vector<int>> edges, int s) - Constructs Bfs object - initializes vertices and adjacency list	

	void traverse() - Traverses in breadth first fashion and prints traversal

	void printPath(int u)	- Prints path from source s to vertex u 

	void printDistances() - Prints distance of all vertices from source

	void printAllPaths() - Prints path of all vertices from source

	~Bfs() - Deallocates vertices
