def main():
    n = int(input())
    a = list(map(int, input().split()))
    abs_a = list(map(abs, a))

    cnt = 0
    for i in a:
        if i < 0:
            cnt += 1
        elif i == 0:
            print(sum(abs_a))
            exit()

    if cnt % 2 == 0:
        print(sum(abs_a))
    else:
        print(sum(abs_a) - 2 * min(abs_a))

main()
