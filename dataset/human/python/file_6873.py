from collections import deque
def main():
    S=input()
    Q=int(input())
    d = deque(S)
    is_forward = True
    for _ in range(Q):
        q=input()
        if q[0] == '1':
            is_forward = not is_forward
        else:
            _, F, C = q.split()
            if F == '1':
                if is_forward:
                    d.appendleft(C)
                else:
                    d.append(C)
            else:
                if is_forward:
                    d.append(C)
                else:
                    d.appendleft(C)
    if is_forward:
        for s in d:
            print(s, sep="", end="")
    else:
        for s in reversed(d):
            print(s, sep="", end="")
    print()
    return

if __name__ == '__main__':
    main()
