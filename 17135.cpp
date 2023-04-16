//캐슬 디펜스
#include <iostream>
#include <algorithm>
#define MAX_N 16
using namespace std;
int n, m, d, **aEnemy;
int Combination();
int del_enemy(int **arr);
int Simulation(int a1, int a2, int a3);
bool inDist(int _x, int _y, int _nx, int _ny);
int main()
{
  aEnemy = new int *[MAX_N];
  for (int i = 0; i < MAX_N; i++)
    aEnemy[i] = new int[MAX_N];
  cin >> n >> m >> d;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cin >> aEnemy[i][j];
    }
  }
  cout << Combination();
  //동적할당 해제
  for (int i = 0; i < MAX_N; i++)
    delete aEnemy[i];
  delete[] aEnemy;
}
bool inDist(int _x, int _y, int _nx, int _ny)
{
  return abs(_x - _nx) + abs(_y - _ny) <= d;
}
int Combination()
{
  int max_ans = 0;
  for (int i = 0; i < m - 2; i++)
    for (int j = i + 1; j < m - 1; j++)
      for (int k = j + 1; k < m; k++)
        max_ans = max(Simulation(i, j, k), max_ans);

  return max_ans;
}
int Simulation(int a1, int a2, int a3)
{
  int **temp = nullptr;
  temp = new int *[n + 1];
  for (int i = 0; i < n + 1; i++)
    temp[i] = new int[m];
  for (int i = 0; i < n + 1; i++)
  {
    for (int j = 0; j < m; j++)
      temp[i][j] = aEnemy[i][j];
  }
  int nums[3] = {a1, a2, a3};
  int cnt = 0;
  for (int i = n; i > 0; i--)
  { //i -> 궁수 올리기
    for (int j = 0; j < 3; j++)
    {
      int x = i;
      int y = nums[j];
      int dist = 0, min_dist = 11;
      int ex = 0, ey = 0;
      int start = i - d;
      if (start < 0)
        start = 0;
      bool flag = false;
      for (int r = start; r <= i - 1; r++)
      {
        for (int c = 0; c < m; c++)
        {
          if (temp[r][c] >= 1 && inDist(x, y, r, c))
          {
            dist = abs(x - r) + abs(y - c);
            if (dist < min_dist)
            {
              flag = true;
              min_dist = dist;
              ex = r;
              ey = c;
            }
            else if (dist == min_dist)
            {
              if (ey > c)
              {
                flag = true;
                ex = r;
                ey = c;
              }
            }
          }
        }
      }
      if (flag)
        temp[ex][ey] += 1;
    }
    cnt += del_enemy(temp);
  }
  for (int i = 0; i < n + 1; i++)
    delete temp[i];
  delete[] temp;
  temp = nullptr;
  return cnt;
}
int del_enemy(int **arr)
{
  int cnt = 0;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if (arr[i][j] >= 2)
      {
        arr[i][j] = 0;
        cnt++;
      }
    }
  }
  return cnt;
}
