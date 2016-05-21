class Solution {
public:

    enum Color {GRAY, WHITE, BLACK};
    
    bool topological_sort(int v, vector<vector<int>>&graph, vector<int>& colors, stack<int>& vertices) {
        
        colors[v] = GRAY;
        vector<int>::iterator it;

        for (it = graph[v].begin(); it != graph[v].end(); ++it) {
            
            if (colors[*it] == GRAY) {
                return true;
            } 
            
            if (colors[*it] == WHITE && topological_sort(*it, graph, colors, vertices)) {
                return true;
            }
       }
       
       colors[v] = BLACK;
       vertices.push(v);
       return false;
    }
    
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> order;
        if (numCourses == 0) {
            return order;
        }
        
        if (prerequisites.size() == 0) {
            for (int i = 0; i < numCourses; ++i) {
                order.push_back(i);
            }
            return order;
        }
        
        vector<vector<int>> graph(numCourses, vector<int>());
        vector<int> colors(numCourses, 0);
        vector<int> outdegree(numCourses, 0);
        vector<int> indegree(numCourses, 0);
        
        
        for (int i = 0; i < prerequisites.size(); ++i) {
            graph[prerequisites[i].second].push_back(prerequisites[i].first);
            outdegree[prerequisites[i].second]++;
            indegree[prerequisites[i].first]++;
        }
        
        vector<int> optional;
        for (int i = 0; i < numCourses; ++i) {
            colors[i] = WHITE;
            if (indegree[i] == 0 && outdegree[i] == 0) {
                optional.push_back(i);
            }
        }
       // cout << outdegree[2] << endl;
        // Do a topological sort on the graph with all vertices with outdegree > 0
        
        stack<int> vertices;
        bool cycle;
        for (int i = 0; i < numCourses; ++i) {
            
            if (colors[i] == WHITE) {
                
                cycle = topological_sort(i, graph, colors, vertices);
                if (cycle) {
                    break;
                }
                //cout << vertices.top() << " size = " << vertices.size() <<  endl;
            }
        }
        
        if (cycle) {
            return order;
        }
        
        while (!vertices.empty()) {
            order.push_back(vertices.top());
            vertices.pop();
        }
        
        if (order.size() < numCourses) {
            for (int i = 0; i < optional.size(); ++i) {
                order.push_back(optional[i]);
            }
        }
        return order;
        
    }
};