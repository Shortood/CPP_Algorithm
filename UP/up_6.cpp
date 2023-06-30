#include <iostream>

using namespace std;
int **map, **chk;
int dfs(int x, int y, int d, int cnt)
{
    //cout << "x, y : " << x << " " << y << endl;
    //cout << "cnt : " << cnt << endl;
    int td, tchk, mchk, bchk, i;
    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
    int bdx[4] = {1, 0, -1, 0}, bdy[4] = {0, -1, 0, 1};
    td = d;
    for (i = 0; i < 4; i++)
    {
        d = d - 1;
        if (d == -1)
            d = 3;
        // cout << "td : " << td << endl;
        if (d == 0)
        { //북
            mchk = map[x + dx[d]][y + dy[d]];
            tchk = chk[x + dx[d]][y + dy[d]];
        }
        else if (d == 1)
        { //동
            mchk = map[x + dx[d]][y + dy[d]];
            tchk = chk[x + dx[d]][y + dy[d]];
        }
        else if (d == 2)
        { //남
            mchk = map[x + dx[d]][y + dy[d]];
            tchk = chk[x + dx[d]][y + dy[d]];
        }
        else if (d == 3)
        { //서
            mchk = map[x + dx[d]][y + dy[d]];
            tchk = chk[x + dx[d]][y + dy[d]];
        }
        // cout << "m & t " << mchk << " " << tchk << endl;
        if (tchk == 0 && mchk == 0)
        {
            chk[x + dx[d]][y + dy[d]] = 1;
            return dfs(x + dx[d], y + dy[d], d, cnt + 1);
        }
    }
    // cout << "i : " << i << endl;
    if (i == 4)
    { // 4방향 막힘
        //cout << "d : " << d << endl;
        if (d == 0)
        { //북
            bchk = map[x + bdx[d]][y + bdy[d]];
        }
        else if (d == 1)
        { //동
            bchk = map[x + bdx[d]][y + bdy[d]];
        }
        else if (d == 2)
        { //남
            bchk = map[x + bdx[d]][y + bdy[d]];
        }
        else if (d == 3)
        { //서
            bchk = map[x + bdx[d]][y + bdy[d]];
        }
        if (bchk == 0)
        {
            //cout << "back" << endl;
            return dfs(x + bdx[d], y + bdy[d], d, cnt);
        }
        else
            return cnt;
    }
}

int main()
{
    int N, M, r, c, d;

    cin >> N >> M;
    cin >> r >> c >> d;
    map = new int *[N];
    chk = new int *[N];
    for (int i = 0; i < N; i++)
    {
        map[i] = new int[M];
        chk[i] = new int[M];
        for (int j = 0; j < M; j++)
        {
            chk[i][j] = 0;
            cin >> map[i][j];
        }
    }
    chk[r][c] = 1;
    cout << dfs(r, c, d, 1) << endl;
}