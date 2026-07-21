import sys
read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines
sys.setrecursionlimit(10**8)
INF = float('inf')
MOD = 10**9+7


def main():
  N = int(readline())
  A = list(map(int, readline().split()))
  B = list(map(int, readline().split()))
  C = list(map(int, readline().split()))
  ans = sum(B)
  for i in range(N-1):
    if A[i] + 1 == A[i+1]:
      ans += C[A[i]-1]
  print(ans)
  
  
if __name__ == '__main__':
  main()
