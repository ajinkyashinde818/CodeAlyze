from collections import deque

def resolve():
    S = deque(input())
    Q = int(input())
    query = [ input().split() for _ in range(Q)]

    sw = True
    for q in query:
        if q[0] == "2":
            if q[1] == "1":
                if sw:
                    S.appendleft(q[2])
                else:
                    S.append(q[2])
            else:
                if sw:
                    S.append(q[2])
                else:
                    S.appendleft(q[2])
        else:
            sw = not sw
    
    if not sw:
        S.reverse()
    print("".join(S))

if __name__ == "__main__":
    resolve()
