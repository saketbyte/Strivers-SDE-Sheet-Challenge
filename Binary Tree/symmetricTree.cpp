/*****************************************************

    Following is the Binary Tree node structure:

    class BinaryTreeNode {
        public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~BinaryTreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

******************************************************/

bool isEqual(BinaryTreeNode<int> *r1, BinaryTreeNode<int> *r2)
{

    if (!r1 || !r2)
        return r1 == r2;
    if (r1->data == r2->data)
    {
        return isEqual(r1->left, r2->right) && isEqual(r1->right, r2->left);
    }

    return false;
}
bool isSymmetric(BinaryTreeNode<int> *root)
{

    if (root == NULL)
        return -1;
    return isEqual(root->left, root->right);
}