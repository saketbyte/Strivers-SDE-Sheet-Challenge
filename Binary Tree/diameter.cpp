
int height(TreeNode<int> *root, int &dia)
{
    if (root == NULL)
        return 0;
    int left = height(root->left, dia);
    int right = height(root->right, dia);
    dia = max(dia, left + right);
    return 1 + max(left, right);
}
int diameterOfBinaryTree(TreeNode<int> *root)
{
    int dia = -1;

    height(root, dia);
    return dia;
}
