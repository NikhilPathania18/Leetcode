/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> arr;
    void post(Node* root)
    {
        if(root==NULL)
            return;
        for(int i=0;i<root->children.size();i++)
            post(root->children[i]);
        arr.push_back(root->val);
    }
    vector<int> postorder(Node* root) {
        if(root==NULL)
            return {};
        post(root);
        return arr;
    }
};