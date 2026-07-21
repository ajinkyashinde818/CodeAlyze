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
    N = int(input())  # 文字列または整数(一変数)
    answer = 0

    if N == 1:
        print(0)
        return

    ll = factorization(N)

    for l in ll:
        e = 1
        rest_e = l[1]
        while True:
            if rest_e >= e:
                answer += 1
                rest_e -= e
                e += 1
            else:
                break


    print(answer)

if __name__ == '__main__':
    main()
