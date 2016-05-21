/*class Graph {
  private:
    int V;
    vector<int>* adj_list;
      
  public:
  
    Graph(int n):V(n) {
        // Adjacency list for n vertices
        adj_list = new vector<int>[n];
    }
    
    ~Graph() {
        delete[] adj_list;
    }
    
    void add_edge(int v, int w) {
        // Graph is undirected 
        adj_list[v].push_back(w);
        adj_list[w].push_back(v);
    }
    
    int degree(int v) {
        return adj_list[v].size();
    }
    
    int getHeight(int v) {
        
        bool visited[V] = {false};
        int currentLevel = 1;
        int nextLevel = 0;
        int height = 0;
        
        queue<int> q;
        q.push(v);
        
        while(!q.empty()) {
            
            int vertex = q.front();
            q.pop();
            if (visited[vertex]) {
                continue;
            }
            
          //  cout << vertex << " , ";
            visited[vertex] = true;
            currentLevel--;
            for (int i = 0; i < adj_list[vertex].size(); ++i) {
                if (!visited[adj_list[vertex][i]]) {
                    q.push(adj_list[vertex][i]);
                    nextLevel++;
                }
            }
            
            if (currentLevel == 0) {
         //       cout << endl;
                height++;
                currentLevel = nextLevel;
                nextLevel = 0;
            }
        }
        
        return height;
    }
  
  
};
*/

/**
 * The idea behind the solution is that we want inner-most 1 or 2 nodes as the roots
 * There cannot be more than 2 roots as the answer. Consider a skewed tree for example.
 * We start from both ends (leaves) and return the node that is the midpoint as the root with minimum tree
 * 
 * We extend this idea and calculate degrees of all vertices.
 * We keep on reducing degrees of leaf nodes, subsequently decreasing degrees of nodes the leaves are incident on.
 * We do this until we get less than or equal to 2 nodes with degree 1 or 0.
 * Note that when we find a node with degree 0, we set its degree to -1 , so that we don't consider such nodes as leaves again.
*/
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        vector<int> roots;
        if (n == 1) { 
            roots.push_back(0);
            return roots;
        }
        
        vector<unordered_set<int>> graph (n, unordered_set<int>());
        vector<int> degree(n, 0);
        for (int i = 0; i < edges.size(); ++i) {
            graph[edges[i].first].insert(edges[i].second);
            graph[edges[i].second].insert(edges[i].first);
            
            degree[edges[i].first]++;
            degree[edges[i].second]++;
        }
        
        int count = n;
        while (count > 2) {
            
            vector<int> leaves;
            for (int i = 0; i < n; ++i) {
                if (degree[i] == 1) {
                    degree[i] = -1;
                    count--;
                    leaves.push_back(i);
                }
            }
            
            for (int i = 0; i < leaves.size(); ++i) {
                // For each neighbor of this leaf (must be one)
                // Reduce its degree by 1
                unordered_set<int>::iterator it;
                for (it = graph[leaves[i]].begin(); it != graph[leaves[i]].end(); ++it ) {
                    degree[*it] -= 1;
                }
            }
        }
        
        for (int i = 0; i < n; ++i) {
            if (degree[i] == 0 || degree[i] == 1) {
                roots.push_back(i);
            }
        }
        
        return roots;
    }
};