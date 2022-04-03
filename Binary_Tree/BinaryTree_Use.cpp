#include <bits/stdc++.h>
#include "Binary_Tree_Class.h"
using namespace std;

#define ll long long
#define pb push_back
#define ppb pop_back
#define pf push_front
#define ppf pop_front
#define all(x) (x).begin(), (x).end()
#define uniq(v) (v).erase(unique(all(v)), (v).end())
#define sz(x) (int)((x).size())
#define fr first
#define sc second
#define pii pair<int, int>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define mem1(a) memset(a, -1, sizeof(a))
#define mem0(a) memset(a, 0, sizeof(a))
#define ppc __builtin_popcount
#define ppcll __builtin_popcountll

const long long INF = 1e18;
const int32_t M = 1e9 + 7;
const int32_t MM = 998244353;
const int N = 0;

template <typename T>
class binaryTreeNode
{
public:
    T data;
    binaryTreeNode<T> *left;
    binaryTreeNode<T> *right;

    binaryTreeNode(T data)
    {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

void printBT(BinaryTreeNode<int> *root)
{
    if (root == nullptr)
    {
        return;
    }

    cout << root->data << " :";
    if (root->left != nullptr)
    {
        cout << "L" << root->left->data << " ";
    }

    if (root->right != nullptr)
    {
        cout << "R" << root->right->data << " ";
    }
    cout << "\n";
    printBT(root->left);
    printBT(root->right);
}

BinaryTreeNode<int> *takeInput()
{
    int data;
    cout << "Enter Data :";
    cin >> data;
    if (data == -1)
    {
        return nullptr;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(data);

    BinaryTreeNode<int> *left_child = takeInput();
    root->left = left_child;
    BinaryTreeNode<int> *right_child = takeInput();
    root->right = right_child;

    return root;
}

BinaryTreeNode<int> *makeBinaryTree()
{
    int rootData;
    cout << "Enter Root Data :";
    cin >> rootData;

    if (rootData == -1)
    {
        return nullptr;
    }

    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int> *> nodeQue;
    nodeQue.push(root);

    while (!nodeQue.empty())
    {
        BinaryTreeNode<int> *front = nodeQue.front();
        nodeQue.pop();

        int leftChildData;
        cout << "Enter Left child data of " << front->data << " :";
        cin >> leftChildData;

        if (leftChildData == -1)
        {
            front->left = nullptr;
        }
        else
        {
            BinaryTreeNode<int> *newNode = new BinaryTreeNode<int>(leftChildData);
            front->left = newNode;
            nodeQue.push(newNode);
        }

        int rightChildData;
        cout << "Enter Right child data of " << front->data << " :";
        cin >> rightChildData;

        if (rightChildData == -1)
        {
            front->right = nullptr;
        }
        else
        {
            BinaryTreeNode<int> *newNode = new BinaryTreeNode<int>(rightChildData);
            front->right = newNode;
            nodeQue.push(newNode);
        }
    }
    return root;
}

void printLevelWiseBT(BinaryTreeNode<int> *root)
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
            cout << "L" << front->left->data << " ";
            nodeQue.push(front->left);
        }

        if (front->right != nullptr)
        {
            cout << "R" << front->right->data << " ";
            nodeQue.push(front->right);
        }

        cout << endl;
    }
}

void printLevelWise(BinaryTreeNode<int> *root)
{
    // Write your code here
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

        cout << front->data << ":L:";

        if (front->left == nullptr)
        {
            cout << "-1,";
        }
        else
        {
            cout << front->left->data << ",";
            nodeQue.push(front->left);
        }

        cout << "R:";
        if (front->right == nullptr)
        {
            cout << "-1";
        }
        else
        {
            cout << front->right->data;
            nodeQue.push(front->right);
        }
        cout << "\n";
    }
}

int countNodes(BinaryTreeNode<int> *root)
{
    if (root == nullptr)
    {
        return 0;
    }
    int leftChildNodes = countNodes(root->left);
    int rightChildNodes = countNodes(root->right);

    return leftChildNodes + rightChildNodes + 1;
}

