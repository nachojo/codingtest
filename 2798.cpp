//블랙잭 
#include <iostream>
#include <algorithm>
using namespace std;
int n, m, ans = 0;
int main()
{
  cin >> n >> m;
  int *arr = new int[n];
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  for (int i = 0; i < n - 2; i++)
  {
    for (int j = i + 1; j < n - 1; j++)
    {
      for (int k = j + 1; k < n; k++)
      {
        int temp = arr[i] + arr[j] + arr[k];
        if (temp > ans && temp <= m)
          ans = temp;
      }
    }
  }
  cout << ans;
  delete[] arr;
}
