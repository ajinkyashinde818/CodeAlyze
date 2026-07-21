def main():
    r, g, b, n = map(int, input().split())

    cnt = 0
    for i in range(n+1):
        for j in range(n+1):
            b_num = n - r*i - g*j
            if b_num >= 0 and b_num % b == 0:
                cnt += 1
    print(cnt)

if __name__ == "__main__":
    main()
