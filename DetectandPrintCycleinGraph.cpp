// Problem Statement:
// Given an undirected graph, detect if there is a cycle in the graph and if found, print the nodes forming the cycle.

// APPROACH
// 1. Use DFS to traverse the graph.
// 2. Use a parent array to keep track of the parent nodes.
// 3. When a visited node is encountered, a cycle is detected.
// 4. Backtrack using the parent array to print the cycle.


bool dfs(int node, vector<vector<int>>& graph, vector<int>& visited, vector<int>& parent, int& cycle_start, int& cycle_end) {
    visited[node] = 1;

    for (int neighbor : graph[node]) {
        if (visited[neighbor] == 0) {
            parent[neighbor] = node;
            if (dfs(neighbor, graph, visited, parent, cycle_start, cycle_end))
                return true;
        } else if (visited[neighbor] == 1) {
            cycle_start = neighbor;
            cycle_end = node;
            return true;
        }
    }

    visited[node] = 2;
    return false;
}

void detectAndPrintCycle(int n, vector<pair<int, int>>& edges) {
    vector<vector<int>> graph(n);
    for (auto edge : edges) {
        graph[edge.first].push_back(edge.second);
        graph[edge.second].push_back(edge.first);
    }

    vector<int> visited(n, 0);
    vector<int> parent(n, -1);
    int cycle_start = -1, cycle_end = -1;

    for (int node = 0; node < n; ++node) {
        if (visited[node] == 0 && dfs(node, graph, visited, parent, cycle_start, cycle_end))
            break;
    }

    if (cycle_start == -1) {
        cout << "No cycle detected." << endl;
    } else {
        vector<int> cycle;
        cycle.push_back(cycle_start);
        for (int v = cycle_end; v != cycle_start; v = parent[v]) {
            cycle.push_back(v);
        }
        cycle.push_back(cycle_start);
        reverse(cycle.begin(), cycle.end());

        cout << "Cycle detected: ";
        for (int v : cycle) {
            cout << v << " ";
        }
        cout << endl;
    }
}
