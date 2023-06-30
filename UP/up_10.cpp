#include <iostream>

using namespace std;

int main()
{
    int r, c, t;
    int **map, **t_map;
    int x = -1, y = -1;
    int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
    cin >> r >> c >> t;

    map = new int *[r];
    t_map = new int *[r];
    for (int i = 0; i < r; i++)
    {
        map[i] = new int[c];
        t_map[i] = new int[c];
        for (int j = 0; j < c; j++)
        {
            cin >> map[i][j];
            t_map[i][j] = 0;
            if (map[i][j] == -1)
            {
                if (i > x)
                {
                    x = i;
                    y = j;
                }
            }
        }
    }
    int nx, ny;
    for (int f = 0; f < t; f++)
    {
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                int cnt = 0;
                for (int t = 0; t < 4; t++)
                {
                    nx = i + dx[t];
                    ny = j + dy[t];
                    // cout << nx << " " << ny << " "<<r<<" "<<c<<endl;
                    //  범위 안
                    if (nx >= 0 && ny >= 0 && nx < r && ny < c)
                    {
                        // cout << "map " << map[nx][ny] << endl;
                        if (map[nx][ny] != -1)
                        {
                            cnt++;
                            // cout << "c++ " << cnt << endl;
                            t_map[nx][ny] = t_map[nx][ny] + map[i][j] / 5;
                        }
                    }
                }
                // cout << map[i][j] << " = " << map[i][j] << " - " << ((map[i][j] / 5) * c) << endl;
                map[i][j] = map[i][j] - ((map[i][j] / 5) * cnt);
            }
        }
        //cout << "-------------------" << endl;
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                map[i][j] += t_map[i][j];
                t_map[i][j] = 0;
                //cout << map[i][j] << " ";
            }
            //cout << endl;
        }
        // 바람이동
        // 공기청정기 아래 x-1은 위
        nx = x - 1;
        ny = y;
        int dir = 0; // 오, 위, 왼, 아
        int temp, temp2;
        // 방향 4가지 순서대로
        temp = map[nx][ny];
        while (1)
        {
            if (dir == 0) // 오
            {
                ny++;
                if (ny >= c)
                {
                    ny--;
                    dir++;
                }
            }
            if (dir == 1) // 위
            {
                nx--;
                if (nx < 0)
                {
                    nx++;
                    dir++;
                }
            }
            if (dir == 2) // 왼
            {
                ny--;
                if (ny < 0)
                {
                    ny++;
                    dir++;
                }
            }
            if (dir == 3) // 아
            {
                nx++;
                if (nx >= r)
                {
                    nx--;
                    dir = 0;
                }
            }
            // cout << nx << " " << ny << endl;
            // cout << temp << " / " << map[nx][ny] << endl;
            if (nx == x - 1 && ny == y)
                break;
            temp2 = map[nx][ny];
            if (temp != -1)
            {
                map[nx][ny] = temp;
                temp = temp2;
            }
            else
            {
                map[nx][ny] = 0;
                temp = temp2;
            }

            // cout << nx << " " << ny << endl;
        }
        nx = x;
        ny = y;
        dir = 0; // 오, 아, 왼, 위
        // 방향 4가지 순서대로
        temp = map[nx][ny];
        while (1)
        {

            if (dir == 0) // 오
            {
                ny++;
                if (ny >= c)
                {
                    ny--;
                    dir++;
                }
            }
            if (dir == 1) // 아
            {
                nx++;
                if (nx >= r)
                {
                    nx--;
                    dir++;
                }
            }
            if (dir == 2) // 왼
            {
                ny--;
                if (ny < 0)
                {
                    ny++;
                    dir++;
                }
            }
            if (dir == 3) // 위
            {
                nx--;
                if (nx < 0)
                {
                    nx++;
                    dir = 0;
                }
            }
            // cout << nx << " " << ny << endl;
            // cout << temp << " / " << map[nx][ny] << endl;
            if (nx == x && ny == y)
                break;
            temp2 = map[nx][ny];
            if (temp != -1)
            {
                map[nx][ny] = temp;
                temp = temp2;
            }
            else
            {
                map[nx][ny] = 0;
                temp = temp2;
            }
            // cout << nx << " " << ny << endl;
        }
    }
    //cout << "-------------------" << endl;
    int sum = 0;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            sum += map[i][j];
            //cout << map[i][j] << " ";
        }
        //cout << endl;
    }
    cout << sum + 2 << endl;
}