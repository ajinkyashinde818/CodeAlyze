from collections import deque

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
    fact = factorization(N)
    ans = 0

    if N == 1:
        print(0)
        return

    kasuus = [f[0] for f in fact]
    sisuus = [f[1] for f in fact]
    ks = deque(kasuus)
    ss = deque(sisuus)

    while ss:
        sisuu = ss.popleft()
        cnt = 1
        while True:
            sisuu -= cnt
            if sisuu < 0:
                break
            else:
                ans += 1
                cnt += 1

    print(ans)

    


if __name__ == "__main__":
    main()
