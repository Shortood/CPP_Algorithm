#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int main()
{
    // -> ^ <-
    int N, x, y, d, g, temp, cnt = 0;
    int map[101][101] = {
        0,
    };
    stack<int> stack;
    queue<int> queue;
    vector<int> vector;
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> y >> x >> d >> g;
        // 0->1 1->2 2->3 3->0
        //       3,2
        // 스택으로 1증가
        map[x][y] = i;
        //cout << x << " " << y << endl;
        stack.push(d);
        queue.push(d);
        vector.push_back(d);
        if (d == 0) // 오
            map[x][++y] = i;
        else if (d == 1) // 위
            map[--x][y] = i;
        else if (d == 2) // 왼
            map[x][--y] = i;
        else if (d == 3) // 아
            map[++x][y] = i;
        //cout << x << " " << y << endl;
        // 0 1 2 3 4
        for (int j = 0; j < g; j++)
        {
            while (!stack.empty())
            {
                temp = stack.top();
                stack.pop();
                temp = (temp + 1) % 4;
                vector.push_back(temp);
                if (temp == 0) // 오
                    map[x][++y] = i;
                else if (temp == 1) // 위
                    map[--x][y] = i;
                else if (temp == 2) // 왼
                    map[x][--y] = i;
                else if (temp == 3) // 아
                    map[++x][y] = i;
            }
            for (int t = 0; t < vector.size(); t++)
            {
                stack.push(vector[t]);
            }
        }
        while (!stack.empty())
            stack.pop();
        vector.clear();
    }
    /*
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                cout << map[i][j] << " ";
            }
            cout << endl;
        }
        */
    for (int i = 1; i <= 100; i++)
    {
        for (int j = 1; j <= 100; j++)
        {
            if (map[i - 1][j] && map[i][j - 1] && map[i - 1][j - 1] && map[i][j])
                cnt++;
        }
    }
    cout << cnt << endl;
}