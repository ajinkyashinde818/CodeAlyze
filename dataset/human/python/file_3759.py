import bisect
n = int(input())

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

arr = factorization(n) 
#print(arr)
ans = 0

tosa = [0 for _ in range(1000)]
for i in range(1000):
    tosa[i] = int(i*(i+1)/2)

#print(tosa)
for s in arr:
    if(s[0] == 1):
        continue
    num = s[1]
    cnt = bisect.bisect_right(tosa, num) - 1
    #print(cnt)
    ans += cnt

print(ans)
