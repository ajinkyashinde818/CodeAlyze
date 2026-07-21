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
    n = int(input())
    if n == 1:
        print(0)
        return 0
    l = factorization(n)
    cnt = 0
    for i in range(len(l)):
        tmp = l[i][1]
        for j in range(1,l[i][1]+1):
            if j <= tmp:
                cnt += 1
                tmp -= j
            else:
                break
    print(cnt)

if __name__ == '__main__':
    main()
