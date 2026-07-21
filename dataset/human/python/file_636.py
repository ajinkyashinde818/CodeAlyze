def main():
    _ = int(input())
    A = [int(i) for i in input().split()]
    sumA = sum(abs(a) for a in A)
    minus_cnt = sum(1 if a < 0 else 0 for a in A)
    if minus_cnt % 2 == 0 or (0 in A):
        print(sumA)
    else:
        min_v = min(abs(a) for a in A)
        print(sumA - min_v*2)


if __name__ == '__main__':
    main()
