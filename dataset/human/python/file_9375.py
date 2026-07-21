import itertools
import numpy as np

def main():
  n, k = [int(i) for i in input().split()]
  A = [None] + [int(i) for i in input().split()]

  slow = fast = 1

  for i in range(k):
    slow = A[slow]
    fast = A[A[fast]]
    if slow == fast:
      break
    if i == k-1:
      return slow

  slow = 1
  count = 0
  while slow != fast:
    slow = A[slow]
    fast = A[fast]
    count += 1

  branch = fast
  branch_num = count
  count = 1
  node = A[branch]
  while node != branch:
    node = A[node]
    count += 1
  
  idx = (k - branch_num) % count + branch_num
  ret = 1
  for _ in range(idx):
    ret = A[ret]
  return ret

print(main())
