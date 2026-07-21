def main():
    R, G, B, N = (int(i) for i in input().split())
    ans = 0
    for r in range(N+1):
        for g in range(N+1):
            need = N - r*R - g*G  # 必要ボール数
            if need < 0:
                continue
            b = 0--need//B
            if r*R + g*G + b*B == N:
                ans += 1
                # print(r, g, b)
    print(ans)


if __name__ == '__main__':
    main()
