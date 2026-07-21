def main():
    N = int(input())
    A = [int(n) for n in input().split()]
    A = sorted(A, key = lambda x: abs(x), reverse=True)
    minus = 0
    for a in A:
        if a < 0:
            minus += 1
    if minus % 2 == 1:
        minus -= 1
    res = 0
    for i in range(N):
        a = A[i]
        if a < 0 and minus > 0:
            A[i] = -a
            minus -= 1
    for i in range(N):
        a = A[i]
        if a < 0:
            A[i] = -a
            A[-1] = -A[-1]
    
    print(sum(A))
main()
