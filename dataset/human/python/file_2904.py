def resolve():
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

    arr = factorization(N)
    ans = 0
    
    for i in range(len(arr)):
        for j in range(1,100):
            if arr[i][0] == 1:
                break
            elif arr[i][1] == 1:
                ans += 1
                break
            elif arr[i][1] == sum(range(0,j+1)):
                ans += j
                break
            elif arr[i][1] < sum(range(0,j+1)):
                ans += j-1
                break
    
    print(ans)
resolve()
