#include <iostream>
#include <algorithm>
#include <vector>

int main()
{
  int n, m;
  std::cin >> n >> m;
  std::vector<std::string> a(n);
  for (auto& itr : a)
  {
    std::cin >> itr;
  }
  std::vector<std::string> b(m);
  for (auto& itr : b)
  {
    std::cin >> itr;
  }
  for (int a_row = 0; a_row < n - m + 1; ++a_row)
  {
    for (int a_column = 0; a_column < n - m + 1; ++a_column)
    {
      bool match = true;
      for (int b_row = 0; b_row < m; ++b_row)
      {
        for (int b_column = 0; b_column < m; ++b_column)
        {
          if (b[b_row][b_column] != a[a_row + b_row][a_column + b_column])
          {
            match = false;
          }
        }
      }
      if (match == true)
      {
        std::cout << "Yes" << std::endl;
        return 0;
      }
    }
  }
  std::cout << "No" << std::endl;
  
  return 0;
}
