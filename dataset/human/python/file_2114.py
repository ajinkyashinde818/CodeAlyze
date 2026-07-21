import sys
sys.setrecursionlimit(20000000)
input = sys.stdin.readline
n = int(input())
s = input()
a = [0]*26
ans = 1
mod = 10**9+7
for i in range(n):
        a[ord(s[i]) - ord("a")] += 1
for i in a:
        ans *= (i+1)
        ans%=mod
print(ans-1)
