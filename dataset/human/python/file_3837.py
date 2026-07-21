import sys
N = int(input())

def factorization(n):
    arr = []
    temp = n
    for i in range(2, int(-(-n**0.5//1))+1):
        if temp%i==0:
            cnt=0
            count = 0
            while temp%i==0:
                cnt+=1
                temp //= i
                if cnt == count+1:
                    count += 1
                    cnt = 0
            arr.append([i, count])

    if temp!=1:
        arr.append([temp, 1])

    if arr==[]:
        arr.append([n, 1])

    return arr

arr = factorization(N)
if N == 1:
    print(0)
    sys.exit()
else:
    print(sum([arr[i][1] for i in range(len(arr))]))
