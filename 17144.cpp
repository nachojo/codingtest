//배열돌리기 미세먼지 공기청정기
#include <iostream>
using namespace std;
#define MAX_C 50
void spread_dust(int arr[][MAX_C], int air);
void purifying(int arr[][MAX_C], int air);
void simulation1(int arr[][MAX_C], int air);
void simulation2(int arr[][MAX_C], int air);
bool inRange(int x, int y);
int count_Dust(int arr[][MAX_C]);
int r, c;
int main()
{
  int T, air = 0, room[MAX_C][MAX_C];
  cin >> r >> c >> T;

  for (int i = 0; i < r; i++)
  {
    for (int j = 0; j < c; j++)
    {
      cin >> room[i][j];
      if (room[i][j] == -1 && air == 0)
        air = i;
    }
  }

  for (int i = 0; i < T; i++)
  {
    spread_dust(room, air);
    simulation1(room, air);
    simulation2(room, air + 1);
  }
  int ans = count_Dust(room);
  cout << ans;
  cout << endl;
  for (int i = 0; i < r; i++)
  {
    for (int j = 0; j < c; j++)
      cout << room[i][j] << " ";
    cout << endl;
  }

  return 0;
}
bool inRange(int x, int y)
{
  return x >= 0 && x < r && y >= 0 && y < c;
}
void spread_dust(int arr[][MAX_C], int air)
{
  //Temp 배열 초기화
  int Temp[MAX_C][MAX_C];
  for (int i = 0; i < r; i++)
    for (int j = 0; j < c; j++)
      Temp[i][j] = 0;
  Temp[air][0] = -1;
  Temp[air + 1][0] = -1;

  //4방향 탐색
  int dx[4] = {-1, 1, 0, 0};
  int dy[4] = {0, 0, -1, 1};

  for (int i = 0; i < r; i++)
  {
    for (int j = 0; j < c; j++)
    {
      //값이 있으면서 값/5가 0보다 큰 경우 미세먼지 확산.
      if ((arr[i][j] / 5) > 0)
      {
        int cnt = 0;
        //4방향 탐색
        for (int k = 0; k < 4; k++)
        {
          int nx = i + dx[k];
          int ny = j + dy[k];
          //inRange고 그 방향의 값이 -1이 아닐 경우에만 값 변경해주고 count
          if (inRange(nx, ny) == true && arr[nx][ny] != -1)
          {
            Temp[nx][ny] += arr[i][j] / 5;
            cnt++;
          }
        }
        Temp[i][j] += arr[i][j] - ((arr[i][j] / 5) * cnt);
      }
      // 미세먼지는 있지만 5로 나눈 값이 0인 경우(값이 5보다 작은 경우)
      // 확산은 안되고 자기 값 그대로 가져감
      else if (arr[i][j] != 0 && arr[i][j] != -1)
      {
        Temp[i][j] += arr[i][j];
      }
    }
  }

  //배열 복사
  for (int i = 0; i < r; i++)
    for (int j = 0; j < c; j++)
      arr[i][j] = Temp[i][j];
}

void purifying(int arr[][MAX_C], int air)
{
  int temp1, temp2, temp3;
  temp1 = arr[air][c - 1];
  for (int i = c - 1; i > 1; i--)
    arr[air][i] = arr[air][i - 1];
  arr[air][1] = 0;

  temp2 = arr[0][c - 1];
  for (int i = 0; i < air - 1; i++)
    arr[i][c - 1] = arr[i + 1][c - 1];
  arr[air - 1][c - 1] = temp1;

  temp3 = arr[0][0];
  for (int i = 0; i < c - 2; i++)
    arr[0][i] = arr[0][i + 1];
  arr[0][c - 2] = temp2;

  for (int i = air - 1; i > 1; i--)
    arr[i][0] = arr[i - 1][0];
  arr[1][0] = temp3;

  air += 1;
  temp1 = arr[air][c - 1];
  for (int i = c - 1; i > 1; i--)
    arr[air][i] = arr[air][i - 1];
  arr[air][1] = 0;

  temp2 = arr[r - 1][c - 1];
  for (int i = r - 1; i > air + 1; i--)
    arr[i][c - 1] = arr[i - 1][c - 1];
  arr[air + 1][c - 1] = temp1;

  temp3 = arr[r - 1][0];
  for (int i = 0; i < c - 2; i++)
    arr[r - 1][i] = arr[r - 1][i + 1];
  arr[r - 1][c - 2] = temp2;

  for (int i = air + 1; i < r - 2; i++)
    arr[i][0] = arr[i + 1][0];
  arr[r - 2][0] = temp3;
}

void simulation1(int arr[][MAX_C], int air)
{
  int dx[4] = {-1, 0, 1, 0};
  int dy[4] = {0, 1, 0, -1};
  cout << "air" << air << endl;
  int sx = air - 1;
  int sy = 0;
  for (int dir = 0; dir < 4;)
  {
    int nx = sx + dx[dir];
    int ny = sy + dy[dir];
    if (nx == air && ny == 0)
      break;
    if (!inRange(nx, ny) || nx > air)
    { //새로운 위치가 격자를 벗어나는 경우
      dir++;
      continue;
    }
    //격자 내
    cout << sx << " " << sy << " sx sy" << endl;
    arr[sx][sy] = arr[nx][ny];
    sx = nx;
    sy = ny;
  }
  arr[air][1] = 0;
  cout << " ?" << endl;
}

void simulation2(int arr[][MAX_C], int air)
{
  int temp = arr[air][0];
  int dx[4] = {1, 0, -1, 0};
  int dy[4] = {0, 1, 0, -1};
  int dir = 0;
  int sx = air + 1;
  int sy = 0;
  for (int dir = 0; dir < 4;)
  {
    int nx = sx + dx[dir];
    int ny = sy + dy[dir];
    if (nx == air && ny == 0)
      break;
    if (!inRange(nx, ny) || nx < air)
    { //새로운 위치가 격자를 벗어나는 경우
      dir++;
      continue;
    }
    //격자 내
    // cout << sx << " " << sy << " sx sy" << endl;
    arr[sx][sy] = arr[nx][ny];
    sx = nx;
    sy = ny;
  }
  arr[air][1] = 0;
}

int count_Dust(int arr[][MAX_C])
{
  int Total = 0;
  for (int i = 0; i < r; i++)
  {
    for (int j = 0; j < c; j++)
    {
      if (arr[i][j] != -1)
      {
        Total += arr[i][j];
      }
    }
  }
  return Total;
}
