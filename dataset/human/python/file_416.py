import sys
input = lambda: sys.stdin.readline().rstrip()

N = int(input())

A = list(map(int, input().split()))

neg_cnt = 0
minimum = 10**10
for num in A:
    minimum = min(minimum, abs(num))
    if num < 0:
        neg_cnt += 1
        
ans = 0
for num in A:
    if num < 0:
        ans += -num
    else:
        ans += num 

if neg_cnt % 2 == 0:
    print(ans)               
else:
    print(ans - minimum * 2)
