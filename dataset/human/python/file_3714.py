def factorization(n):
    arr = []
    temp = n
    for i in range(2, int(-(-n**0.5//1))+1):
        if temp%i==0:
            cnt=0
            while temp%i==0:
                cnt+=1
                temp //= i
            arr.append(cnt)

    if temp!=1:
        arr.append(1)

    if arr==[]:
        arr.append(1)

    return arr

def main():
    N = int(input())
    #xxx = list(map(int, input().split()))

    if N == 1:
        print(0)
        return

    e_num = []
    for i in range(0, 40):
        for k in range(0, i+1):
            e_num.append(i)
    #print(e_num)

    e_list = factorization(N)

    ans = 0
    for e in e_list:
        ans += e_num[e]
    print(ans)

if __name__ == '__main__':
    main()
