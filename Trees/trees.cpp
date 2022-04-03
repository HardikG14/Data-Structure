#include <bits/stdc++.h>
#include "TreeNode_Class.h"
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
#define null nullptr

const long long INF = 1e18;
const int32_t M = 1e9 + 7;
const int32_t MM = 998244353;
const int N = 0;

void printTree2(TreeNode<int> *root)
{
    if (root == null)
    {
        return;
    }
    cout << root->data << " :";
    for (int i = 0; i < root->children.size(); i++)
    {
        cout << root->children[i]->data << ", ";
    }
    cout << "\n";
    for (int i = 0; i < root->children.size(); i++)
    {
        printTree2(root->children[i]);
    }
}

void printTree(TreeNode<int> *root)
{
    queue<TreeNode<int> *> que;
    que.push(root);
    while (!que.empty())
    {
        TreeNode<int> *front = que.front();
        que.pop();
        cout << front->data << " :";
        for (int i = 0; i < front->children.size(); i++)
        {
            cout << front->children[i]->data << ", ";
            que.push(front->children[i]);
        }
        cout << endl;
    }
}

TreeNode<int> *makeTree1()
{
    int data;
    cout << "enter Data : ";
    cin >> data;
    TreeNode<int> *root = new TreeNode<int>(data);
    int chi;
    cout << "Enter No of children of " << data << " :";
    cin >> chi;
    for (int i = 0; i < chi; i++)
    {
        TreeNode<int> *temp = makeTree1();
        root->children.push_back(temp);
    }
    return root;
}

TreeNode<int> *makeTree()
{
    int data;
    cout << "Enter root node data :";
    cin >> data;
    TreeNode<int> *root = new TreeNode<int>(data);
    queue<TreeNode<int> *> q;
    q.push(root);
    while (!q.empty())
    {
        TreeNode<int> *front = q.front();
        q.pop();
        int n;
        cout << "Enter no of children of " << front->data << " :";
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            int newData;
            cout << "enter " << i + 1 << " children data of " << front->data << " :";
            cin >> newData;
            TreeNode<int> *newNode = new TreeNode<int>(newData);
            front->children.push_back(newNode);
            q.push(newNode);
        }
    }

    return root;
}

/* ----------------------- count no of nodes of trees ----------------------- */
// recursive
int countNodes(TreeNode<int> *root)
{
    int count = 1;
    for (int i = 0; i < root->children.size(); i++)
    {
        count += countNodes(root->children[i]);
    }
    return count;
}

/* ---------------------------- sum of all nodes ---------------------------- */
int sumOfAllNodes(TreeNode<int> *root)
{
    int ans = root->data;
    for (int i = 0; i < root->children.size(); i++)
    {
        ans += sumOfAllNodes(root->children[i]);
    }
    return ans;
}

/* ---------------------------- max of all nodes ---------------------------- */
int maxInTree(TreeNode<int> *root)
{
    int max = root->data;
    for (int i = 0; i < root->children.size(); i++)
    {
        int m2 = maxInTree(root->children[i]);
        if (m2 > max)
        {
            max = m2;
        }
    }
    return max;
}

TreeNode<int> *maxInTree1(TreeNode<int> *root)
{
    TreeNode<int> *max = root;
    for (int i = 0; i < root->children.size(); i++)
    {
        TreeNode<int> *newMax = maxInTree1(root->children[i]);
        if (newMax->data > max->data)
        {
            max = newMax;
        }
    }
    return max;
}

/* -------------------------- return height of tree ------------------------- */
int heightOfTree(TreeNode<int> *root)
{
    int hei = 0;
    for (int i = 0; i < root->children.size(); i++)
    {
        int hei1 = heightOfTree(root->children[i]);
        hei = max(hei, hei1);
    }
    return hei + 1;
}

/* ------------------------- print nodes at depth i ------------------------- */
void printNodesAtIthDepth(TreeNode<int> *root, int k)
{
    if (root == nullptr)
    {
        return;
    }
    if (k == 0)
    {
        cout << root->data << " ";
        return;
    }

    for (int i = 0; i < root->children.size(); i++)
    {
        printNodesAtIthDepth(root->children[i], k - 1);
    }
}

/* ---------------------------- no of leaf nodes ---------------------------- */
int noOfLeafNodes(TreeNode<int> *root)
{
    if (root->children.size() == 0)
    {
        return 1;
    }

    int count = 0;
    for (int i = 0; i < root->children.size(); i++)
    {
        count += noOfLeafNodes(root->children[i]);
    }
    return count;
}

/* -------------------------------- traversal ------------------------------- */
void preOrderPrinting(TreeNode<int> *root)
{
    cout << root->data << endl;
    for (int i = 0; i < root->children.size(); i++)
    {
        preOrderPrinting(root->children[i]);
    }
}

void postOrderPrinting(TreeNode<int> *root)
{
    for (int i = 0; i < root->children.size(); i++)
    {
        postOrderPrinting(root->children[i]);
    }
    cout << root->data << " ";
}

/* ---------------------- check if x is present in tree --------------------- */
bool isXPresent(TreeNode<int> *root, int x)
{
    if (root->data == x)
    {
        return true;
    }
    for (int i = 0; i < root->children.size(); i++)
    {
        bool ispre = isXPresent(root->children[i], x);
        if (ispre)
        {
            return true;
        }
    }

    return false;
}

