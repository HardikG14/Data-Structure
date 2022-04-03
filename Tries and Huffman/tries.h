#include <bits/stdc++.h>
using namespace std;

class TrieNode
{
public:
    char data;
    TrieNode **children;
    bool isTerminal;

    TrieNode(char data)
    {
        this->data = data;
        children = new TrieNode *[26];
        for (int i = 0; i < 26; i++)
        {
            children[i] = nullptr;
        }
        isTerminal = false;
    }
};

class Trie
{
    // private:
public:
    TrieNode *root;

public:
    Trie()
    {
        root = new TrieNode('\0');
    }

private:
    void insertWord(TrieNode *root, string str)
    {
        // base case
        if (str.size() == 0)
        {
            root->isTerminal = true;
            return;
        }

        // small calculation
        char ch = str[0];
        if (root->children[ch - 'a'] == nullptr)
        {
            TrieNode *newNode = new TrieNode(ch);
            root->children[ch - 'a'] = newNode;
            insertWord(newNode, str.substr(1));
        }
        else
        {
            TrieNode *newRoot = root->children[ch - 'a'];
            insertWord(newRoot, str.substr(1));
        }
    }

    bool searchInTrie(TrieNode *root, string str)
    {
        if (str.size() == 0)
        {
            return root->isTerminal;
        }

        char ch = str[0];
        string newStr = str.substr(1);
        if (root->children[ch - 'a'] == nullptr)
        {
            return false;
        }

        TrieNode *newNode = root->children[ch - 'a'];
        return searchInTrie(newNode, newStr);
    }

    void removeFromTrie(TrieNode *root, string str)
    {
        if (str.size() == 0)
        {
            root->isTerminal = false;
            return;
        }

        char ch = str[0];
        if (root->children[ch - 'a'] == nullptr)
        {
            return;
        }
        TrieNode *smallAns = root->children[ch - 'a'];
        string sstr = str.substr(1);
        removeFromTrie(smallAns, sstr);
    }

public:
    void insert(string str)
    {
        insertWord(root, str);
    }

    bool search(string str)
    {
        return searchInTrie(root, str);
    }

    void remove(string str)
    {
        removeFromTrie(root, str);
    }
};