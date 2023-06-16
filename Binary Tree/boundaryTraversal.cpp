#include <bits/stdc++.h>
/************************************************************

    Following is the Binary Tree node structure:

    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/

bool isLeaf(TreeNode<int> *node)
{
    if (node->left == NULL && node->right == NULL)
        return true;
    return false;
}

void addLeft(TreeNode<int> *root, vector<int> &ans)
{
    TreeNode<int> *curr = root->left;
    while (curr)
    {
        if (!isLeaf(curr))
            ans.push_back(curr->data);

        if (curr->left)
            curr = curr->left;
        else
            curr = curr->right;
    }
}

void addLeaf(TreeNode<int> *root, vector<int> &ans)
{

    if (isLeaf(root))
    {
        ans.push_back(root->data);
        return;
    }

    if (root->left)
        addLeaf(root->left, ans);
    if (root->right)
        addLeaf(root->right, ans);
}

void addRight(TreeNode<int> *root, vector<int> &ans)
{

    vector<int> temp;
    TreeNode<int> *curr = root->right;
    while (curr)
    {
        if (!isLeaf(curr))
            temp.push_back(curr->data);

        if (curr->right)
            curr = curr->right;
        else
            curr = curr->left;
    }

    for (int i = temp.size() - 1; i >= 0; --i)
    {
        ans.push_back(temp[i]);
    }
}

vector<int> traverseBoundary(TreeNode<int> *root)
{
    // Write your code here.

    vector<int> ans;
    if (!root)
        return ans;

    if (!isLeaf(root))
        ans.push_back(root->data);

    addLeft(root, ans);
    addLeaf(root, ans);
    addRight(root, ans);

    return ans;
}