from collections import defaultdict

MOD = int(1e9) + 7


def main():
    N = int(input())
    S = input()
    cnt = defaultdict(lambda: 0)
    ans = 1
    for c in S:
        ans = ans + ans // (cnt[c]+1)
        cnt[c] += 1
    print(ans % MOD-1)


if __name__ == "__main__":
    main()
