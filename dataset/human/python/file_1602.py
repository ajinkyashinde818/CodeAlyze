def solve():
  N,M = map(int, input().split())
  An = []
  Bn = []
  [An.append(str(input())) for i in range(N)]
  [Bn.append(str(input())) for i in range(M)]

  for i in range(0,N-M+1):
    for j in range(0,N-M+1):
      ret = True
      for k in range(M):
        if An[i+k][j:M+j] != Bn[k]:
          ret = False
      if ret:
        return True
  return False

if __name__ == "__main__":
  if solve():
    print('Yes')
  else:
    print('No')
