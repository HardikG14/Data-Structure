#include <bits/stdc++.h>
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

BinaryTreeNode<int> *makeTree()
{
    int rootData;
    cout << "Enter Root Data: ";
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

        int leftData;
        cout << "Enter left data of " << front->data << " :";
        cin >> leftData;
        if (leftData != -1)
        {
            BinaryTreeNode<int> *newNode = new BinaryTreeNode<int>(leftData);
            nodeQue.push(newNode);
            front->left = newNode;
        }

        int rightData;
        cout << "Enter right data of " << front->data << " :";
        cin >> rightData;
        if (rightData != -1)
        {
            BinaryTreeNode<int> *newNode = new BinaryTreeNode<int>(rightData);
            nodeQue.push(newNode);
            front->right = newNode;
        }
    }
    return root;
}

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

bool findElement(BinaryTreeNode<int> *root, int x)
{
    if (root == nullptr)
    {
        return false;
    }

    if (root->data == x)
    {
        return true;
    }

    if (x < root->data)
    {
        return findElement(root->left, x);
    }
    else
    {
        return findElement(root->right, x);
    }
}
/* --------------------------- max and min in tree -------------------------- */
int MAX(BinaryTreeNode<int> *root)
{
    if (root == nullptr)
    {
        return INT_MIN;
    }

    int leftMax = MAX(root->left);
    int rightMax = MAX(root->right);

    return max(root->data, max(leftMax, rightMax));
}

int MIN(BinaryTreeNode<int> *root)
{
    if (root == nullptr)
    {
        return INT_MAX;
    }

    int leftMin = MIN(root->left);
    int rightMin = MIN(root->right);

    return min(root->data, min(leftMin, rightMin));
}

/* -------------------------- is binary tree a bst -------------------------- */
bool is_BST1(BinaryTreeNode<int> *root)
{
    if (root == nullptr)
    {
        return true;
    }

    int leftMax = MAX(root->left);
    int rightMin = MIN(root->right);

    bool output = (root->data > leftMax) && (root->data <= rightMin) && is_BST1(root->left) && is_BST1(root->right);

    return output;
}

pair<bool, pair<int, int>> is_BST2(BinaryTreeNode<int> *root)
{
    if (root == nullptr)
    {
        pair<bool, pair<int, int>> ans;
        ans.first = true;
        pair<int, int> p;
        p.first = INT_MIN;
        p.second = INT_MAX;
        ans.second = p;
        return ans;
    }

    pair<bool, pair<int, int>> leftAns = is_BST2(root->left);
    pair<bool, pair<int, int>> rightAns = is_BST2(root->right);

    pair<bool, pair<int, int>> out;
    out.first = leftAns.first && rightAns.first && root->data > leftAns.second.first && root->data <= rightAns.second.second;
    pair<int, int> p1;
    p1.first = max(root->data, max(leftAns.second.first, rightAns.second.first));
    p1.second = min(root->data, min(leftAns.second.second, rightAns.second.second));
    out.second = p1;
    return out;
}

bool is_BST3(BinaryTreeNode<int> *root, int min = INT_MIN, int max = INT_MAX)
{
    if (root == nullptr)
    {
        return true;
    }

    if (root->data < min || root->data > max)
    {
        return false;
    }

    bool leftAns = is_BST3(root->left, min, root->data - 1);
    bool rightAns = is_BST3(root->right, root->data, max);

    return leftAns && rightAns;
}

/* ---------------------- create bst from sorted array ---------------------- */
BinaryTreeNode<int> *makeTreeUsingArr(int *arr, int si, int ei)
{
    if (si > ei)
    {
        return nullptr;
    }
    int mid = (ei - si) / 2 + si;
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(arr[mid]);

    BinaryTreeNode<int> *leftAns = makeTreeUsingArr(arr, si, mid - 1);
    BinaryTreeNode<int> *rightAns = makeTreeUsingArr(arr, mid + 1, ei);

    root->left = leftAns;
    root->right = rightAns;

    return root;
}

/* --------------------------- BST to linked list --------------------------- */
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

pair<Node<int> *, Node<int> *> makeLLUsingBst(BinaryTreeNode<int> *root)
{
    if (root == nullptr)
    {
        pair<Node<int> *, Node<int> *> p;
        p.first = nullptr;
        p.second = nullptr;
        return p;
    }

    Node<int> *newNode = new Node<int>(root->data);
    pair<Node<int> *, Node<int> *> leftAns = makeLLUsingBst(root->left);
    pair<Node<int> *, Node<int> *> rightAns = makeLLUsingBst(root->right);

    pair<Node<int> *, Node<int> *> ans;

    if (leftAns.first == nullptr && rightAns.first == nullptr)
    {
        ans.first = newNode;
        ans.second = newNode;
    }
    else if (leftAns.first != nullptr && rightAns.first == nullptr)
    {
        leftAns.second->next = newNode;
        ans.first = leftAns.first;
        ans.second = newNode;
    }
    else if (leftAns.first == nullptr && rightAns.first != nullptr)
    {
        newNode->next = rightAns.first;
        ans.first = newNode;
        ans.second = rightAns.second;
    }
    else
    {
        leftAns.second->next = newNode;
        newNode->next = rightAns.first;
        ans.first = leftAns.first;
        ans.second = rightAns.second;
    }
    return ans;
}

void printLL(Node<int> *head)
{
    while (head != nullptr)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << "\n";
}

/* ---------------------------- root to node path --------------------------- */
vector<int> *rootToNodePath(BinaryTreeNode<int> *root, int ele)
{
    if (root == nullptr)
    {
        return nullptr;
    }

    if (root->data == ele)
    {
        vector<int> *out = new vector<int>();
        out->push_back(root->data);
        return out;
    }

    vector<int> *leftAns = rootToNodePath(root->left, ele);
    if (leftAns)
    {
        leftAns->push_back(root->data);
        return leftAns;
    }

    vector<int> *rightAns = rootToNodePath(root->right, ele);
    if (rightAns)
    {
        rightAns->push_back(root->data);
        return rightAns;
    }

    return nullptr;
}

int main()
{

    BinaryTreeNode<int> *root = makeTree();
    // int arr[] = {1, 2, 3, 4, 5, 6, 7};
    // pair<Node<int> *, Node<int> *> ans = makeLLUsingBst(root);
    // printLL(ans.first);
    vector<int> *arr = rootToNodePath(root, 7);
    for (int i = 0; i < arr->size(); i++)
    {
        cout << arr->at(i) << " ";
    }
    // BinaryTreeNode<int> *root = makeTreeUsingArr(arr, 0, 6);
    // cout << findElement(root, 5) << endl;
    // cout << is_BST1(root);
    // pair<bool, pair<int, int>> p = is_BST2(root);
    // cout << p.first << " " << p.second.first << " " << p.second.second << endl;
    // cout << is_BST3(root) << endl;
    // printBST(root);
    delete root;
    return 0;
}