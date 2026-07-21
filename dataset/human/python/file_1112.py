import collections
import sys

def solve(n, A, B):
  ans = B[:]
  same = collections.deque()
  for i, (a, b) in enumerate(zip(A, B)):
    if a == b:
      if same and B[same[0]] != a:
        j = same.popleft()
        B[i], B[j] = B[j], B[i]
      else:
        same.append(i)
 # print(A)
  #print(B)
  #print(same)
  if same:
    s = A[same[0]]
    to_swap = []
    possible = False
    for i, (a, b) in enumerate(zip(A, B)):
      if a != s and b!=s:
        to_swap.append(i)
      if len(to_swap) == len(same):
        possible = True
        break
    if not possible:
      print('No')
      return
    for i, j in zip(same, to_swap):
      B[i], B[j] = B[j], B[i]
  print('Yes')
  print(' '.join(map(str, B)) )


       


def main():
  input = sys.stdin.readline
  n = int(input())
  A = list(map(int, input().split()))
  B = list(map(int, input().split()))
  solve(n, A, B)

main()
