def main():
    N,K,S = map(int,input().split())
    mx = 10**9
    if S < 10**5:
        Ans = [S]*K + [mx]*(N-K)
        print(*Ans,sep=" ")
        return 
    else:
        Ans = [S]*K + [1]*(N-K)
        print(*Ans,sep=" ")        
        return

if __name__ == "__main__":
    main()
