#include <bits/stdc++.h>
#include "bst_node.h"
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

BinaryTreeNode<int> *makeTree()
{
    int data;
    cout << "Enter Root Data! :";
    cin >> data;

    if (data == -1)
    {
        return nullptr;
    }
    BinaryTreeNode<int> *head = new BinaryTreeNode<int>(data);
    queue<BinaryTreeNode<int> *> nodeQue;
    nodeQue.push(head);

    while (!nodeQue.empty())
    {
        BinaryTreeNode<int> *front = nodeQue.front();
        nodeQue.pop();

        int leftData;
        cout << "Enter Left Child Data Of " << front->data << ":";
        cin >> leftData;

        if (leftData != -1)
        {
            BinaryTreeNode<int> *newNode = new BinaryTreeNode<int>(leftData);
            front->left = newNode;
            nodeQue.push(newNode);
        }

        int rightData;
        cout << "Enter RightChild Data Of " << front->data << ":";
        cin >> rightData;

        if (rightData != -1)
        {
            BinaryTreeNode<int> *newNode = new BinaryTreeNode<int>(rightData);
            front->right = newNode;
            nodeQue.push(newNode);
        }
    }

    return head;
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

/* --------------------------- find element in Bst -------------------------- */
bool findKinBST(BinaryTreeNode<int> *root, int k)
{
    if (root == nullptr)
    {
        return false;
    }
    if (root->data == k)
    {
        return true;
    }

    bool ans;
    if (k < root->data)
    {
        ans = findKinBST(root->left, k);
    }

    if (k > root->data)
    {
        ans = findKinBST(root->right, k);
    }

    return ans;
}

/* --------------------------- print between range -------------------------- */
void printBetweenRange(BinaryTreeNode<int> *root, int i, int j)
{
    if (root == nullptr)
    {
        return;
    }

    if (root->data >= i && root->data <= j)
    {
        cout << root->data << " ";
        printBetweenRange(root->left, i, j);
        printBetweenRange(root->right, i, j);
    }
    else if (j < root->data)
    {
        printBetweenRange(root->left, i, j);
    }
    else if (i > root->data)
    {
        printBetweenRange(root->right, i, j);
    }
}

/* ------------------------------- max in tree ------------------------------ */
int maxInTree(BinaryTreeNode<int> *root)
{
    if (root == nullptr)
    {
        return INT_MIN;
    }
    int leftMax = maxInTree(root->left);
    int rightMax = maxInTree(root->right);

    return max(root->data, max(leftMax, rightMax));
}

int minInTree(BinaryTreeNode<int> *root)
{
    if (root == nullptr)
    {
        return INT_MAX;
    }

    int leftMin = minInTree(root->left);
    int rightMin = minInTree(root->right);

    return min(root->data, min(leftMin, rightMin));
}

pair<int, int> minNmax(BinaryTreeNode<int> *root)
{
    if (root == nullptr)
    {
        pair<int, int> p;
        p.first = INT_MAX;
        p.second = INT_MIN;
        return p;
    }

    pair<int, int> leftAns = minNmax(root->left);
    pair<int, int> rightAns = minNmax(root->right);

    pair<int, int> ans;
    ans.first = min(root->data, min(leftAns.first, rightAns.first));
    ans.second = max(root->data, max(leftAns.second, rightAns.second));
    return ans;
}

/* -------------------------------- is BST-1 -------------------------------- */
bool isBst1(BinaryTreeNode<int> *root)
{
    if (root == nullptr)
    {
        return true;
    }
    int leftMax = maxInTree(root->left);
    int rightMin = minInTree(root->right);

    bool output = (root->data > leftMax) && (root->data <= rightMin) && (isBst1(root->left)) && (isBst1(root->right));

    return output;
}

pair<bool, pair<int, int>> isBST2(BinaryTreeNode<int> *root)
{
    if (root == nullptr)
    {
        pair<bool, pair<int, int>> p;
        p.first = true;
        pair<int, int> p2;
        p2.first = INT_MIN;
        p2.second = INT_MAX;
        p.second = p2;
        return p;
    }

    pair<bool, pair<int, int>> leftAns = isBST2(root->left);
    pair<bool, pair<int, int>> rightAns = isBST2(root->right);

    bool output = root->data > leftAns.second.first && root->data <= rightAns.second.second && leftAns.first && rightAns.first;

    pair<bool, pair<int, int>> Ans;
    Ans.first = output;
    pair<int, int> p;
    p.first = max(root->data, max(leftAns.second.first, rightAns.second.first));
    p.second = min(root->data, min(leftAns.second.second, rightAns.second.second));
    Ans.second = p;
    return Ans;
}

bool isBST3(BinaryTreeNode<int> *root, int min = INT_MIN, int max = INT_MAX)
{
    if (root == nullptr)
    {
        return true;
    }
    if (root->data < min || root->data > max)
    {
        return false;
    }

    bool isLeftOk = isBST3(root->left, min, root->data - 1);
    bool isRightOk = isBST3(root->right, root->data, max);

    return isRightOk && isLeftOk;
}

//* -------------------------- bst from sorted array ------------------------- */
BinaryTreeNode<int> *treeFromArr(int *arr, int si, int ei)
{
    if (si > ei)
    {
        return nullptr;
    }
    int mid = (ei - si) / 2 + si;
    BinaryTreeNode<int> *head = new BinaryTreeNode<int>(arr[mid]);
    BinaryTreeNode<int> *leftTree = treeFromArr(arr, si, mid - 1);
    BinaryTreeNode<int> *rightTree = treeFromArr(arr, mid + 1, ei);
    head->left = leftTree;
    head->right = rightTree;

    return head;
}

/* -------------------------- linked list from BST -------------------------- */
class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }

    ~Node()
    {
        delete this->next;
    }
};

