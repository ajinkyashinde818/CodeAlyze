def main():
    from collections import deque
    d = deque([s for s in input()])
    Q = int(input())
    reverse = False

    for i in range(Q):
        q = input().split()
        if q[0] == "1":
            reverse = not reverse
        else:
            if (q[1] == "1" and not reverse) or (q[1] == "2" and reverse):
                d.appendleft(q[2])
            else:
                d.append(q[2])
    
    if reverse:
        d.reverse()
    
    print("".join(d))

if __name__ == '__main__':
    main()
