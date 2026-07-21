import sys

def f(g, d, P, C):
  if d <= 0:
    return float('inf')
  
  n = min(g//(100*d), P[d-1])
  s = 100*d*n

  if n == P[d-1]:
    s += C[d-1]
  
  if g > s:
    n += f(g-s, d-1, P, C)
  
  return min(n, f(g, d-1, P, C))
  

def main():
  input = sys.stdin.readline
  D, G = map(int, input().split())
  P = []
  C = []
  for i in range(D):
    p, c = map(int, input().split())
    P.append(p)
    C.append(c)

  ans = f(G, D, P, C)
  print(ans)


if __name__ == '__main__':
  main()
