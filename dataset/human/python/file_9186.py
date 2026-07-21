def Hantei(S):
    res = False
    dream = list("dream")
    dreamer = list("dreamer")
    erase = list("erase")
    eraser = list("eraser")

    flg = 0
    if S[-1] == dream[-1]:
        flg = 1
    elif S[-1] == dreamer[-1] and S[-2] == dreamer[-2] and S[-3] == dreamer[-3]:
        flg = 2
    elif S[-1] == erase[-1]:
        flg = 3
    elif S[-1] == eraser[-1] and S[-2] == eraser[-2] and S[-3] == eraser[-3]:
        flg = 4

    if flg == 1:
        S.pop()
        if S.pop()==dream[-2] and S.pop()==dream[-3] and S.pop()==dream[-4] and S.pop()==dream[-5]:
            res = True
    if flg == 2:
        S.pop()
        S.pop()
        S.pop()
        if S.pop()==dreamer[-4] and S.pop()==dreamer[-5] and S.pop()==dreamer[-6] and S.pop()==dreamer[-7]:
            res = True
    if flg == 3:
        S.pop()
        if S.pop()==erase[-2] and S.pop()==erase[-3] and S.pop()==erase[-4] and S.pop()==erase[-5]:
            res = True
    if flg == 4:
        S.pop()
        S.pop()
        S.pop()
        if S.pop()==eraser[-4] and S.pop()==eraser[-5] and S.pop()==eraser[-6]:
            res = True
            
    return res

S = list(input())
while True:
    if Hantei(S) == False:
        print("NO")
        break
    if len(S) == 0:
        print("YES")
        break
