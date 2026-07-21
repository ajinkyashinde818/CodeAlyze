from sys import stdin

def main():
    S = list(stdin.readline().rstrip())
    Q = int(input())
    rev = 0
    head = []
    tail = []

    for _ in range(Q):
        q = stdin.readline()
        if q[0] == "1":
            rev = (rev+1)%2
        else:
            if q[2] == "1":
                if rev == 0:
                    head.append(q[4])
                else:
                    tail.append(q[4])
            else:
                if rev ==0:
                    tail.append(q[4])
                else:
                    head.append(q[4])

    if rev == 0:
        ans = "".join(head[::-1] + S + tail)
    else:
        ans = "".join(tail[::-1] + S[::-1] + head)
    
    print(ans)
    """
    S = stdin.readline().rstrip() 
    Q = int(input())
    rev = 0
    for _ in range(Q):
        q = stdin.readline()

        if q[0] == "1":
            rev = (rev+1)%2
        else:
            if q[2] == "1":
                if rev == 0:
                    S = "{}{}".format(q[4], S)
                else:
                    S = "{}{}".format(S, q[4])
            else:
                if rev ==0:
                    S = "{}{}".format(S, q[4])
                else:
                    S = "{}{}".format(q[4], S)
    if rev == 1:
        print(S[::-1])
    else:
        print(S)
    """
main()
