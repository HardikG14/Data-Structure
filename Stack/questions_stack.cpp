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

void reverseSentence(string sentence)
{
    stack<string> s;
    for (int i = 0; i < sentence.size(); i++)
    {
        string str = "";
        while (sentence[i] != ' ' && i != sentence.size())
        {
            // string str="";
            str.push_back(sentence[i]);
            i++;
        }
        s.push(str);
    }

    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
}

void printStack(stack<int> s)
{
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
}

void insertAtBottom(stack<int> &st, int ele)
{
    if (st.empty())
    {
        st.push(ele);
        return;
    }
    int top = st.top();
    st.pop();
    insertAtBottom(st, ele);
    st.push(top);
}

void reverseStack(stack<int> &s)
{
    if (s.empty())
    {
        return;
    }

    int topE = s.top();
    s.pop();
    reverseStack(s);
    insertAtBottom(s, topE);
}

int prefixEvaluation(string str)
{
    stack<int> st;
    for (int i = str.size() - 1; i >= 0; i--)
    {
        if (str[i] >= '0' && str[i] <= '9')
        {
            st.push(str[i] - '0');
        }
        else
        {
            int op1 = st.top();
            st.pop();
            int op2 = st.top();
            st.pop();

            switch (str[i])
            {
            case '+':
                /* code */
                st.push(op1 + op2);
                break;

            case '*':
                st.push(op1 * op2);
                break;

            case '/':
                st.push(op1 / op2);
                break;

            case '-':
                st.push(op1 - op2);
                break;

            case '^':
                st.push(op1 ^ op2);
                break;
            }
        }
    }
    return st.top();
}

int postfixEvaluation(string str)
{
    stack<int> st;

    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] >= '0' && str[i] <= '9')
        {
            st.push(str[i] - '0');
        }
        else
        {
            int op2 = st.top();
            st.pop();
            int op1 = st.top();
            st.pop();
            switch (str[i])
            {
            case '+':
                /* code */
                st.push(op1 + op2);
                break;

            case '*':
                st.push(op1 * op2);
                break;

            case '/':
                st.push(op1 / op2);
                break;

            case '-':
                st.push(op1 - op2);
                break;

            case '^':
                st.push(op1 ^ op2);
                break;
            }
        }
    }
    return st.top();
}

/* ---------------------------- valid Parenthesis --------------------------- */
bool isValid(string s)
{
    int size = s.size();
    if (size % 2 != 0)
    {
        return false;
    }

    stack<char> sta;
    for (int i = 0; i < size; i++)
    {
        if (s[i] == '{' || s[i] == '[' || s[i] == '(')
        {
            sta.push(s[i]);
        }
        else
        {
            if (!sta.empty() && (s[i] == '}' && sta.top() == '{'))
            {
                sta.pop();
            }
            else if (!sta.empty() && (s[i] == ']' && sta.top() == '['))
            {
                sta.pop();
            }
            else if (!sta.empty() && (s[i] == ')' && sta.top() == '('))
            {
                sta.pop();
            }
            else
            {
                return false;
            }
        }
    }
    if (!sta.empty())
    {
        return false;
    }
    else
    {
        return true;
    }
}

bool isOperator(char ch)
{
    if (ch == '-' || ch == '*' || ch == '/' || ch == '(' || ch == '+')
    {
        return true;
    }

    return false;
}

bool redundantParenthesis(string str)
{
    stack<char> sta;
    int size = str.size();

    for (int i = 0; i < size; i++)
    {
        if (isOperator(str[i]))
        {
            sta.push(str[i]);
        }
        else if (str[i] == ')')
        {
            if (sta.top() == '(')
            {
                return true;
            }
            else
            {
                while (sta.top() != '(')
                {
                    sta.pop();
                }
                sta.pop();
            }
        }
    }
    return false;
}

/* ---------------------------- infix to postfix ---------------------------- */
int precedence(char ch)
{
    if (ch == '^')
    {
        return 3;
    }
    else if (ch == '*' || ch == '/')
    {
        return 2;
    }
    else if (ch == '+' || ch == '-')
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

void infixToPostfix(string s)
{
    int size = s.size();
    stack<char> st;

    rep(i, 0, size)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
        {
            cout << s[i];
        }
        else if (s[i] == '(')
        {
            st.push('(');
        }
        else if (s[i] == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                cout << st.top();
                st.pop();
            }
            if (!st.empty())
            {
                st.pop();
            }
        }
        else
        {
            while (!st.empty() && (precedence(st.top()) > precedence(s[i])))
            {
                cout << st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }

    while (!st.empty())
    {
        cout << st.top();
        st.pop();
    }
}

int main()
{

    // reverseSentence("My name is Hardik");
    // stack<int> stac;

    // stac.push(1);
    // stac.push(2);
    // stac.push(3);
    // stac.push(4);
    // // insertAtBottom(stac, 100);
    // reverseStack(stac);
    // printStack(stac);
    // cout << postfixEvaluation("46+2/5*7+");
    // cout << isValid("{}");
    // cout << redundantParenthesis("((+(a+b)*)");
    infixToPostfix("(l-k/a)*(c/b-a)");
    return 0;
}