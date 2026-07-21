S = list(map(str, input()))
q = int(input())
Q =[list(map(str, input().split())) for k in range(q)]
rev = False
f1 = []
f2 = []
def pls(n):
    global rev
    if n[0] == "1":
        rev = not rev
    else:
        if n[1] == "1":
            if rev:
                f2.append(n[2])
            else:
                f1.append(n[2])
        else:
            if rev:
                f1.append(n[2])
            else:
                f2.append(n[2])

for k in range(q):
    pls(Q[k])

if rev:
    S.reverse()
    f2.reverse()
    ans = f2 + S + f1
else:
    f1.reverse()
    ans = f1 + S + f2

print("".join(map(str, ans)))
