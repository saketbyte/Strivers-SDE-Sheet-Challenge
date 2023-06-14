#include <bits/stdc++.h>
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

void helper(TreeNode<int> *root, int level, vector<int> &ans)
{
    if (root == NULL)
        return;

    if (ans.size() == level)
        ans.push_back(root->data);

    helper(root->left, level + 1, ans);
    helper(root->right, level + 1, ans);
}

vector<int> getLeftView(TreeNode<int> *root)
{
    //    Write your code here
    vector<int> a;
    helper(root, 0, a);
    return a;
}