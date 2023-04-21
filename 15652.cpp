//N과 M(4)
#include <iostream>
#define MAX 8
using namespace std;
int n, m;
int arr[MAX];
bool visited[MAX];
void Permutation(int cnt, int start)
{
  if (cnt == m)
  {
    for (int i = 0; i < m; i++)
    {
      cout << arr[i] << " ";
    }
    cout << '\n';
    return;
  }
  for (int i = start; i < n; i++)
  {
    arr[cnt] = i + 1;
    Permutation(cnt + 1, i);
  }
}
int main()
{
  cin >> n >> m;
  for (int i = 0; i < n; i++)
  {
    visited[i] = false;
  }
  for (int i = 0; i < n; i++)
  {
    arr[i] = 0;
  }
  Permutation(0, 0);
}
