#include <iostream>

using namespace std;

int main()
{
    int n, k, cnt = 0, zero = 0, level = 0, down;
    int *a, *robot;
    bool *chk;

    cin >> n >> k;
    down = n;
    a = new int[n * 2];
    chk = new bool[n * 2];
    robot = new int[n * 2];
    for (int i = 0; i < n * 2; i++)
    {
        cin >> a[i];
        if (a[i] == 0)
            zero++;
        chk[i] = false;
        robot[i] = -1;
    }
    if (zero > k)
        level = 1;
    else
    {
        int now = 2 * n - 1; // 1번
        down = n - 2;
        // 2번
        while (1)
        {
            if (a[now]) // 3번
            {
                robot[cnt] = now; // 로봇이 몇번에 있는지
                chk[now] = true;  // 로봇 올라감
                cnt++;            // 로봇 수
                a[now]--;         // 내구도
                if (a[now] == 0)
                    zero++;
                // level++;
            }
            // 4번
            if (zero >= k)
                break;
            // 1번
            now--;
            down--;
            if (now == -1)
                now = 2 * n - 1;
            if (down == -1)
                down = 2 * n - 1;
            if (chk[down]) // 내리는 위치에 로봇
            {
                chk[down] == false;
                cnt--;
                // robot 배열 스택으로 바꾸기
            }
            level++;
            // 2번 //로봇 빼기
            for (int i = 0; i < cnt; i++)
            {
                if (a[robot[i] + 1] && chk[i + 1] == false)
                { // 이동가능
                    a[robot[i] + 1]--;
                    if (a[robot[i] + 1] == 0)
                        zero++;
                    chk[i + 1] = true;
                    chk[i] = false;
                    robot[i]++;
                    // level++;
                    if (zero >= k)
                    {
                        cout << level << endl;
                        return 0;
                    }
                }
            }
        }
    }
    cout << level << endl;
}