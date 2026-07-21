from collections import deque

def main():
    S = input()
    Q = int(input())
    q = deque(S)
    cnt = 0
    for _ in range(Q):
        query = list(input().split())
        if query[0] == '1':
            cnt += 1
        else:
            if query[1] == '1':
                if cnt % 2 == 0:
                    q.appendleft(query[2])
                else:
                    q.append(query[2])
            else:
                if cnt % 2 == 1:
                    q.appendleft(query[2])
                else:
                    q.append(query[2])

    if cnt % 2 == 0:
        print(*q, sep ="")
    else:
        q.reverse()
        print(*q, sep ="")







if __name__ == "__main__":
    main()
