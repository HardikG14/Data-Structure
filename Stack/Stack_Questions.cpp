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

bool balancedParenthesis(string s)
{
    stack<char> st;
    rep(i, 0, s.length())
    {
        if (s[i] == '(')
        {
            st.push('(');
        }
        else
        {
            if (st.empty())
            {
                return false;
            }
            else
            {
                st.pop();
            }
        }
    }
    if (!st.empty())
    {
        return false;
    }
    else
    {
        return true;
    }
}

void reverseSen(string s)
{
    stack<string> st;
    for (int i = 0; i < s.size(); i++)
    {
        string str;
        while (s[i] != ' ' && i < s.length())
        {
            str.push_back(s[i]);
            i++;
        }
        st.push(str);
    }
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
}

void insertAtStackEnd(stack<int> &st, int ele)
{
    if (st.empty())
    {
        st.push(ele);
        return;
    }
    int curr = st.top();
    st.pop();
    insertAtStackEnd(st, ele);
    st.push(curr);
}

void reverseStack(stack<int> &st)
{
    if (st.size() == 1)
    {
        return;
    }
    int curr = st.top();
    st.pop();
    reverseStack(st);
    insertAtStackEnd(st, curr);
}

void printStack(stack<int> &s)
{
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << "\n";
}

/* ---------------------------- prefix evaluation --------------------------- */
int prefixEval(string s)
{
    stack<int> sta;
    for (int i = s.size() - 1; i >= 0; i--)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            sta.push(s[i] - '0');
        }
        else
        {
            int op1 = sta.top();
            sta.pop();
            int op2 = sta.top();
            sta.pop();

            switch (s[i])
            {
            case '+':
                sta.push(op1 + op2);
                break;

            case '-':
                sta.push(op1 - op2);
                break;

            case '*':
                sta.push(op1 * op2);
                break;
            case '/':
                sta.push(op1 / op2);
                break;

            case '^':
                sta.push(pow(op1, op2));
                break;
            }
        }
    }
    return sta.top();
}

int postfixEval(string s)
{
    stack<int> sta;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            sta.push(s[i] - '0');
        }
        else
        {
            int op2 = sta.top();
            sta.pop();
            int op1 = sta.top();
            sta.pop();

            switch (s[i])
            {
            case '+':
                sta.push(op1 + op2);
                break;
            case '-':
                sta.push(op1 - op2);
                break;
            case '*':
                sta.push(op1 * op2);
                break;
            case '/':
                sta.push(op1 / op2);
                break;
            case '^':
                sta.push(pow(op1, op2));
                break;
            }
        }
    }
    return sta.top();
}

/* ---------------------------- infix to postfox ---------------------------- */
int prec(char ch)
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
    stack<char> sta;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
        {
            cout << s[i];
        }
        else if (s[i] == '(')
        {
            sta.push('(');
        }
        else if (s[i] == ')')
        {
            while (!sta.empty() && sta.top() != '(')
            {
                cout << sta.top();
                sta.pop();
            }
            if (!sta.empty())
            {
                sta.pop();
            }
        }
        else
        {
            while (!sta.empty() && prec(sta.top()) > prec(s[i]))
            {
                cout << sta.top();
                sta.pop();
            }
            sta.push(s[i]);
        }
    }

    while (!sta.empty())
    {
        cout << sta.top();
        sta.pop();
    }
}
int main()
{

    // cout << balancedParenthesis("()()(()") << endl;
    // reverseSen("Hey, How are you doing?");
    // stack<int> st;
    // st.push(1);
    // st.push(2);
    // st.push(3);
    // st.push(4);
    // cout << prefixEval("+*423") << endl;
    // cout << postfixEval("46+2/5*7+") << endl;
    infixToPostfix("(a-b/c)*(a/k-l)");
    // // reverseStack(st);
    // insertAtStackEnd(st, 0);
    // insertAtStackEnd(st, 1);
    // printStack(st);
    // "(()()())"

    return 0;
}