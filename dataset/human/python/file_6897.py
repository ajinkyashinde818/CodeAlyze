def main2(s,x,q):
    res = s
    rev = 1 #-1なら反転中
    lstA = []
    lstB = []
    for op in q:
        if int(op[0]) == 1:
            rev = rev * -1
        elif int(op[1])*rev == 1 or int(op[1])*rev == -2:
            lstA.append(op[2])
        elif int(op[1])*rev == -1 or int(op[1])*rev == 2:
            lstB.append(op[2])
    if rev == 1:
        res = "".join(lstA[::-1])+res+"".join(lstB)
    else :
        res = "".join(lstB[::-1])+res[::-1]+"".join(lstA)
    return res
 
s = input()
x = int(input())
q = [input().split() for _ in range(x)]
print(main2(s,x,q))
