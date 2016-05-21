/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:

    void cloneGraphUtil(unordered_map<UndirectedGraphNode*, UndirectedGraphNode*>& graphMap, UndirectedGraphNode* src, UndirectedGraphNode* target) {
        
        for (int i = 0; i < src->neighbors.size(); ++i) {
            
            if (graphMap.find(src->neighbors[i]) == graphMap.end()) {
                UndirectedGraphNode* child = new UndirectedGraphNode(src->neighbors[i]->label);
                graphMap[src->neighbors[i]] = child;
                target->neighbors.push_back(child);
                cloneGraphUtil(graphMap, src->neighbors[i], target->neighbors.back() );
            } else {
                target->neighbors.push_back(graphMap[src->neighbors[i]]);
            }
        }
    }
        
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> graphMap;
        UndirectedGraphNode* ansNode(NULL);
        if (!node) {
            return ansNode;
        }
        
        ansNode = new UndirectedGraphNode(node->label);
        graphMap[node] = ansNode;
        cloneGraphUtil(graphMap, node, ansNode);
        return ansNode;
    }
};