int getLargeNodeCount(TreeNode<int> *root, int x)
{
    int count;
    if (root->data > x)
    {
        count = 1;
    }
    else
    {
        count = 0;
    }
    for (int i = 0; i < root->children.size(); i++)
    {
        count += getLargeNodeCount(root->children[i], x);
    }

    return count;
}
/* ---------------------- max sum of node and children ---------------------- */
TreeNode<int> *maxSumNode(TreeNode<int> *root)
{
    TreeNode<int> *ans = root;
    int sum = root->data;
    for (int i = 0; i < root->children.size(); i++)
    {
        sum += root->children[i]->data;
    }

    for (int i = 0; i < root->children.size(); i++)
    {
        TreeNode<int> *smallAns = maxSumNode(root->children[i]);
        int smallSum = smallAns->data;
        for (int j = 0; j < smallAns->children.size(); j++)
        {
            smallSum += smallAns->children[j]->data;
        }

        if (smallSum > sum)
        {
            sum = smallSum;
            ans = smallAns;
        }
    }
    return ans;
}

/* ------------------------- structurally equal tree ------------------------ */
bool areIdentical(TreeNode<int> *root1, TreeNode<int> *root2)
{
    queue<TreeNode<int> *> q1;
    queue<TreeNode<int> *> q2;

    q1.push(root1);
    q2.push(root2);

    while (!q1.empty() && !q2.empty())
    {
        TreeNode<int> *front1 = q1.front();
        TreeNode<int> *front2 = q2.front();
        q1.pop();
        q2.pop();

        if (front1->data != front2->data)
        {
            return false;
        }

        for (int i = 0; i < front1->children.size(); i++)
        {
            q1.push(front1->children[i]);
        }

        for (int i = 0; i < front2->children.size(); i++)
        {
            q2.push(front2->children[i]);
        }

        if (q1.size() != q2.size())
        {
            return false;
        }
    }

    if (!q1.empty() || !q2.empty())
    {
        return false;
    }

    return true;
}

/* ------------------------------- next larger ------------------------------ */
TreeNode<int> *getNextLargerElement(TreeNode<int> *root, int x)
{
    if (root->data > x)
    {
        return root;
    }

    TreeNode<int> *ans = nullptr;
    for (int i = 0; i < root->children.size(); i++)
    {
        TreeNode<int> *smallAns = getNextLargerElement(root->children[i], x);
        if (ans == nullptr)
        {
            ans = smallAns;
        }
    }
    return ans;
}

/* ----------------------- second maximum in the tree ----------------------- */

class Pair
{
public:
    TreeNode<int> *l;
    TreeNode<int> *sl;

    Pair(TreeNode<int> *l, TreeNode<int> *sl)
    {
        this->l = l;
        this->sl = sl;
    }
};

Pair secondLargest(TreeNode<int> *root)
{
    Pair ans(root, null);
    for (int i = 0; i < root->children.size(); i++)
    {
        Pair child = secondLargest(root->children[i]);
        if (child.l->data > ans.l->data)
        {
            if (child.sl == NULL)
            {
                ans.sl = ans.l;
                ans.l = child.l;
            }
            else
            {
                if (child.sl->data > ans.l->data)
                {
                    ans.sl = child.sl;
                    ans.l = child.l;
                }
                else
                {
                    ans.sl = ans.l;
                    ans.l = child.l;
                }
            }
        }
        else
        {
            if (ans.l->data != child.l->data && (ans.sl == NULL || child.l->data > ans.sl->data))
            {
                ans.sl = child.l;
            }
        }
    }

    return ans;
}

/* ------------------------- replace data with depth ------------------------ */
void replaceWithDepth(TreeNode<int> *root, int x = 0)
{
    root->data = x;
    for (int i = 0; i < root->children.size(); i++)
    {
        replaceWithDepth(root->children[i], x + 1);
    }
}

vector<TreeNode<int> *> incev(TreeNode<int> *head)
{
    vector<TreeNode<int> *> v;
    if (head->children.size() == 0)
    {
        v.push_back(head);
    }

    for (int i = 0; i < head->children.size(); i++)
    {
        vector<TreeNode<int> *> smallAns = incev(head->children[i]);
        for (int j = 0; j < smallAns.size(); j++)
        {
            v.push_back(smallAns[j]);
        }
    }

    return v;
}

int main()
{
    TreeNode<int> *root = makeTree();
    // TreeNode<int> *root2 = makeTree();
    // TreeNode<int> *max = maxInTree1(root);
    // cout << max->data << endl;
    // cout << heightOfTree(root) << endl;
    // printNodesAtIthDepth(root, 2);
    vector<TreeNode<int> *> ans = incev(root);

    for (auto &val : ans)
    {
        cout << val->data << " ";
    }

    // cout << ans.size() << endl;
    // replaceWithDepth(root);
    // printTree(root);

    // cout << noOfLeafNodes(root);
    // cout << getLargeNodeCount(root, 2);
    // TreeNode<int> *ans = maxSumofNodeNChildren(root);
    // cout << ans->data << endl;
    // cout << areIdentical(root, root2);
    // 5 3 1 2 3 1 15 2 4 5 1 6 0 0 0 0
}