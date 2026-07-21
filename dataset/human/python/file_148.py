def main():
    R, G, B, N = map(int, input().split())
    ans = 0
    for r in range(N // R + 1):
        for g in range(N // G + 1):
            if r * R + g * G > N:
                break
            tmp = r * R + g * G
            b = (N - tmp) // B
            if (N - tmp) % B == 0 and N == tmp + b * B:
                ans += 1
                

    print(ans)


if __name__ == "__main__":
    main()
