#include <iostream>

void rotateDirection(int dir[2])
{
  if (dir[0] == 1 && dir[1] == 0)
  {
    dir[0] = 0;
    dir[1] = 1;
  }
  else if (dir[0] == 0 && dir[1] == 1)
  {
    dir[0] = -1;
    dir[1] = 0;
  }
  else if (dir[0] == -1 && dir[1] == 0)
  {
    dir[0] = 0;
    dir[1] = -1;
  }
  else if (dir[0] == 0 && dir[1] == -1)
  {
    dir[0] = 1;
    dir[1] = 0;
  }
}



void rotate90Degrees(int dir[2])
{
  
}

template <size_t n>
class Matrix
{
public:
  int m[n][n];

  Matrix<n>(int (&m)[n][n])
  {
    for (int i = 0; i < n; ++i)
    {
      for (int j = 0; j < n; ++j)
      {
        this->m[i][j] = m[i][j];
      }
    }
  }

  void rotateLeft()
  {
    for (int i = 0; i < n / 2; ++i)
    {
      int edges[2] = {i, n - 1 - i};
      int pos[2] = {i, i};
      int dir[2] = {1, 0};
      int nextPos[2] = {i + 1, i};
      int val = m[pos[0]][pos[1]];

      if (edges[0] == edges[1])
      {
        continue;
      }

      do
      {
        if (nextPos[0] < edges[0] || nextPos[0] > edges[1] || nextPos[1] < edges[0] || nextPos[1] > edges[1])
        {
          rotateDirection(dir);
          nextPos[0] = pos[0] + dir[0];
          nextPos[1] = pos[1] + dir[1];
        }

        int temp = m[nextPos[0]][nextPos[1]];
        m[nextPos[0]][nextPos[1]] = val;
        val = temp;

        pos[0] = nextPos[0];
        pos[1] = nextPos[1];
        nextPos[0] += dir[0];
        nextPos[1] += dir[1];
      } while (pos[0] != i || pos[1] != i);
    }
  }

  void rotate90Degrees()
  {

  }

  void print()
  {
    for (int i = 0; i < n; ++i)
    {
      for (int j = 0; j < n; ++j)
      {
        std::cout << m[i][j] << " ";
      }
      std::cout << std::endl;
    }
  }
};

int main()
{
  // int m[2][2] = {{0, 1}, {2, 3}};
  // auto img = new Matrix<2>(m);
  int m[4][4] = {{0, 1, 2, 3}, {4, 5, 6, 7}, {8, 9, 10, 11}, {12, 13, 14, 15}};
  auto img = new Matrix<4>(m);

  img->print();
  std::cout << std::endl;
  img->rotateLeft();
  img->print();
  return 0;
}
