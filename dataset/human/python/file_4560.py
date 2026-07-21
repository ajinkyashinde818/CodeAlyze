import sys, math, itertools, collections, bisect
input = lambda: sys.stdin.buffer.readline().rstrip().decode('utf-8')
inf = float('inf') ;mod = 10**9+7
mans = inf ;ans = 0 ;count = 0 ;pro = 1

n = int(input())
data = [0] * (10**5)
for i in range(1,10**5):
  data[i] = data[i-1] + i

def prime_factor(n):
    ass = []
    for i in range(2,int(n**0.5)+1):
        count=0
        while n % i==0:
            count+=1
            n = n//i
        if count!=0:
            ass.append((i,count))
    if n != 1:
        ass.append((n,1))
    return ass
ass = prime_factor(n)
for num,count in ass:
  ans += bisect.bisect_right(data,count)-1
  # print(bisect.bisect_right(data,count),count)
print(ans)
# print(data[:10])
