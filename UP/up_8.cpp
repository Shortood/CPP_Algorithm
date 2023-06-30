#include <iostream>

using namespace std;

int main()
{
    int N, L, i, j, now, mc, cnt = 0;
    int **map;
    bool down = false;
    cin >> N >> L;
    // 입력
    map = new int *[N];
    for (int i = 0; i < N; i++)
    {
        map[i] = new int[N];
        for (int j = 0; j < N; j++)
        {
            cin >> map[i][j];
        }
    }
    //
    for (i = 0; i < N; i++)
    {
        now = map[i][0];
        mc = 1;
        down = false;
        for (j = 1; j < N; j++)
        {
            if (map[i][j] - now > 1 || map[i][j] - now < -1)
                break;
            if (map[i][j] > now) // 높아질 때
            {
                if (down == true)
                    break;
                if (mc < L) // 경사로가 못 들어갈 때
                    break;
                mc = 1;
            }
            else if (map[i][j] < now) // 낮아질 때
            {
                if (down == true)
                    break;
                down = true;
                mc = 1;
            }
            else // 같을 때
            {
                mc++; // 현재 경사 높이 갯수 증가
            }
            if (down == true && mc >= L)
            {
                down = false;
                mc = 0;
            }
            now = map[i][j];
        }
        if (j == N && down == false)
            cnt++;
    }
    for (j = 0; j < N; j++)
    {
        now = map[0][j];
        mc = 1;
        down = false;
        for (i = 1; i < N; i++)
        {
            if (map[i][j] - now > 1 || map[i][j] - now < -1)
                break;
            if (map[i][j] > now) // 높아질 때
            {
                if (down == true)
                    break;
                if (mc < L) // 경사로가 못 들어갈 때
                    break;
                mc = 1;
            }
            else if (map[i][j] < now) // 낮아질 때
            {
                if (down == true)
                    break;
                down = true;
                mc = 1;
            }
            else // 같을 때
            {
                mc++; // 현재 경사 높이 갯수 증가
            }
            if (down == true && mc >= L)
            {
                down = false;
                mc = 0;
            }
            now = map[i][j];
        }
        if (i == N && down == false)
            cnt++;
    }
    cout << cnt << endl;
    // 위에서 아래로
    // 왼쪽에서 오른쪽으로
    // 0,0 -> 0,1 -> 0,2 -> 0,n
    // 1,0 -> 1,1 -> 1,2 -> 1,n

    // 0,0 -> 1,0 -> 2,0 -> n,0
    // 0,1 -> 1,1 -> 2,1 -> n,1
    // 높은 경사로로 갈 때
    //  현재 경사가 L개 반복되는지 확인
    // 낮은 경사로로 갈 때
    // 다음 경사가 L개 반복되는지 확인
}