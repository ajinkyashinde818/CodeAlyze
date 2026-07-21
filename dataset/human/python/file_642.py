def main():
    n = int(input())
    a = [int(x) for x in input().split()]
    count_negative = 0
    for i in range(n):
        if a[i] < 0:
            count_negative += 1
    a = [abs(x) for x in a]
    answer = sum(a)
    if count_negative % 2:
        answer -= 2 * min(a)
    print(answer)


if __name__ == '__main__':
    main()
