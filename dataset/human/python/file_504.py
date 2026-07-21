import sys
input = sys.stdin.readline

def main():
    n=int(input())
    a=sorted(list(map(int,input().split())))
    mnum=0
    for i,x in enumerate(a):
        if x>=0:
            mnum=i
            break
    m,p=-a[i-1],a[i]
    if i%2==0:
        print(-sum(a[:i])+sum(a[i:]))
    else:
        print(-sum(a[:i])+sum(a[i:])-2*min(m,p))

if __name__ == '__main__':
    main()
