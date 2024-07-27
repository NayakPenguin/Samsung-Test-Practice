// Problem Statement:
// Given an undirected graph, determine whether the graph is bipartite. A graph is bipartite if you can divide its vertices into two disjoint sets such that no two vertices within the same set are adjacent.

bool isBipartite(int n, vector<pair<int, int>> edges) {
    vector<vector<int>> graph(n);
    for (auto edge : edges) {
        graph[edge.first].push_back(edge.second);
        graph[edge.second].push_back(edge.first);
    }

    // 0 - no color
    // 1 - color 1
    // 2 - color 2
    vector<int> color(n, 0);

    for (int node = 0; node < n; node++) {
        if (color[node] == 0) { // new component
            queue<int> q;
            q.push(node);
            color[node] = 1;

            while (!q.empty()) {
                int currNode = q.front();
                q.pop();

                for (auto neighbor : graph[currNode]) {
                    if (color[neighbor] == 0) {
                        color[neighbor] = 3 - color[currNode]; // Flip between 1 and 2
                        q.push(neighbor);
                    } else if (color[neighbor] == color[currNode]) {
                        return false;
                    }
                }
            }
        }
    }

    return true;
}

