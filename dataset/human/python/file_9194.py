def h(temp):
    if temp[0] == "m":
        a = 0
    elif temp[0] == "r":
        if temp[2] == "m":
            a = 1
        else:
            a = 3
    else:
        a = 2
    return a 

def H(temp,y,a):
    c = 0
    if a == 0 or a == 2:
        for j in range(5):
            if y[a][4-j] != temp[0]:
                return c
            temp.remove(temp[0])
        c = 1
    elif a == 3:
        for j in range(6):
            if y[a][5-j] != temp[0]:
                return c
            temp.remove(temp[0])
        c = 1
    else:
        for j in range(7):
            if y[a][6-j] != temp[0]:
                return c
            temp.remove(temp[0])
        c = 1
    return c


s = input()
y = ['dream','dreamer','erase','eraser'] 
temp = []
t = []
k = len(s)
for i in range(k):
    temp.append(s[k-i-1])
c = 1
while len(temp) != 0 and c == 1:
    a = h(temp)
    c = H(temp,y,a)
if c == 1:
    print("YES")
else :
    print("NO")
