import sys
import copy

def main():
  input = sys.stdin.readline
  n, k = map(int, input().split())
  a = [int(x)-1 for x in input().split()]
  key = [copy.deepcopy(a) for _ in range(61)]
  for i in range(60):
    for j in range(n):
      key[i+1][j] = key[i][key[i][j]]
  
  i = 0
  now = 0
  while k > 0:
    if k%2:
      now = key[i][now]
    k //= 2
    i += 1
  
  print(now+1)
  
if __name__ == "__main__":
  main()
