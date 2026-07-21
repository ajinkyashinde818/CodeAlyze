import sys
sys.setrecursionlimit(10**9)
INF=10**18
def input():
    return sys.stdin.readline().rstrip()

def main():
    N=int(input())
    A=list(map(int,input().split()))
    minA=INF
    c_m=0
    sumA=0
    for i in A:
        if i<0:
            c_m+=1
        minA=min(minA,abs(i))
        sumA+=abs(i)
    if c_m%2==1:
        print(sumA-2*minA)
    else:
        print(sumA)
        
    

if __name__ == '__main__':
    main()
