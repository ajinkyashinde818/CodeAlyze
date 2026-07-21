def main():
    R, G, B, N = map(int, input().split())
    R, G, B = sorted([R, G, B])
    result = 0
    for i in range(N // G + 1):
        for j in range(N // B + 1):
            if (N - G*i - B*j) < 0:
                break
            elif (N - G*i - B*j) % R == 0:
                result += 1
    print(result)
main()
