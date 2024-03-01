#include <bits/stdc++.h>
using namespace std;

template<typename E>
class BinaryTree
{
public:
    E data;
    BinaryTree<E>* left;
    BinaryTree<E>* right;
    BinaryTree<E>* parent;

    BinaryTree()
    {
        data = 0;
        left = NULL;
        right = NULL;
        parent = NULL;
    }

    BinaryTree(E value)
    {
        data = value;
        left = NULL;
        right = NULL;
        parent = NULL;
    }

    BinaryTree(E value, BinaryTree<E>* left, BinaryTree<E>* right)
    {
        data = value;
        this->left = left;
        this->right = right;
        parent = NULL;
    }

    // Calculate the height of the node
    int height()
    {
        if (this == NULL)
        {
            return 0;
        }
        else
        {
            int l = 0;
            int r = 0;
            if (left != NULL)
            {
                l = left->height();
            }
            if (right != NULL)
            {
                r = right->height();
            }
            int hgt = max(l, r) + 1;
            return hgt;
        }
    }

    // Set the left child of the node
    void setLeft(BinaryTree<E>* newLeft)
    {
        left = newLeft;
        if (newLeft != NULL)
        {
            newLeft->parent = this;
        }
    }

    // Set the parent of the node
    void setParent(BinaryTree<E>* newParent)
    {
        parent = newParent;
    }

    // Set the right child of the node
    void setRight(BinaryTree<E>* newRight)
    {
        right = newRight;
        if (newRight != NULL)
        {
            newRight->parent = this;
        }
    }

    // Set the value of the node
    void setValue(E value)
    {
        data = value;
    }

    // Iterator class for traversing the tree
    class Iterator
    {
    private:
        stack<BinaryTree<E>*> node;

    public:
        Iterator(BinaryTree<E>* root)
        {
            if (root != NULL)
                node.push(root);
        }

        E next()
        {
            while (!node.empty())
            {
                BinaryTree<E>* cur = node.top();
                node.pop();
                if (cur->right != NULL)
                {
                    node.push(cur->right);
                }
                if (cur->left != NULL)
                {
                    node.push(cur->left);
                }
                return cur->data;
            }
        }

        bool hasNext()
        {
            return !node.empty();
        }
    };

    // an iterator for in-order traversal
    Iterator inorderIterator()
    {
        return Iterator(this);
    }

    // an iterator for pre-order traversal
    Iterator preorderIterator()
    {
        stack<BinaryTree<E>*> node;
        node.push(this);
        return Iterator(this);
    }

    // Create an iterator for post-order traversal
    Iterator postorderIterator()
    {
        stack<E> outStack;
        stack<BinaryTree<E>*> inStack;
        inStack.push(this);
        while (!inStack.empty())
        {
            BinaryTree<E>* current = inStack.top();
            inStack.pop();
            outStack.push(current->data);
            if (current->left != NULL)
            {
                inStack.push(current->left);
            }
            if (current->right != NULL)
            {
                inStack.push(current->right);
            }
        }
        return Iterator();
    }

    // Check if the tree is height-balanced
    bool isBalanced()
    {
        if (!this)
        {
            return true;
        }
        int leftHeight = 0;
        if (left != NULL)
        {
            leftHeight = left->height();
        }
        int rightHeight = 0;
        if (right != NULL)
        {
            rightHeight = right->height();
        }
        if (abs(leftHeight - rightHeight) <= 1)
        {
            if (left->isBalanced())
            {
                if (right->isBalanced())
                {
                    return true;
                }
            }
        }
        return false;
    }

    // Check if the tree is complete
    bool isComplete()
    {
        if (!this)
        {
            return true;
        }
        queue<BinaryTree<E>*> q;
        q.push(this);
        bool node = false;
        while (!q.empty())
        {
            BinaryTree<E>* current = q.front();
            q.pop();
            if (current == NULL)
            {
                node = true;
            }
            else
            {
                if (node)
                {
                    return false;
                }
                q.push(current->left);
                q.push(current->right);
            }
        }
        return true;
    }

