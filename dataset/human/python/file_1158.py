from bisect import bisect_left,bisect_right
n=int(input())
a=list(map(int,input().split()))
b=list(map(int,input().split()))
bset=set(b)

ans=0
for i in range(n):
  if a[i] in bset:
    ans=max(bisect_right(b,a[i])-i,ans)

# bを回転
b=(b+b)[ans:ans+n]
# check
for i in range(n):
  if a[i]==b[i]:
    exit(print("No"))
print("Yes")
print(*b)
