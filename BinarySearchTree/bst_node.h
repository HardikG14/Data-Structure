template <typename T>
class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data)
    {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }

    ~BinaryTreeNode()
    {
        delete left;
        delete right;
    }
};