#include <unordered_map>

struct Node {
    int val;
    Node *n1, *n2;

    Node* CopyNode(Node* root) {
        auto map = std::unordered_map<Node*, Node*>();
        return CopyRecursively(root, map);
    }

    Node *CopyRecursively(Node* src, std::unordered_map<Node*, Node*> map) {
        if (src == nullptr) return nullptr;

        auto it = map.find(src);
        if (it != map.end()) {
            return it->second;
        }

        auto node = new Node();
        map[src] = node;
        node->n1 = CopyRecursively(src->n1, map);
        node->n2 = CopyRecursively(src->n2, map);
        return node;
    }
};