int noOfLeaveNodes(BinaryTreeNode<int> *root)
{
    if (root == nullptr)
    {
        return 0;
    }

    if (root->left == nullptr && root->right == nullptr)
    {
        return 1;
    }

    int leftChild = noOfLeaveNodes(root->left);
    int rightChild = noOfLeaveNodes(root->right);

    return leftChild + rightChild;
}

bool findNode(BinaryTreeNode<int> *root, int x)
{
    if (root == nullptr)
    {
        return false;
    }

    if (root->data == x)
    {
        return true;
    }

    bool leftChild = findNode(root->left, x);
    if (leftChild)
    {
        return true;
    }
    bool rightChild = findNode(root->right, x);
    if (rightChild)
    {
        return true;
    }
}

/* -------------------------- height of binary tree ------------------------- */
int heightOfBinaryTree(BinaryTreeNode<int> *root)
{
    if (root == nullptr)
    {
        return 0;
    }

    int leftChildHeight = heightOfBinaryTree(root->left);
    int rightChildHeight = heightOfBinaryTree(root->right);

    return max(leftChildHeight, rightChildHeight) + 1;
}

/* --------------------------- mirror Binary Tree --------------------------- */
void mirrorTree(BinaryTreeNode<int> *root)
{
    if (root == nullptr)
    {
        return;
    }

    swap(root->left, root->right);
    mirrorTree(root->left);
    mirrorTree(root->right);
}

