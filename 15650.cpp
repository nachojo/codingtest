//N과 M(2)
#include <iostream>
#define MAX 8
using namespace std;
int n, m;
int arr[MAX];
void Permutation(int cnt, int start)
{
  if (cnt == m)
  {
    for (int i = 0; i < m; i++)
    {
      cout << arr[i] + 1 << " ";
    }
    cout << '\n';
    return;
  }
  for (int i = start; i < n; i++)
  {
    arr[cnt] = i;
    Permutation(cnt + 1, i + 1);
  }
}
int main()
{
  cin >> n >> m;
  for (int i = 0; i < n; i++)
    arr[i] = 0;
  Permutation(0, 0);
}
