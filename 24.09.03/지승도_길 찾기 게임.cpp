#include <vector>
#include <algorithm>

using namespace std;

struct TreeNode {
    int id;
    int x;
    int y;
    TreeNode* left;
    TreeNode* right;
};

bool cmp(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b) {
    if (a.second.second == b.second.second) {
        return a.second.first < b.second.first;
    }
    return a.second.second > b.second.second;
}

TreeNode* insertNode(TreeNode* root, TreeNode* node) {
    if (root == nullptr) {
        return node;
    }
    if (node->x < root->x) {
        root->left = insertNode(root->left, node);
    } else {
        root->right = insertNode(root->right, node);
    }
    return root;
}

void preorder(TreeNode* node, vector<int>& result) {
    if (node == nullptr) return;
    result.push_back(node->id);
    preorder(node->left, result);
    preorder(node->right, result);
}

void postorder(TreeNode* node, vector<int>& result) {
    if (node == nullptr) return;
    postorder(node->left, result);
    postorder(node->right, result);
    result.push_back(node->id);
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer(2);
    vector<pair<int, pair<int, int>>> nodes;

    for (int i = 0; i < nodeinfo.size(); i++) {
        nodes.push_back({i + 1, {nodeinfo[i][0], nodeinfo[i][1]}});
    }

    sort(nodes.begin(), nodes.end(), cmp);

    TreeNode* root = nullptr;
    for (auto node : nodes) {
        TreeNode* newNode = new TreeNode{node.first, node.second.first, node.second.second, nullptr, nullptr};
        root = insertNode(root, newNode);
    }

    preorder(root, answer[0]);
    postorder(root, answer[1]);

    return answer;
}
