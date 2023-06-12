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
vector<int> getPreOrderTraversal(TreeNode *p)
{
    // Write your code here.

    vector<int> ans;
    if (!p)
        return ans;
    stack<TreeNode *> s;

    s.push(p);

    while (!s.empty())
    {
        p = s.top();
        s.pop();

        if (p != NULL)
        {
            ans.push_back(p->data);
        }

        //  Since we are using a stack, hence we go right and then left. Simplest traversal.
        if (p->right != NULL)
        {

            s.push(p->right);
        }

        if (p->left != NULL)
        {
            s.push(p->left);
        }
    }
    return ans;
}