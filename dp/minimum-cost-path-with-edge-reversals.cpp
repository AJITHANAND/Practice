#include <iostream>
#include <map>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
  int minCost(int n, vector<vector<int>> &edges) {
    int totalEdges = n;

    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        pq;

    vector<int> distance(totalEdges, INT_MAX);

    distance[0] = 0;
    pq.emplace(0, 0);

    std::vector<vector<int>> adj[totalEdges];
    for (auto &itr : edges) {
      int u = itr[0];
      int v = itr[1];
      int weight = itr[2];
      adj[u].push_back({v, weight});
      adj[v].push_back({u, weight * 2});
    }

    while (!pq.empty()) {
      int dist = pq.top().first;
      int node = pq.top().second;

      pq.pop();

      if (dist > distance[node]) {
        continue;
      }

      for (auto &itr : adj[node]) {
        if (dist + itr[1] < distance[itr[0]]) {
          distance[itr[0]] = dist + itr[1];
          pq.emplace(distance[itr[0]], itr[0]);
        }
      }
    }

    return distance[totalEdges - 1] != INT_MAX ? distance[totalEdges - 1] : -1;
  }
};

int main() {
  int n = 4;
  vector<vector<int>> edges = {{0, 1, 3}, {3, 1, 1}, {2, 3, 4}, {0, 2, 2}};
  Solution sol;
  int result = sol.minCost(n, edges);
  cout << "Minimum cost from node 0 to node " << n - 1 << " is: " << result
       << endl;
}