/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
TreeNode* solve(int preStart, int postStart, int preEnd , vector<int>& preOrder, vector<int>& postOrder, unordered_map<int,int>& mp){
    if(preStart > preEnd){
        return NULL;
    }
    TreeNode* root = new TreeNode(preOrder[preStart]);
    if(preStart == preEnd){
        return root;
    }
    int nextNode = preOrder[preStart+1];
    int j = mp[nextNode];
    int num =  j - postStart +1;
    root->left = solve(preStart + 1, postStart, preStart+num, preOrder, postOrder,mp);
    root->right = solve(preStart+num+1, j+1, preEnd, preOrder, postOrder,mp);
    return root;
}
public:
    //TC is O(n) and SC is O(2n)
    TreeNode* constructFromPrePost(vector<int>& preOrder, vector<int>& postOrder) {
        int n = preOrder.size();
        unordered_map<int,int>mp;
        for(int i =0; i<n; i++){
            mp[postOrder[i]] = i;
        }
        return solve(0,0,n-1,preOrder,postOrder,mp);   
    }
};
