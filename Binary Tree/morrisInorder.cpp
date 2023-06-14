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
    // So the logic here is simple. It states that, we need to link the inorder predecessor with the current node/root node.
    //  The algorithm to do that is-
    // Move one step left, then go as right as possible, the last node will be inorder predecessor of the current node. Now link this node with the node from where you took left turn.
    // Two cases will occur when you reach the predecessor - either it will be null (first time) or it will be connected already. Just toggle the link in either case and add
    // the node to answer if you are removing the link.
    //  Now, if the one step left was null itself, then add it to our answer and move one step right from there, and repeat above process.

    vector<int> ans;
    TreeNode *curr = root;

    while (curr != NULL)
    {
        if (curr->left == NULL)
        {
            ans.push_back(curr->data); // Push in answer when the left is over. cause left root right
            curr = curr->right;
        }
        else
        {
            TreeNode *predecessor = curr->left;
            while (predecessor->right != curr && predecessor->right != NULL)
            {
                predecessor = predecessor->right;
            }

            if (predecessor->right == NULL)
            {
                predecessor->right = curr;
                curr = curr->left;
            }
            else
            {
                ans.push_back(curr->data); // You push the answer before going to right
                predecessor->right = NULL;
                curr = curr->right;
            }
        }
    }

    return ans;
}