def check(p,A):
    cnt = 0
    for a in p:
        if a >= A:
            cnt+=1
    return cnt >= A

def main():
    N=int(input())
    p=list(map(int,input().split()))
    for A in range(100,-1,-1):
        if check(p,A):
            print(A)
            return

if __name__ == "__main__":
    main()
