import sys
sys.setrecursionlimit(100000)

def ins(): return input().split()
def ii(): return int(input())
def iil(): return list(map(int,ins()))
def lin(): return list(input())
def iin(): return map(int,ins())

n = ii()
a = iil()
b = iil()
c = iil()
ans = b[a[0]-1]
for i in range(1,n):
    if a[i]-a[i-1]==1:
        ans += c[a[i-1]-1]
    ans += b[a[i]-1]
print(ans)
