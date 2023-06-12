#include <bits/stdc++.h>
/*
    Following is Binary Tree Node structure:
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };
*/
vector<int> getInOrderTraversal(TreeNode *root)
{
    // Write your code here.

    vector<int> ans;
    stack<TreeNode *> s;

    while (true)
    {
        while (root != NULL) // check why root == NULL or not?
        {
            s.push(root); // push first then move left otherwise infinite loop
            root = root->left;
        }

        if (s.empty())
            break;

        root = s.top();

        s.pop();
        ans.push_back(root->data);
        root = root->right;
    }

    return ans;
}