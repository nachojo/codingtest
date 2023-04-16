#include <iostream>
#define MAX 16
using namespace std;
char *arr, *copy_arr;
int L, C;
bool *visited;
void Permutation(int cnt, int idx);
int main()
{
  arr = new char[MAX];
  copy_arr = new char[MAX];
  visited = new bool[MAX];
  cin >> L >> C;
  for (int i = 0; i < C; i++)
    cin >> arr[i];
  for (int i = 0; i < C; i++)
    copy_arr[i] = ' ';
  for (int i = 0; i < C; i++)
    visited[i] = false;
  for (int i = 0; i < C - 1; i++)
    for (int j = i + 1; j < C; j++)
    {
      if (arr[i] > arr[j])
      {
        int temp = 0;
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
      }
    }
  Permutation(0, 0);
  delete[] arr;
  delete[] visited;
  delete[] copy_arr;
}
void Permutation(int cnt, int idx)
{
  if (cnt == L)
  {
    bool flag = false;
    int alph = 0;
    for (int i = 0; i < L; i++)
    {
      if (copy_arr[i] >= 97 && copy_arr[i] <= 122 && copy_arr[i] != 'a' && copy_arr[i] != 'e' && copy_arr[i] != 'i' && copy_arr[i] != 'o' && copy_arr[i] != 'u')
        alph++;
      if (copy_arr[i] == 'a' || copy_arr[i] == 'e' || copy_arr[i] == 'i' || copy_arr[i] == 'o' || copy_arr[i] == 'u')
      {
        flag = true;
      }
    }
    if (flag == true && alph >= 2)
    {
      for (int i = 0; i < L; i++)
        cout << copy_arr[i];
      cout << endl;
    }
    return;
  }

  for (int i = 0; i < C; i++)
  {
    if (visited[i] == true)
      continue;
    if (cnt >= 1)
      if (arr[i] < copy_arr[cnt - 1])
        continue;
    visited[i] = true;
    copy_arr[cnt] = arr[i];
    Permutation(cnt + 1, idx + 1);
    visited[i] = false;
  }
}