N = int(input())

if N == 1:
    print(0)
    exit()

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

dic = {}
for v in factorization(N):
    dic[v[0]] = v[1]
#print(dic)


lst = []
for i in dic:
    for j in range(1, dic[i]+1):
        lst.append(i**j)
lst.sort()


cnt = 0
for i in lst:
    if  N % i == 0 and N // i > 0:
        N = N / i
        cnt += 1
print(cnt)
