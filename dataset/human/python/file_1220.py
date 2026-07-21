def main():
    n = int(input())
    inlis = list(map(int, input().split()))

    total = sum(inlis)
    ans = 10 ** 20

    for i in range(n-1):
        if i == 0:
            x = inlis[i]
        else:
            x += inlis[i]
        y = total - x
        tmp = abs(x-y)
        if tmp < ans:
            ans = tmp

    print(ans)





if __name__ == "__main__":
    main()
