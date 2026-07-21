def main():
    from collections import deque
    s = deque(list(input()))
    q = int(input())
    query = [input().split() for _ in [0]*q]

    cnt = 0
    for i in range(q):
        if query[i][0] == "1":
            cnt += 1
        else:
            if (cnt+int(query[i][1])) % 2 == 1:
                s.appendleft(query[i][2])
            else:
                s.append(query[i][2])
    if cnt % 2 == 0:
        print("".join(s))
    else:
        print("".join(list(reversed(s))))


main()
