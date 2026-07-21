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

def countstep(a):
    i = 0
    while a>=i+1:
        i += 1
        a -= i
    return i

def main():
    n = int(input())
    a = factorization(n)
    
    if n==1:
        print(0)
        return
    
    if a[0][0]==0:
        print(0)
    else:
        count = 0
        for i in range(len(a)):
            count += countstep(a[i][1])
        print(count)

if __name__ == "__main__":
    main()
