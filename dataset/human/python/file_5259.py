import sys
input = sys.stdin.readline
n,m = map(int,input().split())
ab = [list(map(int,input().split()))for i in range(m)]
from1 = []
to_n = []
for i in range(m):
    if ab[i][0] == 1:
        from1.append(ab[i][1])
    if ab[i][1] == n:
        to_n.append(ab[i][0])
from1.sort()
to_n.sort()
'''
for i in range(len(from1)):
    if from1[i] in to_n:
        print('POSSIBLE')
        break
else:print('IMPOSSIBLE')
二分探索で実装できそう
'''
def bisearch(data,value):#data:ソート済みリスト  value:調べる値
  left = 0
  right = len(data) - 1
  while left <= right:
    mid = (left + right)//2
    if data[mid] == value:
      return mid
    elif data[mid] < value:
      left = mid + 1
    else:
      right = mid - 1
  return -1
for i in range(len(from1)):
    if bisearch(to_n,from1[i]) != -1:
        print('POSSIBLE')
        break
else:print('IMPOSSIBLE')
