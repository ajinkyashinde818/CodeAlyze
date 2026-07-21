from collections import defaultdict
n = int(input())

arr = defaultdict(int)
temp = n
for i in range(2, int(-(-n**0.5//1))+1):
    if temp%i==0:
        cnt=0
        while temp%i==0:
            cnt+=1
            temp //= i
        arr[i] = cnt

if temp!=1:
    arr[temp] = 1

if arr==[]:
    arr[n] = 1

ans = 0

for i in arr:
    c = 1
    while arr[i]-c>=0:
        arr[i] -= c
        c += 1
        ans += 1
print(ans)
