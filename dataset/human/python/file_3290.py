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
fact = factorization(n)
cnt = 0

for i in range(len(fact)):
    for j in range(1,fact[i][1]+1):
        if n==1:
            print(cnt)
            exit()
        if n%(fact[i][0]**j)==0:
            cnt += 1
            n = n/(fact[i][0]**j)
print(cnt)
