from collections import Counter
def solve(N, S):
    d = 10**9 + 7
    c = Counter(S)
    ans = 1
    for ch, count in c.items():
        ans *= (count + 1)
    ans %= d
    return ans - 1

if __name__ == "__main__":
    N = int(input())
    S = input()
    print(solve(N, S))
