#include <bits/stdc++.h>
/*************************************************************

    Following is the Binary Tree node structure

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/

vector<int> zigZagTraversal(BinaryTreeNode<int> *root)
{
    // Write your code here!

    vector<int> ans;

    if (root == NULL)
        return ans;

    queue<BinaryTreeNode<int> *> node_queue;
    node_queue.push(root);
    bool ltr = true;
    while (!node_queue.empty())
    {
        int n = node_queue.size();
        vector<int> temp(n);

        for (int i = 0; i < n; i++)
        {
            BinaryTreeNode<int> *curr = node_queue.front();
            node_queue.pop();

            int pos = ltr ? i : n - i - 1;
            temp[pos] = curr->data;

            if (curr->left)
                node_queue.push(curr->left);
            if (curr->right)
                node_queue.push(curr->right);
        }
        ltr = !ltr;

        for (auto it : temp)
        {
            ans.push_back(it);
        }
    }

    return ans;
}
