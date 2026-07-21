N = int(input())

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

if N == 1:
    ans = 0
else:
    ans = 0
    checked = set()
    fact = factorization(N)
    candidates = []
    for num in fact:
        for i in range(1,num[1]+1):
            candidates.append(num[0]**i)

    candidates.sort(reverse=True)
    #print(candidates)
    while N != 1 and len(candidates) > 0:
        
        while len(candidates) != 0:
            tmp = candidates.pop()
            if N%tmp == 0:
                break
        #print(N,tmp)
        if N >= tmp:
            N = N//tmp
            ans += 1


print(ans)
