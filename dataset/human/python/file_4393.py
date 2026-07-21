import heapq
n = int(input())
copy = n


def factorization(n):
    arr = []
    temp = n
    for i in range(2, int(-(-n**0.5//1))+1):
        if temp%i==0:
            cnt=0
            while temp%i==0:
                cnt+=1
                temp //= i
            arr.append([i, cnt])
    if temp!=1:
        arr.append([temp, 1])
    if arr==[]:
        arr.append([n, 1])
    return arr


f = factorization(n)
l = []
for i in f:
    for j in range(1, i[1]+1):
        l.append(i[0]**j)

heapq.heapify(l)

cnt = 0
while l:
    tmp = heapq.heappop(l)
    if n % tmp == 0:
        n = n // tmp
        cnt += 1
print(cnt if copy != 1 else 0)
