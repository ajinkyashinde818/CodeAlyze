import bisect
def main():
    N = int(input())
    A = list(map(int, input().split()))
    A.sort()
    i = bisect.bisect_left(A, 0)
    j = bisect.bisect_right(A, 0)
    if i % 2 == 0:
        print(sum([abs(i) for i in A]))
    else:
        if i != j:
            print(sum([abs(i) for i in A]))
        elif i == N:
            print(sum([abs(i) for i in A]) - 2 * abs(A[-1]))
        else:
            if abs(A[i-1]) > A[i]:
                print(sum([abs(i) for i in A]) - 2 * abs(A[i]))
            else:
                print(sum([abs(i) for i in A]) - 2 * abs(A[i-1]))
main()
