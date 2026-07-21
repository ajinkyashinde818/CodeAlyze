def main():
    A, B, C = map(int, input().split())
    ans = 0

    if C >= A:
        ans += A
        C -= A
    else:
        ans += C
        C = 0

    if C <= B:
        ans += C + B
        C = 0
    else:
        ans += B * 2
        C -= B

    if C >= 1:
        ans += 1

    print(ans)

if __name__ == "__main__":
    main()
