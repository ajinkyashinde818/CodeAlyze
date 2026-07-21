from sys import stdin
sin = stdin.readline().rstrip()
q = int(stdin.readline().rstrip())
li = [list(stdin.readline().rstrip().split()) for _ in range(q)]
point = 0
omote = ""
ura = ""
for i in li:
    if i[0] == "1":
        point += 1
    elif i[0] == "2":
        if i[1] == "1":
            if point%2 == 0:
                omote += i[2]
            else:
                ura += i[2]
        else:
            if point%2 == 0:
                ura += i[2]
            else:
                omote += i[2]
if point%2 == 0:
    omote = omote[::-1]
    sin = omote + sin + ura
    print(sin)
else:
    sin = sin[::-1]
    ura = ura[::-1]
    sin = ura + sin + omote
    print(sin)
