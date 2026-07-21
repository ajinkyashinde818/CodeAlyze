import numpy as np


if __name__ == '__main__':
  N = int(input())
  A = list(map(int, input().split()))

  num_of_minus = sum([a < 0 for a in A])
  abs_A = [abs(a) for a in A]
  ans = sum(abs_A)

  if (num_of_minus % 2 == 0) or (sum([a == 0 for a in A])>0):
      print(ans)
  else:
      print(ans - 2 * min(abs_A))
