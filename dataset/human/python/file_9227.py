d = ["dream", "dreamer", "erase", "eraser"]

def getDevidedString(s):
    i = 0
    while i < 4:
        position = len(d[i]) * -1
        str = s[position:]
        if str == d[i]:
           return s[0:position]
        i += 1
    return s

S = input()

while len(S) != 0:
    tmp = getDevidedString(S)
    if len(S) != len(tmp):
        S = tmp
    else:
        break

if len(S)== 0:
    print("YES")
else:
    print("NO")
