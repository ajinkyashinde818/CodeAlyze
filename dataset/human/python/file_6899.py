def main():
    S = input()
    Q = int(input())
    rev = False # rev=1で反転した状態
    tail = ""
    head = ""
    for i in range(Q):
        query = input()
        if len(query)==1:
            rev = not rev
        else:
            tmp = list(query.split())
            f = int(tmp[1])
            c = tmp[2]
            if rev:
                if f==1:
                    tail+=c
                else:
                    head=c+head
            else:
                if f==1:
                    head=c+head
                else:
                    tail+=c

    ans = tail[::-1]+S[::-1]+head[::-1] if rev else head+S+tail
    print(ans)

main()
