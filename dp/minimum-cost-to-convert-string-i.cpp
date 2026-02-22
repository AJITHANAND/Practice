#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {

private:
  inline int charToIndex(const char &c) { return c - 'a'; }

  int digikstra(vector<vector<long long>> &graph, int start, int end) {
    const int ALPHABET_SIZE = 26;
    vector<long long> dist(ALPHABET_SIZE, 1e15);
    vector<bool> visited(ALPHABET_SIZE, false);
    dist[start] = 0;

    for (int i = 0; i < ALPHABET_SIZE - 1; ++i) {
      long long minDist = 1e15;
      int u = -1;
      for (int j = 0; j < ALPHABET_SIZE; ++j) {
        if (!visited[j] && dist[j] < minDist) {
          minDist = dist[j];
          u = j;
        }
      }

      if (u == -1)
        break;

      visited[u] = true;

      for (int v = 0; v < ALPHABET_SIZE; ++v) {
        if (!visited[v] && graph[u][v] != 1e15 &&
            dist[u] + graph[u][v] < dist[v]) {
          dist[v] = dist[u] + graph[u][v];
        }
      }
    }

    return dist[end] == 1e15 ? -1 : dist[end];
  }

public:
  long long minimumCost(string source, string target, vector<char> &original,
                        vector<char> &changed, vector<int> &cost) {
    // build graph table
    const int ALPHABET_SIZE = 26;
    vector<vector<long long>> graph(ALPHABET_SIZE,
                                    vector<long long>(ALPHABET_SIZE, 1e15));
    for (size_t i = 0; i < original.size(); ++i) {
      int u = charToIndex(original[i]);
      int v = charToIndex(changed[i]);
      graph[u][v] = min(graph[u][v], static_cast<long long>(cost[i]));
    }

    long long totalCost = 0;
    for (size_t i = 0; i < source.size(); ++i) {
      int s = charToIndex(source[i]);
      int t = charToIndex(target[i]);
      if (s == t) {
        continue;
      }

      int minCost = digikstra(graph, s, t);
      if (minCost == -1) {
        return -1;
      }
      totalCost += minCost;
    }
    return totalCost;
  }
};

int main() {
  string source = "abcd";
  string target = "acbe";
  vector<char> original = {'a', 'b', 'c', 'c', 'e', 'd'};
  vector<char> changed = {'b', 'c', 'b', 'e', 'b', 'e'};
  vector<int> cost = {2, 5, 5, 1, 2, 20};
  Solution sol;
  cout << sol.minimumCost(source, target, original, changed, cost) << endl;
  return 0;
}