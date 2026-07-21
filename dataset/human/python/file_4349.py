def main():
    n = int(input())
    ans = 0
    for k in range(2,int(n**0.5)+1):
        if n%k==0:
            cnt,mx = 0,0
            while n%k==0:
                n = n//k
                cnt += 1
                if cnt > mx:
                    ans += 1
                    mx += 1
                    cnt = 0
    if n!=1:
        ans += 1
    print(ans)

if __name__ == "__main__":
    main()
