import itertools
def main():
    N = int(input())
    a = list(map(int, input().split()))
    AC = list(itertools.accumulate(a))
    M = sum(a)
    ans = abs(M - a[0]*2)

    for i in range(1,N-1):
        ans =  min(abs(M - AC[i]*2),ans)
    
    print(ans)


if __name__ == '__main__':
    main()
