def main():
    R, G, B, N = map(int, input().split())
    ans = 0
    cnt = 0
    for r in range(N + 1):
        for g in range(N + 1 - (R * r)):
            if (N - (R * r) - (G * g)) % B == 0 and N - (R * r) - (G * g) >= 0:
                cnt += 1
 
    print(cnt)
 
 
if __name__ == '__main__':
    main()
