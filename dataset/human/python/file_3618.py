N = int(input())
ANS = 0
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

L = factorization(N)

for i in range(len(L)):
    for j in range(50):
        if j * (j+1) > 2 * L[i][1]:
            ANS += j - 1
            break
if len(L) == 1 and L[0][0] == 1:
    ANS = 0

print(ANS)
