# Depth First Search

Class Dfs implements Depth First Search using adjacency list representation of graph

Methods/ Operations implemented: 

	Dfs(int n, int m, std::vector<std::vector<int>> edges) - Constructs Dfs object - Initializes vertices and adjacency list

	void traverse() - Traverses in depth first fashion and prints traversal

	bool isCyclic() - Returns true if graph is cyclic

	void topologicalSort() - Prints topological sort order of vertices if graph is acyclic

	Dfs::~Dfs() - Deallocate Vertices
