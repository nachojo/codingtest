//외판원 순회 
#include <iostream>
#include <climits>
#define N 10
using namespace std;
int arr[N][N], city[N], perm[N + 1];
bool visited[N];
int n = 0, min_cost = INT_MAX;
void permutation(int cnt);
int main()
{
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
      cin >> arr[i][j];
  }
  for (int i = 0; i < n; i++)
    city[i] = i;
  for (int i = 0; i < n + 1; i++)
    perm[i] = 0;
  for (int i = 0; i < n; i++)
    visited[i] = false;

  permutation(0);
  cout << min_cost;
}
void permutation(int cnt)
{
  if (cnt == n)
  {
    perm[n] = perm[0];
    int total = 0, flag = 0;
    for (int i = 0; i < n; i++)
    {
      if (arr[perm[i]][perm[i + 1]] == 0)
      {
        flag = 1;
        break;
      }
      total += arr[perm[i]][perm[i + 1]];
    }
    if (flag != 1)
      min_cost = min(total, min_cost);
    return;
  }

  for (int i = 0; i < n; i++)
  {
    if (visited[i] == true)
      continue;
    visited[i] = true;
    perm[cnt] = city[i];
    permutation(cnt + 1);
    visited[i] = false;
  }
}
