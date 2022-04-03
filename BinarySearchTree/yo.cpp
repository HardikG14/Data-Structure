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

int main()
{

    // gross salary = basic + HRA + DA + TA
    string emp_name;
    cout << "Employee Name : ";
    cin >> emp_name;
    string emp_type;
    cout << "Employee Type : ";
    cin >> emp_type;

    string emp_desg;
    string emp_noe;
    double reg;
    if (emp_type == "Teaching")
    {
        cout << "Employee Designation :";
        cin >> emp_desg;
        if (emp_desg == "Professor")
        {
            cout << "Nature Of Employee :";
            cin >> emp_noe;
            if (emp_noe == "Regular")
            {
                reg = 100000;
            }
            else if (emp_noe == "Contractual")
            {
                reg = 70000;
            }
        }
        else if (emp_desg == "AssociateProfessor")
        {
            cout << "Nature Of Employee :";
            cin >> emp_noe;
            if (emp_noe == "Regular")
            {
                reg = 80000;
            }
            else if (emp_noe == "Contractual")
            {
                reg = 50000;
            }
        }
        else if (emp_desg == "AssistantProfessor")
        {
            cout << "Nature Of Employee :";
            cin >> emp_noe;
            if (emp_noe == "Regular")
            {
                reg = 60000;
            }
            else if (emp_noe == "Contractual")
            {
                reg = 30000;
            }
        }
    }
    else if (emp_type == "Non-Teaching")
    {
        cout << "Employee Designation :";
        cin >> emp_desg;
        if (emp_desg == "Clerk")
        {
            cout << "Nature Of Employee :";
            cin >> emp_noe;
            if (emp_noe == "Regular")
            {
                reg = 40000;
            }
            else if (emp_noe == "Contractual")
            {
                reg = 25000;
            }
        }
        else if (emp_desg == "Engineer")
        {
            cout << "Nature Of Employee :";
            cin >> emp_noe;
            if (emp_noe == "Regular")
            {
                reg = 30000;
            }
            else if (emp_noe == "Contractual")
            {
                reg = 20000;
            }
        }
        else if (emp_desg == "Helper")
        {
            cout << "Nature Of Employee :";
            cin >> emp_noe;
            if (emp_noe == "Regular")
            {
                reg = 20000;
            }
            else if (emp_noe == "Contractual")
            {
                reg = 15000;
            }
        }
    }

    double HRA, TA, DA, gross;
    cout << "Employee Name :" << emp_name << endl;
    cout << "Employee Type :" << emp_type << endl;
    cout << "employee Designation :" << emp_desg << endl;
    cout << "Nature Of Employement :" << emp_noe << endl;
    HRA = 0.2 * reg;
    DA = 0.1 * reg;
    if (emp_noe == "Contractual")
    {
        TA = 0.03 * reg;
    }
    else if (emp_noe == "Regular")
    {
        TA = 0.05 * reg;
    }
    gross = reg + HRA + TA + DA;
    cout << "Gross Salary :" << gross << endl;
    return 0;
}