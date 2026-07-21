import sys
input = sys.stdin.readline


def read():
    S = input().strip()
    return S,


def is_palindrome(seq):
    n = len(seq)
    for i in range(n//2):
        if seq[i] != seq[n-i-1]:
            return False
    return True


def solve(S):
    S = "*" + S + "*"
    T = [a for a in S if a != "x"]
    N = len(T) // 2 + len(T) % 2
    if not is_palindrome(T):
        return -1
    l = 0
    r = len(S)-1
    c = 0
    while c < N:
        if S[l] != "x":
            c += 1
        l += 1
    c = 0
    while c < N:
        if S[r] != "x":
            c += 1
        r -= 1
    
    L = S[:l]
    R = S[r+1:][::-1]
    ans = 0
    l, r = 0, 0
    for i in range(N+1):
        lc = 0
        rc = 0
        while l < len(L) and L[l] == "x":
            lc += 1
            l += 1
        while r < len(R) and R[r] == "x":
            rc += 1
            r += 1
        ans += abs(lc-rc)
        l += 1
        r += 1
    return ans


if __name__ == '__main__':
    inputs = read()
    print(solve(*inputs))
