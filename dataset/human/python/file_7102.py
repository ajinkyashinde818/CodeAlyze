def main():
    from collections import deque
    import sys
    input = sys.stdin.readline

    s = input().rstrip()
    q = int(input())

    dq = deque(s)
    head_is_0 = 1
    for _ in range(q):
        query = iter(input().rstrip().split())
        if next(query) == '1':
            head_is_0 ^= 1
        elif (next(query) == '2') ^ head_is_0:
            dq.appendleft(next(query))
        else:
            dq.append(next(query))

    if not head_is_0:
        dq.reverse()

    ret = ''.join(dq)
    print(ret)


if __name__ == '__main__':
    main()
