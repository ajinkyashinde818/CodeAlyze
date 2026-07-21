from collections import deque


def main():
    S = input()
    q = deque(S)
    order = 1
    Q = int(input())
    for _ in range(Q):
        X = input().split()
        if X[0] == "1":
            order = 3 - order
        else:
            f, c = int(X[1]), X[2]
            if f == order:
                q.appendleft(c)
            else:
                q.append(c)
    ans = "".join(q)
    if order == 2:
        ans = ans[::-1]
    print(ans)


if __name__ == "__main__":
    main()
