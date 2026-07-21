def colorful_subsequence(N: int, S: str)->int:
    MOD = (10 ** 9) + 7
    cum = {}
    for c in S:
        cum.setdefault(c, 0)
        cum[c] += 1

    values = list(cum.values())
    count = 1
    for v in values:
        count *= (1 + v)
        count %= MOD

    return (count-1) % MOD


if __name__ == "__main__":
    N = int(input())
    S = input()
    ans = colorful_subsequence(N, S)
    print(ans)
