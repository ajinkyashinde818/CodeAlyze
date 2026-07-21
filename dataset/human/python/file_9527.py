import sys
readline = sys.stdin.readline

def main():
  N, K = map(int, readline().split())
  A = list(map(int, readline().split()))
 
  n = []
  for i in range(N):
    n.append(-1)
  s = 0
  c = -1
  d = A[1-1]
  r = [1]
  n[0] = 0
  for i in range(1, K+1):
    if n[d - 1] == -1:
      n[d - 1] = i
    else:
      s = n[d - 1]
      c = i - n[d - 1]
      break
    r.append(d)
    d = A[d - 1]
  if c == -1:
    print(r[-1])
  else:
    cr = r[s:s+c]
    k = (K - s)%c
    print(cr[k])
  exit()

if __name__ == '__main__':
  main()