pair<Node *, Node *> llfromBST(BinaryTreeNode<int> *root)
{
    if (root == nullptr)
    {
        pair<Node *, Node *> p;
        p.first = nullptr;
        p.second = nullptr;
        return p;
    }
    Node *newNode = new Node(root->data);
    pair<Node *, Node *> leftAns = llfromBST(root->left);
    pair<Node *, Node *> rightAns = llfromBST(root->right);

    pair<Node *, Node *> ans;
    if (leftAns.first == nullptr && rightAns.first == nullptr)
    {
        ans.first = newNode;
        ans.second = newNode;
    }
    else if (leftAns.first == nullptr && rightAns.first != nullptr)
    {
        newNode->next = rightAns.first;
        ans.first = newNode;
        ans.second = rightAns.second;
    }
    else if (leftAns.first != nullptr && rightAns.first == nullptr)
    {
        leftAns.second->next = newNode;
        ans.first = leftAns.first;
        ans.second = newNode;
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

void printLL(Node *head)
{
    while (head != nullptr)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

/* ------------------------------ Path to node ------------------------------ */
vector<int> *pathToNode(BinaryTreeNode<int> *root, int data)
{
    if (root == nullptr)
    {
        return nullptr;
    }

    if (root->data == data)
    {
        vector<int> *ans = new vector<int>();
        ans->push_back(root->data);
        return ans;
    }

    vector<int> *leftAns = pathToNode(root->left, data);
    if (leftAns != nullptr)
    {
        leftAns->push_back(root->data);
        return leftAns;
    }

    vector<int> *rightAns = pathToNode(root->right, data);
    if (rightAns != nullptr)
    {
        rightAns->push_back(root->data);
        return rightAns;
    }

    return nullptr;
}

int secondLargest(int a, int b, int c)
{
    int arr[3] = {a, b, c};
    sort(arr, arr + 3);
    return arr[1];
}
int main()
{

    // BinaryTreeNode<int> *root = makeTree();
    // // int a[] = {1, 2, 3, 4, 5, 6, 7, 8};
    // // 4 2 6 1 3 5 7 -1 -1 -1 -1 -1 -1 -1 -1
    // // BinaryTreeNode<int> *root = treeFromArr(a, 0, 7);
    // vector<int> *vec = pathToNode(root, 4);
    // for (int i = 0; i < vec->size(); i++)
    // {
    //     cout << vec->at(i) << " ";
    // }
    cout << secondLargest(12, 32, 10);
    // printBST(root);
    // cout << findKinBST(root, 7);
    // pair<Node *, Node *> ans = llfromBST(root);

    // cout << ans.first << " " << ans.second << endl;
    // printLL(ans.first);
    // cout << "\n";
    // printBetweenRange(root, 3, 5);
    // cout << maxInTree(root);
    // cout << isBst1(root);
    // pair<bool, pair<int, int>> ans = isBST2(root);
    // cout << ans.first << endl;
    // cout << ans.second.first << endl;
    // cout << ans.second.second << endl;
    // delete root;
    return 0;
}