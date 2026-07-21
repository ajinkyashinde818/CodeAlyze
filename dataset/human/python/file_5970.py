import sys
input = sys.stdin.readline

def main():
    n=int(input())
    a=list(map(int,input().split()))
    b=list(map(int,input().split()))
    c=list(map(int,input().split()))
    m=0
    m+=b[a[0]-1]
    for i in range(1,n):
        m+=b[(a[i]-1)]
        if a[i]==a[i-1]+1:
            m+=c[a[i]-2]

    print(m)

if __name__ == "__main__":
    main()
