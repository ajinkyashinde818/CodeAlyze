s = input()
q = int(input())

def addflont(s,c):
    text = "".join([c,s])
    return text
def addback(s,c):
    text = "".join([s,c])
    return text

reverse = 0
r = "";u = ""
for i in range(q):
    t = input()
    if t[0]=="1":
        reverse = reverse^1
    if t[0]=="2":
        if t[2]=="1":
            if reverse==0:
                r = addflont(r,t[4])
            else:
                u = addback(u,t[4])
        elif t[2]=="2":
            if reverse==0:
                u = addback(u,t[4])
            else:
                r = addflont(r,t[4])

s = r + s + u
if reverse==1:
    print(s[::-1])
else:
    print(s)
