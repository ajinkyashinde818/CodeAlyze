def main():
    n = int(input())
    a = [int(x) for x in input().split()]
    b = [int(x) for x in input().split()]
    c = [int(x) for x in input().split()]

    answer = sum(b)
    for i in range(n-1):
        if a[i+1] == a[i]+1:
            answer += c[a[i]-1]
    print(answer)


if __name__ == '__main__':
    main()
