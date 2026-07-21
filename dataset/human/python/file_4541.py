N = int(input())
S = 0
Tri = [0,1,3,6,10,15,21,28,36,45,55,66,78,91]
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
A = factorization(N)

if N > 1:
    for i in range (len(A)):
        T = A[i][1]
        j = 0
        while(T>=Tri[j]):
            j += 1
        S += (j-1)
                

print(S)
