def main():
    n = int(input())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    c = list(map(int, input().split()))

    ans = 0
    for i, num in enumerate(a):
        ans += b[num-1]
        if i < len(a)-1:
            if num+1 == a[i+1]:
                ans += c[num-1]
    print(ans)


if __name__ == "__main__":
    main()
