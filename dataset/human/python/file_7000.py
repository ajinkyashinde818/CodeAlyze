S = input()
Q = int(input())
 
A = ""
B = ""
count = 0

Que = []
ope = []

def rev(s):
    re = ""
    for i in range(len(s)):
        re = re + s[len(s) - 1 - i]
    return re
 
for i in range(Q):
    k = input()
    if k == "1":
        count += 1
        Que.append("1")
        ope.append("0")
    else:
        Que.append("2")
        ope.append([k[2],k[4]])
 
cou = 0
 
if count % 2 == 0:
    for i in range(Q):
        if Que[i] == "1":
            cou += 1
        else:
            if (int(ope[i][0]) + cou) % 2 == 1:
                A = ope[i][1] + A
            else:
                B = B + ope[i][1]
else:
    for i in range(Q):
        if Que[i] == "1":
            cou += 1
        else:
            if (int(ope[i][0]) + cou) % 2 == 1:
                A = A + ope[i][1]
            else:
                B = ope[i][1] + B
 
if count % 2 == 0:
    S = A + S + B
else:
    S = rev(S)
    S = B + S + A
 
print(S)
