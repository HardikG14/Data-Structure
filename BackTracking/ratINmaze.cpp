// rat in a maze
#include <bits/stdc++.h>
using namespace std;

int grid[10][10];

// print grid func
void printGrid(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}

void helper(int maze[][10], int n, int i, int j)
{
    if (maze[i][j] == 0 || grid[i][j] == 1 || i == n || i == -1 || j == n || j == -1)
    {
        return;
    }

    if (i == n - 1 && j == n - 1)
    {
        grid[i][j] = 1;
        printGrid(n);
        cout << '\n';
        grid[i][j] = 0;
        return;
    }
    grid[i][j] = 1;
    helper(maze, n, i - 1, j);
    helper(maze, n, i + 1, j);
    helper(maze, n, i, j + 1);
    helper(maze, n, i, j - 1);
    grid[i][j] = 0;
}
void ratInMaze(int maze[][10], int n)
{
    return helper(maze, n, 0, 0);
}

int main()
{
    int maze[10][10];
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> maze[i][j];
        }
    }
    ratInMaze(maze, 3);
    return 0;
}
