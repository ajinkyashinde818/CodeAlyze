def main():
    tmp = input().split(" ")
    k = int(tmp[0])

    a = input().split(" ")
    a = [int(i) for i in a]

    ans = []
    for i in range(len(a)):
        if i == 0:
            ans.append(k - a[-1] + a[i])
        else:
            ans.append(a[i] - a[i - 1])
        
    print(sum(ans) - max(ans))


if __name__ == '__main__':
    main()
