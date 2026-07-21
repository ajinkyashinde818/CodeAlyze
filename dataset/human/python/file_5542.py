def hex(s):
    if s=="A" :
        return 10
    elif s=="B" :
        return 11
    elif s=="C" :
        return 12
    elif s=="D" :
        return 13
    elif s=="E" :
        return 14
    elif s=="F" :
        return 15

x,y = map(hex, input().split())
if x > y :
    print(">")
elif x == y :
    print("=")
elif x < y :
    print("<")
