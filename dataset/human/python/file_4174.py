N=int(input())
if N==1:
    print(0)
else:
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

    A=factorization(N)
    total=0
    for i in range(len(A)):
        for j in range(1,10**6):
            if j*(j+1)//2<=A[i][1]<(j+1)*(j+2)//2:
                total+=j
                break
    print(total)
