from collections import defaultdict

def fctr1(n): 
    d = defaultdict(int)
    c=0
    r=int(n**0.5)
    for i in range(2,r+2):
        while n%i==0:
            c+=1
            n=n//i
        if c!=0:
            d[i] = c
            c=0
    if n!=1:
        d[n] = 1
    return d

def main():
    N = int(input())
    primes = fctr1(N)
    d = defaultdict(int)
    ans = 0
    for i, j in primes.items():
        cnt = 1
        while True:
            if j - cnt < 0:
                d[i] = j
                break
            ans += 1
            j -= cnt
            cnt += 1

    print(ans)





if __name__ == "__main__":
    main()
