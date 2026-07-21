def main():
    import sys
    from collections import deque
    input = sys.stdin.readline

    S = input().rstrip('\n')
    ans = deque()
    ans.append(S)
    q = int(input())
    rev = 1
    for _ in range(q):
        query = input().rstrip('\n')
        if query == '1':
            rev *= -1
        else:
            _, f, c = query.split()
            if rev == 1:
                if f == '1':
                    ans.appendleft(c)
                else:
                    ans.append(c)
            else:
                if f == '1':
                    ans.append(c)
                else:
                    ans.appendleft(c)
    ans = ''.join(ans)
    if rev == -1:
        ans = ans[::-1]
    print(ans)


if __name__ == '__main__':
    main()
