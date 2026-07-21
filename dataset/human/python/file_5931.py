import sys
sys.setrecursionlimit(10**9)

def mi(): return map(int,input().split())
def ii(): return int(input())
def isp(): return input().split()
def deb(text): print("-------\n{}\n-------".format(text))

INF=10**20
def main():
    N=ii()
    A=list(mi())
    B=list(mi())
    C=list(mi())

    pre = INF
    ans = 0
    for i in range(N):
        a = A[i]
        b = B[a-1]
        ans += b
        if a == pre + 1:
            ans += C[a-2]
        
        pre = a

    print(ans)


if __name__ == "__main__":
    main()
