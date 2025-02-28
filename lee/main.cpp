#include <bits/stdc++.h>

using namespace std;

int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
int n, a[101][101], aux[101][101]={0};

struct puncte
{
    int x, y;
} p[3];

void reset()
{
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            a[i][j] = aux[i][j];
}

bool inmat(int i, int j)
{
    return (i >= 1 and i <= n and j >= 1 and j <= n);
}

int lee(int is, int js, int x, int y)
{
    reset();
    queue<pair<int, int>> q;
    q.push({is, js});
    a[is][js] = 1;
    while (!q.empty())
    {
        pair<int, int> p = q.front();
        int xv = p.first, yv = p.second;
        q.pop();
        for (int k = 0; k < 4; k++)
        {
            int xn = xv + dx[k],
                yn = yv + dy[k];
            if (a[xn][yn] == 0 && inmat(xn, yn))
            {
                a[xn][yn] = a[xv][yv] + 1;
                q.push({xn, yn});
            }
        }
    }
    return a[x][y]-1;
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
            aux[i][j] = a[i][j];
        }
    for (int i = 0; i < 3; i++)
        cin >> p[i].x >> p[i].y;
    int traseu1=lee(1, 1, p[0].x, p[0].y)+lee(p[0].x, p[0].y, p[1].x, p[1].y)+lee(p[1].x, p[1].y, p[2].x, p[2].y)+lee(p[2].x, p[2].y, n, n);
    int traseu2=min(traseu1, lee(1, 1, p[0].x, p[0].y)+lee(p[0].x, p[0].y, p[2].x, p[2].y)+lee(p[2].x, p[2].y, p[1].x, p[1].y)+lee(p[1].x, p[1].y, n, n));
    int traseu3=min(traseu2, lee(1, 1, p[1].x, p[1].y)+lee(p[1].x, p[1].y, p[0].x, p[0].y)+lee(p[0].x, p[0].y, p[2].x, p[2].y)+lee(p[2].x, p[2].y, n, n));
    int traseu4=min(traseu3, lee(1, 1, p[1].x, p[1].y)+lee(p[1].x, p[1].y, p[2].x, p[2].y)+lee(p[2].x, p[2].y, p[0].x, p[0].y)+lee(p[0].x, p[0].y, n, n));
    int traseu5=min(traseu4, lee(1, 1, p[2].x, p[2].y)+lee(p[2].x, p[2].y, p[0].x, p[0].y)+lee(p[0].x, p[0].y, p[1].x, p[1].y)+lee(p[1].x, p[1].y, n, n));
    int traseu6=min(traseu5, lee(1, 1, p[2].x, p[2].y)+lee(p[2].x, p[2].y, p[1].x, p[1].y)+lee(p[1].x, p[1].y, p[0].x, p[0].y)+lee(p[0].x, p[0].y, n, n));
    cout<<traseu6;
}