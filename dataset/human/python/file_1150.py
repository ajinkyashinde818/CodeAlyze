from collections import defaultdict,deque
printn = lambda x: print(x,end='')
inn = lambda : int(input())
inl   = lambda: list(map(int, input().split()))
inm   = lambda:      map(int, input().split())
ins = lambda : input().strip()
DBG = True # and False
BIG = 10**18
R = 10**9 + 7
#R = 998244353

def ddprint(x):
  if DBG:
    print(x)

n = inn()
a = inl()
b = inl()
b.reverse()
left = n
same = -1
for i in range(n):
    if a[i]==b[i]:
        left = i
        same = a[i]
        break
if left==n:
    print('Yes')
    print(' '.join([str(x) for x in b]))
    exit()
for i in range(n):
    if same in [a[i],b[i]]:
        l2 = i
        break
right = r2 = -1
for i in range(n-1,-1,-1):
    if r2<0 and (same in [a[i], b[i]]):
        r2 = i+1
    if a[i]==b[i]:
        right = i+1
        break
if l2>=right-left:
    tmp = b[:right-left]
    b[:right-left] = b[left:right]
    b[left:right] = tmp
else:
    tmp = b[:l2]
    b[:l2] = b[left:left+l2]
    b[left:left+l2] = tmp
    if right+r2-left-l2>n:
        print('No')
        exit()
    tmp = b[r2:r2+right-l2-left]
    b[r2:r2+right-l2-left] = b[l2+left:right]
    b[l2+left:right] = tmp
print('Yes')
print(' '.join([str(x) for x in b]))
