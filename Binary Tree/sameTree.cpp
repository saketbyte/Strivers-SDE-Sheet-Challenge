

class Solution
{
public:
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        if (p == NULL && q == NULL)
            return true;

        if (p == NULL || q == NULL)
            return false;

        queue<TreeNode *> x, y;
        x.push(p);
        y.push(q);

        while (!x.empty() || !y.empty())
        {

            TreeNode *m, *n;
            m = x.front();
            n = y.front();
            x.pop();
            y.pop();

            if (m->val != n->val)
            {

                return false;
            }

            if (m->left && n->left)
            {
                x.push(m->left);
                y.push(n->left);
            }

            else if (m->left || n->left)
                return false;

            if (m->right && n->right)
            {
                x.push(m->right);
                y.push(n->right);
            }

            else if (m->right || n->right)
                return false;
        }

        return true;
    }
};
