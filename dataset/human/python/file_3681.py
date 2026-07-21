N = int(input())

import heapq 





def factorization(n):
    arr = []
    temp = n
    for i in range(2, int(-(-n**0.5//1))+1):
        if temp%i==0:
            cnt=0
            while temp%i==0:
                cnt+=1
                temp //= i
            arr.append([i,i, cnt])

    if temp!=1:
        arr.append([temp,temp, 1])

    if arr==[]:
        arr.append([n,n,1])

    return arr

# for N in range(1,100000):
# N = 288
# print(N)

heap = factorization(N) 
# print(heap)
# print(heap)
heapq.heapify(heap)
ans = 0

while(heap):
    # print(heap)
    if N == 1:
        break
    sub,prime,cnt = heapq.heappop(heap)
    if N < sub:
        break
    if N % sub == 0:
        N = N // sub
        ans += 1
        if cnt > 0:
            cnt -= 1
            sub *= prime
            heapq.heappush(heap, [sub,prime,cnt])

print(ans)
