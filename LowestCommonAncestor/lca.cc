#include<bits/stdc++.h>

using namespace std;

// improvement: return ordered set
vector<TreeNode*> DFSUntil(TreeNode* root, TreeNode* end) {
    unordered_set<TreeNode*> visited;
    vector<TreeNode*> path = {end};
    
    stack<TreeNode*> st;
    st.push(root);
    while(!st.empty()) {
        auto node = st.top();
        if(node == end) break;
        if(visited.find(node) != visited.end()) st.pop();
        else {
            visited.insert(node);
            if(node->left)  st.push(node->left);
            if(node->right) st.push(node->right);    
        }
    }
    
    while(!st.empty()) {
        if(visited.find(st.top()) != visited.end()) path.push_back(st.top());
        st.pop();
    }
    
    return path;
}

TreeNode* lowestCommonAncestor_iterative(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(!root) return NULL;
    
    vector<TreeNode*> path_to_p = DFSUntil(root, p), path_to_q = DFSUntil(root, q);
   
    unordered_set<TreeNode*> set_path_to_p;
    for(auto pp:path_to_p) set_path_to_p.insert(pp);
    
    for(auto qq:path_to_q) if(set_path_to_p.find(qq) != set_path_to_p.end()) return qq;

    return NULL;
}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if( root == p || root == q || !root ) return root;
    
    TreeNode* l = lowestCommonAncestor(root->left, p, q),
            * r = lowestCommonAncestor(root->right, p, q);
    
    if(!l) return r;
    
    if(!r) return l;

    return root;
}