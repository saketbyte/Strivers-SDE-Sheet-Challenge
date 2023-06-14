
vector<int> ans;
TreeNode *curr = root;

while (curr != NULL)
{
    if (curr->left == NULL)
    {
        ans.push_back(curr->data);
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
            ans.push_back(curr->data); // this is the only difference in two algos.
            // Here you push the answer either when left is not there or before going to left, cause root then left then right.
            curr = curr->left;
        }
        else
        {
            // ans.push_back(curr->data); // In
            predecessor->right = NULL;
            curr = curr->right;
        }
    }
}
