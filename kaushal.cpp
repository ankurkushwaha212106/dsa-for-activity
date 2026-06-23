class Solution {
public:
    int maxi = INT_MIN;

    int dfs(TreeNode* root) {
        if (root == NULL)
            return 0;

        int left = max(0, dfs(root->left));
        int right = max(0, dfs(root->right));

        // Path passing through current node
        maxi = max(maxi, root->val + left + right);

        // Return best path to parent
        return root->val + max(left, right);
    }

    int maxPathSum(TreeNode* root) {
        dfs(root);
        return maxi;
    }
};