/* ----------------------------- tree traversals ---------------------------- */
void preOrderTraversal(BinaryTreeNode<int> *root)
{
    if (root == nullptr)
    {
        return;
    }

    cout << root->data << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

void inOrderTraversal(BinaryTreeNode<int> *root)
{
    if (root == nullptr)
    {
        return;
    }

    inOrderTraversal(root->left);
    cout << root->data << " ";
    inOrderTraversal(root->right);
}

void postOrderTraversal(BinaryTreeNode<int> *root)
{
    if (root == nullptr)
    {
        return;
    }

    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout << root->data << " ";
}

/* --------- making tree using preorder and postorder given arrays; --------- */
// 7
// 1 2 4 5 3 6 7 4 2 5 1 6 3 7
BinaryTreeNode<int> *buildTree_prein(int *in, int *pre, int inS, int inE, int preS, int preE)
{
    if (preS > preE)
    {
        return nullptr;
    }
    int root = pre[preS];
    int lpreS = preS + 1;
    int i = inS;
    int j = 0;
    while (in[i] != root)
    {
        i++;
        j++;
    }

    int linS = inS;
    int linE = i - 1;
    int lpreE = lpreS + j - 1;
    int rpreS = lpreE + 1;
    int rpreE = preE;
    int rinS = i + 1;
    int rinE = inE;

    BinaryTreeNode<int> *newRoot = new BinaryTreeNode<int>(root);
    BinaryTreeNode<int> *leftcall = buildTree_prein(in, pre, linS, linE, lpreS, lpreE);
    BinaryTreeNode<int> *rightcall = buildTree_prein(in, pre, rinS, rinE, rpreS, rpreE);

    newRoot->right = rightcall;
    newRoot->left = leftcall;

    return newRoot;
}

BinaryTreeNode<int> *buildTree_postin(int *post, int *in, int pS, int pE, int iS, int iE)
{
    if (pE < pS)
    {
        return nullptr;
    }
    int root = post[pE];
    int rpostE = pE - 1;
    int rinE = iE;
    int i = rinE;
    int j = 0;
    while (in[i] != root)
    {
        i--;
        j++;
    }
    int rinS = i + 1;
    int rpostS = rpostE - j + 1;
    int linS = iS;
    int linE = i - 1;
    int lpostS = pS;
    int lpostE = rpostS - 1;

    BinaryTreeNode<int> *newRoot = new BinaryTreeNode<int>(root);

    BinaryTreeNode<int> *leftChild = buildTree_postin(post, in, lpostS, lpostE, linS, linE);
    BinaryTreeNode<int> *rightChild = buildTree_postin(post, in, rpostS, rpostE, rinS, rinE);

    newRoot->left = leftChild;
    newRoot->right = rightChild;

    return newRoot;
}

int heightOfTree(BinaryTreeNode<int> *root)
{
    if (root == nullptr)
    {
        return 0;
    }

    int leftHeight = heightOfTree(root->left);
    int rightHeight = heightOfTree(root->right);

    return 1 + max(leftHeight, rightHeight);
}

int diameterOfTree(BinaryTreeNode<int> *root)
{
    if (root == nullptr)
    {
        return 0;
    }

    int leftHeight = heightOfTree(root->left);
    int rightHeight = heightOfTree(root->right);
    int h1 = leftHeight + rightHeight;

    int h2 = diameterOfTree(root->left);
    int h3 = diameterOfTree(root->right);

    return max(h1, max(h2, h3));
}

/* ---------------------- diameter of tree using class ---------------------- */
class Pair
{
public:
    int height;
    int diameter;
};

Pair diameterOfTreeUsingClass(BinaryTreeNode<int> *root)
{
    if (root == nullptr)
    {
        Pair p1;
        p1.diameter = 0;
        p1.height = 0;
        return p1;
    }

    Pair leftCh = diameterOfTreeUsingClass(root->left);
    Pair rightCh = diameterOfTreeUsingClass(root->right);

    Pair ans;
    ans.height = max(leftCh.height, rightCh.height) + 1;
    ans.diameter = max(leftCh.height + rightCh.height, max(leftCh.diameter, rightCh.diameter));

    return ans;
}

/* ----------------- return min and max of tree at same time ---------------- */
pair<int, int> minAndMaxOfTree(BinaryTreeNode<int> *root)
{
    if (root == nullptr)
    {
        pair<int, int> p;
        p.first = INT_MAX;
        p.second = INT_MIN;
        return p;
    }

    pair<int, int> leftAns = minAndMaxOfTree(root->left);
    pair<int, int> rightAns = minAndMaxOfTree(root->right);

    pair<int, int> ans;
    ans.first = min(root->data, min(leftAns.first, rightAns.first));
    ans.second = max(root->data, max(leftAns.second, rightAns.second));
    return ans;
}

void printLevelWiseNew(BinaryTreeNode<int> *root)
{
    // Write your code here
    if (root == nullptr)
    {
        return;
    }

    queue<BinaryTreeNode<int> *> q1;
    queue<BinaryTreeNode<int> *> q2;
    q1.push(root);

    while (!q1.empty() || !q2.empty())
    {
        while (!q1.empty())
        {
            BinaryTreeNode<int> *front = q1.front();
            q1.pop();
            cout << front->data << " ";
            if (front->left != nullptr)
            {
                q2.push(front->left);
            }
            if (front->right != nullptr)
            {
                q2.push(front->right);
            }
        }
        cout << endl;
        while (!q2.empty())
        {
            BinaryTreeNode<int> *front = q2.front();
            q2.pop();
            cout << front->data << " ";
            if (front->left != nullptr)
            {
                q1.push(front->left);
            }
            if (front->right != nullptr)
            {
                q1.push(front->right);
            }
        }
        cout << endl;
    }
}

int height(BinaryTreeNode<int> *root)
{
    if (root == nullptr)
    {
        return 0;
    }

    int leftHt = height(root->left);
    int rightHt = height(root->right);

    return leftHt + rightHt + 1;
}
bool isBalanced(BinaryTreeNode<int> *root)
{
    if (root == nullptr)
    {
        return true;
    }

    int leftHt = height(root->left);
    int rightHt = height(root->right);

    bool leftCh = isBalanced(root->left);
    bool rightCh = isBalanced(root->right);

    if (((leftHt == rightHt) || abs(leftHt - rightHt) == 1) && (leftCh && rightCh))
    {
        return true;
    }

    return false;
}

BinaryTreeNode<int> *removeLeafNodes(BinaryTreeNode<int> *root)
{
    // Write your code here
    if (root == nullptr)
    {
        return nullptr;
    }

    if (root->left == nullptr && root->right == nullptr)
    {
        delete root;
        return nullptr;
    }

    BinaryTreeNode<int> *leftCh = removeLeafNodes(root->left);
    BinaryTreeNode<int> *rightCh = removeLeafNodes(root->right);

    root->left = leftCh;
    root->right = rightCh;

    return root;
}

template <typename T>
class Node
{
public:
    T data;
    Node<T> *next;

    Node(T data)
    {
        this->data = data;
        this->next = nullptr;
    }
};

vector<Node<int> *> constructLinkedListForEachLevel(BinaryTreeNode<int> *root)
{
    // Write your code here
    vector<Node<int> *> vec;
    if (root == nullptr)
    {
        vec.push_back(nullptr);
        return vec;
    }
    queue<BinaryTreeNode<int> *> q1;
    queue<BinaryTreeNode<int> *> q2;
    q1.push(root);

    while (!q1.empty() || !q2.empty())
    {
        Node<int> *head = nullptr;
        Node<int> *tail = nullptr;
        while (!q1.empty())
        {
            BinaryTreeNode<int> *front = q1.front();
            q1.pop();
            if (front->left != nullptr)
            {
                q2.push(front->left);
            }
            if (front->right != nullptr)
            {
                q2.push(front->right);
            }
            Node<int> *newNode = new Node<int>(front->data);
            if (head == nullptr)
            {
                head = newNode;
                tail = newNode;
            }
            else
            {
                tail->next = newNode;
                tail = newNode;
            }
        }
        if (head != nullptr)
        {
            vec.push_back(head);
        }

        head = nullptr;
        tail = nullptr;
        while (!q2.empty())
        {
            BinaryTreeNode<int> *front = q2.front();
            q2.pop();
            if (front->left != nullptr)
            {
                q1.push(front->left);
            }
            if (front->right != nullptr)
            {
                q1.push(front->right);
            }
            Node<int> *newNode = new Node<int>(front->data);
            if (head == nullptr)
            {
                head = newNode;
                tail = newNode;
            }
            else
            {
                tail->next = newNode;
                tail = newNode;
            }
        }
        if (head != nullptr)
        {
            vec.push_back(head);
        }
    }
    return vec;
}

void zigZagOrder(BinaryTreeNode<int> *root)
{
    // Write your code here
    if (root == nullptr)
    {
        return;
    }

    stack<BinaryTreeNode<int> *> sta1;
    stack<BinaryTreeNode<int> *> sta2;
    sta1.push(root);

    while (!sta1.empty() || !sta2.empty())
    {

        while (!sta1.empty())
        {
            BinaryTreeNode<int> *front = sta1.top();
            sta1.pop();
            cout << front->data << " ";
            if (front->left != nullptr)
            {
                sta2.push(front->left);
            }
            if (front->right != nullptr)
            {
                sta2.push(front->right);
            }
        }
        cout << endl;
        while (!sta2.empty())
        {
            BinaryTreeNode<int> *front = sta2.top();
            sta2.pop();
            cout << front->data << " ";
            if (front->right != nullptr)
            {
                sta1.push(front->right);
            }
            if (front->left != nullptr)
            {
                sta1.push(front->left);
            }
        }
        cout << endl;
    }
}

void printNodesWithoutSibling(BinaryTreeNode<int> *root)
{
    // Write your code here
    if (root == nullptr)
    {
        return;
    }

    if (root->left == nullptr && root->right != nullptr)
    {
        cout << root->right->data << " ";
    }

    if (root->left != nullptr && root->right == nullptr)
    {
        cout << root->left->data << " ";
    }

    printNodesWithoutSibling(root->left);
    printNodesWithoutSibling(root->right);
}

bool getPath(BinaryTreeNode<int> *root, int key, vector<int> &path)
{
    if (root == NULL)
    {
        return false;
    }

    path.push_back(root->data);
    if (root->data == key)
    {
        return true;
    }

    if (getPath(root->left, key, path) || getPath(root->right, key, path))
    {
        return true;
    }

    path.pop_back();
    return false;
}

int lca(BinaryTreeNode<int> *root, int n, int m)
{
    vector<int> path1, path2;

    if (!getPath(root, n, path1) || !getPath(root, m, path2))
    {
        return -1;
    }

    int pc = 0;
    while (pc < path1.size() && pc < path2.size())
    {
        if (path1[pc] != path2[pc])
        {
            return path1[pc - 1];
        }
        pc++;
    }
}

vector<int> path1(BinaryTreeNode<int> *root, int key)
{
    if (root == NULL)
    {
        vector<int> p;
        return p;
    }
    if (root->data == key)
    {
        vector<int> p;
        p.push_back(root->data);
        return p;
    }

    vector<int> leftAns = path1(root->left, key);
    if (leftAns.size() != 0)
    {
        leftAns.push_back(root->data);
        return leftAns;
    }

    vector<int> rightAns = path1(root->right, key);
    if (rightAns.size() != 0)
    {
        rightAns.push_back(root->data);
        return rightAns;
    }
}

pair<int, vector<int>> maxSumPath(BinaryTreeNode<int> *root)
{
    if (root == nullptr)
    {
        pair<int, vector<int>> p;
        p.first = 0;
        vector<int> v;
        p.second = v;
        return p;
    }

    pair<int, vector<int>> leftAns = maxSumPath(root->left);
    pair<int, vector<int>> rightAns = maxSumPath(root->right);

    if (root->data + leftAns.first > root->data + rightAns.first)
    {
        pair<int, vector<int>> ans;
        ans.first = root->data + leftAns.first;
        vector<int> v;
        leftAns.second.push_back(root->data);
        v = leftAns.second;
        ans.second = v;
        return ans;
    }
    else
    {
        pair<int, vector<int>> ans;
        ans.first = root->data + rightAns.first;
        vector<int> v;
        rightAns.second.push_back(root->data);
        v = rightAns.second;
        ans.second = v;
        return ans;
    }
}
int main()
{

    /*
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(10);
    BinaryTreeNode<int> *n1 = new BinaryTreeNode<int>(30);
    BinaryTreeNode<int> *n2 = new BinaryTreeNode<int>(20);
    root->left = n1;
    root->right = n2;
    */
    //    1 2 3 4 -1 8 9 6 7 -1 -1 10 -1 -1 -1 -1 -1 -1 -1
    // 1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1
    // BinaryTreeNode<int> *root = makeBinaryTree();
    // BinaryTreeNode<int> *newRoot = takeInput();
    // cout << "\n";
    // 7

    // int post[] = {4, 5, 2, 6, 7, 3, 1};
    // BinaryTreeNode<int> *root = removeLeafNodes(newRoot);
    // int ino[] = {4, 2, 5, 1, 6, 3, 7};

    // BinaryTreeNode<int> *hello = buildTree_postin(post, ino, 0, 6, 0, 6);
    // printLevelWise(hello);
    // cout << hello->data << endl;
    // printLevelWiseBT(root);
    // cout << endl;
    // printLevelWiseBT(root);
    // printLevelWise(hello);
    // mirrorTree(root);
    // preOrderTraversal(root);
    // printLevelWiseBT(root);
    // printLevelWise(root);
    // cout << noOfLeaveNodes(root);
    BinaryTreeNode<int> *root = makeBinaryTree();
    // cout << diameterOfTree(root);
    cout << "\n";
    // pair<int, int> ans = minAndMaxOfTree(root);
    // Pair ans = diameterOfTreeUsingClass(root);
    // printLevelWiseNew(root);
    // cout << noOfLeaveNodes(root);
    // vector<int> path;
    // cout << getPath(root, 6, path);
    pair<int, vector<int>> ans = maxSumPath(root);
    cout << ans.first << endl;
    for (int i = 0; i < ans.second.size(); i++)
    {
        cout << ans.second[i] << " ";
    }
    cout << endl;
    // path = path1(root, 6);
    // for (int i = 0; i < path.size(); i++)
    // {
    //     cout << path[i] << " ";
    // }
    // cout << ans.first << " " << ans.second << endl;
    // cout << ans.diameter;
    delete root;
    // delete newRoot;
    return 0;
}