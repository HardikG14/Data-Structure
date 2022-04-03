#include <bits/stdc++.h>
#include "bst_node.h"
using namespace std;

class BST
{
private:
    BinaryTreeNode<int> *root;

public:
    BST()
    {
        this->root = nullptr;
    }

private:
    bool hasData(BinaryTreeNode<int> *root, int ele)
    {
        if (root == nullptr)
        {
            return false;
        }

        if (root->data == ele)
        {
            return true;
        }
        else if (ele < root->data)
        {
            return hasData(root->left, ele);
        }
        else
        {
            return hasData(root->right, ele);
        }
    }

public:
    bool hasData(int data)
    {
        return hasData(root, data);
    }

private:
    BinaryTreeNode<int> *insertInTree(BinaryTreeNode<int> *root, int ele)
    {
        if (root == nullptr)
        {
            BinaryTreeNode<int> *newNode = new BinaryTreeNode<int>(ele);
            return newNode;
        }

        // BinaryTreeNode<int>* Ans=nullptr;
        if (ele > root->data)
        {
            BinaryTreeNode<int> *rightAns = insertInTree(root->right, ele);
            root->right = rightAns;
        }
        else
        {
            BinaryTreeNode<int> *leftAns = insertInTree(root->left, ele);
            root->left = leftAns;
        }

        return root;
    }

public:
    void insert(int data)
    {
        root = insertInTree(root, data);
    }

private:
    void printBST(BinaryTreeNode<int> *root)
    {
        if (root == nullptr)
        {
            return;
        }
        queue<BinaryTreeNode<int> *> nodeQue;
        nodeQue.push(root);

        while (!nodeQue.empty())
        {
            BinaryTreeNode<int> *front = nodeQue.front();
            nodeQue.pop();

            cout << front->data << " :";
            if (front->left != nullptr)
            {
                cout << "L :" << front->left->data << " ,";
                nodeQue.push(front->left);
            }
            else
            {
                cout << "L :-1 ,";
            }

            if (front->right != nullptr)
            {
                cout << "R :" << front->right->data;
                nodeQue.push(front->right);
            }
            else
            {
                cout << "R :-1";
            }
            cout << endl;
        }
    }

public:
    void print()
    {
        printBST(root);
    }

private:
    int minintree(BinaryTreeNode<int> *root)
    {
        if (root == nullptr)
        {
            return INT_MAX;
        }
        int leftAns = minintree(root->left);
        int rightAns = minintree(root->right);
        return min(root->data, min(leftAns, rightAns));
    }

    BinaryTreeNode<int> *Delete(BinaryTreeNode<int> *root, int ele)
    {
        if (root == nullptr)
        {
            return nullptr;
        }

        if (ele > root->data)
        {
            BinaryTreeNode<int> *rightAns = Delete(root->right, ele);
            root->right = rightAns;
        }
        else if (ele < root->data)
        {
            BinaryTreeNode<int> *leftAns = Delete(root->left, ele);
            root->left = leftAns;
        }
        else
        {
            if (root->left == nullptr && root->right == nullptr)
            {
                delete root;
                return nullptr;
            }
            else if (root->left != nullptr && root->right == nullptr)
            {
                return root->left;
            }
            else if (root->left == nullptr && root->right != nullptr)
            {
                return root->right;
            }
            else
            {
                int min = minintree(root->right);
                root->data = min;
                BinaryTreeNode<int> *newAns = Delete(root->right, min);
                root->right = newAns;
                return root;
            }
        }
    }

public:
    void Delete(int ele)
    {
        root = Delete(root, ele);
    }
};