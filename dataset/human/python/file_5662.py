S = input()
S = list(S)
S_no_x = []
def is_kaibun(kaibun):
    for i in range(len(kaibun)//2):
        if kaibun[i] != kaibun[-i-1]:
            return False
    return True
inds = []
for i,c in enumerate(S):
    if c != "x":
        S_no_x.append(c)
        inds.append(i)
if not is_kaibun(S_no_x):
    print(-1)
else:
    l = len(S_no_x)

    if l == 0:
        print(0)
    else:
        mae = ""
        usiro = ""
        if l % 2 == 0:
            mae_ind = inds[l // 2 - 1]
            usiro_ind = inds[l // 2]
            mae = S[:mae_ind +1]
            usiro = S[usiro_ind :]
        else:
            center = inds[l // 2]
            mae = S[:center]
            usiro = S[center +1:]

        usiro.reverse()
        usiro_x = []
        mae_x = []
        cot = 0
        usiro.append("@")
        for c in usiro:
            if c == "x":
                cot += 1
            else:
                usiro_x.append(cot)
                cot = 0
        cot = 0
        mae.append("@")
        for c in mae:
            if c == "x":
                cot += 1
            else:
                mae_x.append(cot)
                cot = 0
        ans = 0
        for a,b in zip(mae_x,usiro_x):
            ans += abs(a-b)
        print(ans)
