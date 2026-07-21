def solve():
    N = int(input())
    A = list(map(int,input().split()))

    n_negative = 0
    for a in A:
        if a < 0:
            n_negative += 1

    abs_sum = sum(map(abs,A))
    if n_negative % 2 == 0:
        print(abs_sum)
    else:
        print(abs_sum - 2 * min(map(abs,A)))

if __name__ == '__main__':
    solve()
