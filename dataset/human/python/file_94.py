def main(R, G, B, N):
    count = 0
    for r in range(N+1):
        for g in range(N+1):
            remain = N - R * r - G * g
            if remain >= 0 and remain % B == 0:
                count += 1
    return count


if __name__ == "__main__":
    R, G, B, N = list(map(int, input().split()))
    print(main(R, G, B, N))
