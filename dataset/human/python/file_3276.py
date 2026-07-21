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

def main():
        N = int(input())

        fac = factorization(N)

        arr = []

        for i in range(len(fac)):
                for j in range(fac[i][1]):
                        temp = fac[i][0]**(j+1)
                        arr.append(temp)

        arr.sort()

        count = 0

        for i in range(len(arr)):
                if N==1:
                        break
                else:
                        if N%arr[i]==0:
                                N = N/arr[i]
                                count += 1

        return count

if __name__=="__main__":
        ans = main()
        print(ans)
