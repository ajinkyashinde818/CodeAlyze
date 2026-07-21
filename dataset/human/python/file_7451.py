from collections import deque
if __name__ == '__main__':

    s = input()
    n = int(input())

    rvflg = False

    d_st = deque()
    d_ed = deque()

    for _ in range(n):
        q = input()
        if len(q) == 1:
            if rvflg:
                rvflg = False
            else:
                rvflg = True
        else:
            i,f,c = map(str,q.split())
            if f == "1":#先頭に追加
                if rvflg:
                    #末尾に追加
                    d_ed.append(c)
                else:
                    #先頭に追加
                    d_st.appendleft(c)
            else:#末尾に追加
                if rvflg:
                    #先頭に追加
                    d_st.appendleft(c)
                else:
                    #末尾に追加
                    d_ed.append(c)

    ans = "".join(d_st) + s + "".join(d_ed)
    #最後に反転するかを決定
    if rvflg:
        ans = ans[::-1]
    print(ans)
