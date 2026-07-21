import sys
input = sys.stdin.readline


def main():
    s = input().strip()
    import collections
    q = collections.deque(s)
    ans = 0
    while q:
        s, t = q[0], q[-1]
        if s == t:
            q.popleft()
            if q:
                q.pop()
        elif s == "x" and t != "x":
            ans += 1
            q.popleft()
        elif s != "x" and t == "x":
            ans += 1
            q.pop()
        else:
            print(-1)
            return
    print(ans)


if __name__ == '__main__':
    main()
