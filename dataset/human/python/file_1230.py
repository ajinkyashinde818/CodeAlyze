def main():
    n = int(input())
    a = list(map(int, input().split()))

    sum_a = sum(a)
    min_diff = 1000000000000000000000

    sum_x = 0
    for i in range(0, n-1):
        sum_x += a[i]
        diff = abs(sum_a - 2*sum_x)
        if min_diff > diff:
            min_diff = diff

    print(min_diff)

    '''
    half = sum_a // 2

    diff = []
    for i in range(n-1):
        diff.append(a[i+1] - a[i])
    min_diff = abs(min(diff))

    print(min_diff)
    '''

# 真ん中を分けるカードの差がわかればよい


if __name__ == '__main__':
    main()
