import sys
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
n = int(input())
if n == 1:
    print(0)
    sys.exit()
res = factorization(n)
d = dict()
for i,j in res:
    d[i] = j
ans = 0
for n in d.keys():
    for i in range(100):
        #print(d[n],i*(i+1)//2)
        if d[n] < i*(i+1)//2:
            ans += i-1
            break
        else:
            pass
print(ans)
