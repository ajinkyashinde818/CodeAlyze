def Main(S, Q, q):
    pre = []
    suf = []
    flipped = False
    for i in range(Q):
        if q[i][0] == '1':
            if not flipped:
                flipped = True
            else:
                flipped = False
        elif q[i][0] == '2':
            if q[i][1] == '1':
                if not flipped:
                    pre.append(q[i][2])
                else:
                    suf.append(q[i][2])
            elif q[i][1] == '2':
                if not flipped:
                    suf.append(q[i][2])
                else:
                    pre.append(q[i][2])
    pre.reverse()
    ans = pre + list(S) + suf
    if flipped:
        ans.reverse()
    return "".join(ans)              
    
def main():
    S = str(input())
    Q = int(input())
    q = []
    for i in range(Q):
        q.append(list(map(str, input().split())))
    print(Main(S, Q, q))

if __name__ == '__main__':
    main()
