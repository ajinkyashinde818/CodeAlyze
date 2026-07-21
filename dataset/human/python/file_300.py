def main():
    N = int(input())
    *A, = map(int, input().split())
    minuscount = 0
    A.sort(key=abs)
    for i in A:
        if i < 0:
            minuscount += 1
    maxi = 0
    for i in A:
        maxi += abs(i)
    if minuscount % 2 == 0:
        print(maxi)
    else:
        print(maxi - 2*abs(A[0]))
main()
