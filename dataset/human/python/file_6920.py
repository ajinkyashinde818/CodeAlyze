import collections

def read():
    S = input().strip()
    Q = int(input().strip())
    queries = list()
    for i in range(Q):
        query = input().strip().split()
        t = int(query[0])
        if t == 1:
            queries.append((t, -1, "*"))
        if t == 2:
            f = int(query[1])
            c = query[2]
            queries.append((t, f, c))
    return S, Q, queries

def solve(S, Q, queries):
    head = collections.deque()
    tail = collections.deque()
    is_fliped = False
    for t, f, c in queries:
        if t == 1:
            is_fliped = not is_fliped
        if t == 2:
            is_head = (f == 1) ^ is_fliped
            if is_head:
                head.appendleft(c)
            else:
                tail.append(c)
    s = ''.join(head) + S + ''.join(tail)
    if is_fliped:
        s = ''.join(reversed(s))
    return s


if __name__ == '__main__':
    inputs = read()
    print("{}".format(solve(*inputs)))
