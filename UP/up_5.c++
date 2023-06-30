#include <iostream>

using namespace std;

// 10830
int hag[6][6] = {
    0,
},
    hag2[6][6] = {
        0,
};
int n, b;

int square(int b) // b제곱
{
    if (b == 2)
        mul(2);
        else if(b==3) mul(3);
        else if(b%2==0) square(b/2);
        else 
}

int mul(int g) //곱하기
{
    // g=2
    // g=3
}

int main()
{

    cin >> n >> b;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            cin >> hag[i][j];
            hag2[i][j] = hag[i][j];
        }
    }
}
