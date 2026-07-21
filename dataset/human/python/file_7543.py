def main():
    import sys
    input = sys.stdin.readline

    s = input()
    s = s[0:len(s)-1]
    Q = int(input())
    head = []
    tail = []

    flg = 0 # 0:sonomama 1:gyakuten
    for _ in range(Q):
        q = input().split()
        if q[0] == "1":
            if flg == 0:
                flg = 1
            else:
                flg = 0
        elif q[0]=="2":
            index,tmp = q[1],q[2]
            if (index == "1" and flg ==0) or (index == "2" and flg ==1):
                head.append(tmp)
            elif (index == "2" and flg == 0) or (index == "1" and flg == 1):
                tail.append(tmp)

    s1 = "".join(head)
    s1 = s1[::-1]
    s2 = "".join(tail)
    ans = s1 + s + s2
    if flg == 1:
        ans = ans[::-1]

    print(ans)

if __name__ == '__main__':
    main()
