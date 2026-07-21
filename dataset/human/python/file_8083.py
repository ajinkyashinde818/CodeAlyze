def main():
    K, S = map(int, input().strip().split())
    result = 0
    for z in range(0, K+1):
        target = S - z
        k = 0
        while k <= K:
            if 0 <= target - k <= K:
                result += 1
                k += 1
            else:
                k += 1
                continue
    print(result)

if __name__ == "__main__":
    main()
