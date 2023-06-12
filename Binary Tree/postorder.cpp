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
vector<int> getPostOrderTraversal(TreeNode *cur)
{
    // Write your code here.
    vector<int> ans;
    stack<TreeNode *> stk;

    if (cur == NULL)
        return {};

    TreeNode *temp;

    while (cur != NULL || !stk.empty())
    {
        //  Move to extreme left while standing at each node.
        while (cur != NULL)
        {
            stk.push(cur);
            cur = cur->left;
        }

        temp = stk.top()->right;
        if (temp == NULL)
        {
            // When the temp is null, which means it is the extreme left having no right to explore further
            // we can safely print the topmost of stack.
            temp = stk.top();
            stk.pop();
            ans.push_back(temp->data);
            // Now if the node we just pushed was right of a node
            //    which is currently at the top of our stack, then we need to
            // trace back to current node and move upwards.
            while (!stk.empty() && temp == stk.top()->right)
            {
                temp = stk.top();
                stk.pop();
                ans.push_back(temp->data);
            }
        }
        // if the current node is not the extreme right either of a subtree
        // then move towards the right while checking for extreme left at each step.
        else
        {
            cur = temp;
            // Now since temp is not null, the same process will be repeated for each
            // node as in the first while loop and this else.
        }
    }
    return ans;
}
