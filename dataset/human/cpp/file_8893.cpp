#include <iostream>
#include <string>

bool compare_string(std::string A, std::string B, int A_start, int length)
{
  for(int i = 0; i < length; i++)
  {
    if(A[A_start + i] != B[i])
    {
      return false;
    }
  }
  return true;
}

int main()
{  
  int N, M;
  std::string A[50], B[50], result = "No";
  std::cin >> N >> M;
  
  for(int i = 0; i < N; i++)
  {
    std::cin >> A[i];
  }
  
  for(int i = 0; i < M; i++)
  {
    std::cin >> B[i]; 
  }

  for(int i = 0; i <= N - M; i++)
  {
    for(int j = 0; j <= N - M; j++)
    {
      for(int k = 0; k < M; k++)
      {
        if(compare_string(A[j + k], B[k], i, M) == false)
        {
          break;
        }
        else if(k == M - 1)
        {
          result = "Yes";
        }
      }
    }
  }
  
  std::cout << result;
  return 0;
}
