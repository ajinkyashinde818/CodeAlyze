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

#    print(arr)
    cnt = 0
    N = n
    prime_arr = []
    array = []
#    print(len(arr))
    if len(arr) > 1:
        for i in range(len(arr)):
            array.append(arr[i][0])
#        print(array)
        for i in range(len(arr)):
            for j in range(arr[i][1]):
                prime_arr.append(array[i]**(j+1))
        prime_arr.sort()
#        print(prime_arr)
        for i in range(len(prime_arr)):
            if (N/prime_arr[i] >= 1 and N%prime_arr[i] == 0):
                N /= prime_arr[i]
                cnt += 1
        print(cnt)
    elif len(arr) == 1:
        if arr[0][0] == 1:
            print(0)
        else:
            num = arr[0][1]
            for i in range(num):
                prime_arr.append(arr[0][0]**(i+1))
            prime_arr.sort()
#            print(prime_arr)
            for i in range(len(prime_arr)):
                if (N/prime_arr[i] >= 1):
                    N /= prime_arr[i]
                    cnt += 1
            print(cnt)

    return arr
    

if __name__=="__main__":
    n = int(input())
    factorization(n)
