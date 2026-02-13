class Solution {
public:
    unordered_map<Node*, Node*> cloned;

    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;

        // already cloned → reuse
        if (cloned.count(node))
            return cloned[node];

        // clone this node
        Node* copy = new Node(node->val);
        cloned[node] = copy;

        // clone neighbors
        for (Node* nei : node->neighbors) {
            copy->neighbors.push_back(cloneGraph(nei));
        }

        return copy;
    }
};
