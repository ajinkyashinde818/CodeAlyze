from collections import deque

def main():
    S = list(input())
    Q = int(input())
    l = [list(input().split(' ')) for _ in range(Q)]

    d = deque(S)

    FLAG = False

    for li in l:
        if int(li[0]) == 1: # 前後反転
            if FLAG == True:
                FLAG = False
            else:
                FLAG = True
        
        elif int(li[0]) == 2: # 追加, li[1] == 1 => li[2]を先頭に，li[1] == 2 => li[2]を末尾
            if int(li[1]) == 1:
                if FLAG == True:
                    d.append(li[2])
                else:
                    d.appendleft(li[2])
            elif int(li[1]) == 2:
                if FLAG == True:
                    d.appendleft(li[2])
                else:
                    d.append(li[2])

    S = ''.join(d)
    if FLAG:
        S = S[::-1]
    print(S)


main()
