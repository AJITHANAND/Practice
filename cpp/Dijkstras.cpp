#include <iostream>
#include <vector>

using namespace std;

vector<int> shortTestPath(int n, vector<vector<int>> &edges) {
  int totalEdges = n;

  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      pq;

  vector<int> distance(totalEdges, INT_MAX);

  distance[0] = 0;
  pq.emplace(0, 0);

  while (!pq.empty()) {
    int dist = pq.top().first;
    int node = pq.top().second;

    pq.pop();

    for (auto itr : edges) {
      int u = itr[0]; // from
      int v = itr[1]; // to
      int weight = itr[2];

      if (u == node) {
        if (dist + weight < distance[v]) {
          distance[v] = dist + weight;
          pq.emplace(distance[v], v);
        }
        continue;
      } else if (v == node) { // reverse direction cost double
        if (dist + (weight * 2) < distance[u]) {
          distance[u] = dist + (weight * 2);
          pq.emplace(distance[u], u);
        }
        continue;
      }
    }
  }

  return distance;
}

int main() {
  // Input: n = 4, edges = [[0,1,3],[3,1,1],[2,3,4],[0,2,2]]

  // 0 -> 1 : weight = 3
  // 0 -> 2 : weight = 2
  // 2 -> 3 : weight = 4
  // 3 -> 1 : weight = 1

  // n = 2

  int n = 4;

  vector<vector<int>> edges = {{0, 1, 3}, {3, 1, 1}, {2, 3, 4}, {0, 2, 2}};

  vector<int> result = shortTestPath(n, edges);

  for (int i = 0; i < result.size(); i++) {
    cout << "Distance from 0 to " << i << " is " << result[i] << endl;
  }
}
