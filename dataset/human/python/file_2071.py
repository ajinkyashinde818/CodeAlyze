from collections import Counter

def ii():return int(input())
def iim():return map(int,input().split())
def iil():return list(map(int,input().split()))

n = ii()
s = input()
d = Counter(s)

ans = 1
mod = 1000_000_007

for _,v in d.items():
    ans *= v+1
    ans %= mod

print(ans-1)
