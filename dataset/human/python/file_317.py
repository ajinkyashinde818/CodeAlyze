def main():
    n = int(input())
    a = list(map(int, input().rstrip().split(' ')))
    total = 0
    n_count = 0
    n_max = -10000000000
    p_min = 10000000000
    for i in range(n):
        if a[i] < 0:
            n_count += 1
            if n_max < a[i]:
                n_max = a[i]
        else:
            if p_min > a[i]:
                p_min = a[i]
    if n_count % 2 == 0:
        total = sum(map(abs, a))
    else:
        total = sum(map(abs, a)) - 2 * min(p_min, abs(n_max))
    print(total)

if __name__ == '__main__':
    main()
