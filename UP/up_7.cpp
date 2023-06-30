#include <iostream>
#include <climits>

using namespace std;
int **S;
int N, result = INT_MAX;
bool *chk;
void dfs(int n, int m)
{
    int start = 0, link = 0;
    if (n == N / 2)
    {
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                if (chk[i] == true && chk[j] == true)
                    start += S[i][j];
                else if (chk[i] == false && chk[j] == false)
                    link += S[i][j];
            }
        }
        int sum = abs(start - link);
        if (sum < result)
            result = sum;
        return;
    }
    for (int i = m; i < N; i++)
    {
        chk[i] = true;
        dfs(n + 1, i + 1);
        chk[i] = false;
    }
}

int main()
{

    cin >> N;

    S = new int *[N + 1];
    chk = new bool[N + 1];
    for (int i = 1; i <= N; i++)
    {
        S[i] = new int[N + 1];
        chk[i] = false;
        for (int j = 1; j <= N; j++)
        {
            cin >> S[i][j];
        }
    }
    dfs(0, 1);
    cout << result << endl;
}