from collections import deque

S = input()
Q = int(input())

reverse = 1 #reverse == 1 -> 正常, reverse == -1 -> 逆から

d = deque(S)

for i in range(Q):
    Query_tmp = list(map(str, input().split()))
    
    if Query_tmp[0] == "1":
        reverse *= -1
        # S = S[::-1]
    else:
        Ci = Query_tmp[2]

        if Query_tmp[1] == "1":
            if reverse == 1:
                d.appendleft(Ci)
            else:
                rev_Ci = Ci[::-1]
                d.append(rev_Ci)
        else:
            if reverse == 1:
                d.append(Ci)
            else:
                rev_Ci = Ci[::-1]
                d.appendleft(rev_Ci)
    
    # if reverse == 1:
    #     print(S)
    # else:
    #     print(S[::-1])

if reverse == -1:
    d.reverse()

print("".join(d))