    // Check if the tree is full
    bool isFull()
    {
        if (!this)
        {
            return true;
        }
        if (left == NULL && right == NULL)
        {
            return true;
        }
        if ((left != NULL && right != NULL))
        {
            return left->isFull() && right->isFull();
        }
        return false;
    }

    // Check if the tree is a binary search tree
    bool isBinarySearchTree()
    {
        if (this == NULL)
        {
            return true;
        }
        if ((left != NULL && left->data >= data) || (right != NULL && right->data <= data))
        {
            return false;
        }
        bool l = true;
        bool r = true;
        if (left != NULL)
        {
            l = left->isBinarySearchTree() && left->data < data;
        }
        if (right != NULL)
        {
            r = right->isBinarySearchTree() && right->data > data;
        }
        return l && r;
    }

    // Build a balanced binary search tree from a sorted array of nodes
    static BinaryTree<E>* buildBalancedBST(vector<E>& nodes, int start, int End)
    {
        if (start > End)
        {
            return NULL;
        }
        int mid = start + (End - start) / 2;
        BinaryTree<E>* root = new BinaryTree<E>(nodes[mid]);
        root->left = buildBalancedBST(nodes, start, mid - 1);
        root->right = buildBalancedBST(nodes, mid + 1, End);
        return root;
    }

    // Balance an unbalanced binary search tree
    static BinaryTree<E>* balance_tree(BinaryTree<E>* root)
    {
        if (root == NULL)
            return NULL;
        vector<E> nodes;
        stack<BinaryTree<E>*> st;
        BinaryTree<E>* curr = root;
        while (curr != NULL || !st.empty())
        {
            while (curr != NULL)
            {
                st.push(curr);
                curr = curr->left;
            }
            curr = st.top();
            st.pop();
            nodes.push_back(curr->data);
            curr = curr->right;
        }
        return buildBalancedBST(nodes, 0, nodes.size() - 1);
    }
};

int main()
{
    //  a sample binary tree
    BinaryTree<int>* demo = new BinaryTree<int>(15);
    demo->left = new BinaryTree<int>(2107006);
    demo->right = new BinaryTree<int>(2107016);
    demo->left->left = new BinaryTree<int>(2107002);
    demo->left->right = new BinaryTree<int>(2107005);
    demo->right->right = new BinaryTree<int>(2107055);
    demo->right->left = new BinaryTree<int>(2107031);
    demo->right->left = new BinaryTree<int>(2107020);

    // various properties of the tree
    cout << "Height of node in tree: " << (demo->height()? "yes" : "NO") << endl;
    cout << "Tree is height balanced: " << (demo->isBalanced() ? "yes" : "NO") << endl;
    cout << "tree is complete: " << (demo->isComplete()? "yes" : "NO") << endl;
    cout << "Tree is full: " << (demo->isFull()? "yes" : "NO") << endl;
    cout << "Is Binary Search Tree balanced? : " << (demo->isBinarySearchTree()? "yes" : "NO") << endl;

    // Balance the tree
    demo = BinaryTree<int>::balance_tree(demo);

    // Display properties of the balanced tree
    cout << "Height after balancing? " << (demo->height()? "yes" : "NO") << endl;
    cout << "Is tree Balanced after balancing? " << (demo->isBalanced() ? "yes" : "NO") << endl;
    cout << "Is tree Complete after balancing? " << (demo->isComplete()? "yes" : "NO")  << endl;
    cout << "Is tree Full after balancing? " << (demo->isFull()? "yes" : "NO")  << endl;
    cout << "Is Binary Search Tree balanced after balancing? " << (demo->isBinarySearchTree()? "yes" : "NO")<< endl;

    delete demo; // Delete dynamically allocated memory

    return 0;
}
