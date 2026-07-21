X,Y = map(str,input().split())
def chan(S):
    if S == "A":
        s = 1
    elif S == "B":
        s = 2
    elif S == "C":
        s = 3
    elif S == "D":
        s = 4
    elif S == "E":
        s = 5
    elif S == "F":
        s = 6
    return s

x = chan(X)
y = chan(Y)
if x>y:
    print(">")
elif x<y:
    print("<")
else:
    print("=")
