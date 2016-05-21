class Graph
{
    private:
    int V; // Number of vertices
    vector<int> *adj_list;
    
    bool dfs (int v, bool visited[], bool revisited[]) {
        
        if (!visited[v]) {
            visited[v] = true;
            revisited[v]= true;
            for (int i = 0; i < adj_list[v].size(); ++i) {
                if (!visited[adj_list[v][i]] &&  dfs(adj_list[v][i], visited, revisited)) {
                    return true;
                }
                if (revisited[adj_list[v][i]]) {
                    return true;
                }
            }
        }
        revisited[v] = false;
        return false;
    }
    
    public:
    Graph(int n):V(n) {
        // Adjacency list for n elements
        adj_list = new vector<int>[n];
    }
    
    ~Graph() {
        delete [] adj_list;
    }
    
    void add_edge(int v, int w) {
        adj_list[v].push_back(w);
    }
    
    bool isCyclic() {
        bool visited[V] = {false};
        bool revisited[V] = {false};
        //Do DFS from each vertex
        // If DFS contains
        for (int i = 0; i < V; ++i) {
            if (dfs(i, visited, revisited)) {
                return true;
            } 
        }
        
        return false;
    }
};

class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        Graph g(numCourses);
        for (int i = 0; i < prerequisites.size(); ++i) {
            g.add_edge(prerequisites[i].first, prerequisites[i].second);
        }
        
        return !g.isCyclic();
    }
};