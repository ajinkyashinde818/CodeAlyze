import numpy as np

def solve(_k, _A):
  ans = np.inf
  tmp_list = _A + [i+_k for i in _A]
  for i in range(len(_A)):
    dist = tmp_list[len(_A)+i-1] - tmp_list[i]
    if ans > dist:
      ans = dist
  return ans

if __name__ == "__main__":
  _k,_n = map(int, input().split())
  _A = [int(i) for i in input().split()]
  print(int(solve(_k, _A)))
