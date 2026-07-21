def main():
    N = int(input())
    a = list(map(int, input().split()))

    sum_a = sum(a)
    min_diff = float('inf')
    sum_first = 0
    for i in range(N-1):
        sum_first += a[i]
        if min_diff > abs(sum_a - 2 * sum_first):
            min_diff = abs(sum_a - 2 * sum_first)

    print(min_diff)

main()
