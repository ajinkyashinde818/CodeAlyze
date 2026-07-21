import collections

def solve(S, Q, queries):
    S = collections.deque(S)
    is_reversed = False
    for q in queries:
        if q[0] == "1":
            is_reversed = not is_reversed
        else:
            _, f, c = tuple(q.split(" "))

            if is_reversed:
                f = "2" if f == "1" else "1"

            if f == "1":
                S.appendleft(c)
            else:
                S.append(c)

    if is_reversed:
        S = reversed(S)

    return "".join(S)

if __name__ == "__main__":
    S = input()
    Q = int(input())
    queries = []
    for _ in range(Q):
        queries.append(input())

    print(solve(S, Q, queries))
