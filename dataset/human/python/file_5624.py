def main():
    S = input()
    from collections import deque
    S = deque(S)
    ans = 0
    while S:
        if S[0] == S[-1]:
            S.popleft()
            if S:
                S.pop()
        elif S[0] != "x" and S[-1] != "x":
            return print(-1)
        elif S[0] == "x":
            S.append("x")
            ans += 1
        else:
            S.appendleft("x")
            ans += 1
    print(ans)


if __name__ == '__main__':
    main()
