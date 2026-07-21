def solve():
    S = sorted(input())
    T = sorted(input(), reverse=True)
    lim = min(len(S), len(T))
    for i in range(lim):
        if (S[i]) > T[i]:
            print("No")
            break
        if S[i] == T[i]:
            continue
        else:
            print("Yes")
            break
    else:
        if len(S)<len(T):
            print("Yes")
        else:
            print("No")

if __name__ == '__main__':
    solve()
