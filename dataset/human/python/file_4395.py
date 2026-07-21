def main():
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
    N = int(input())
    A = factorization(N)
    count = 0
    if A[0][0] != 1:
        for a in A:
            for i in range(a[1]):
                if a[1] - (i+1) >= 0:
                    a[1] = a[1] - (i+1)
                    count += 1
                else:
                    break
            
    print(count)
    
if __name__ == '__main__':
    main()
