X,Y = input().split()
def Toint(string):
    if string == "A":
        return 10
    elif string == "B":
        return 11
    elif string == "C":
        return 12
    elif string == "D":
        return 13
    elif string == "E":
        return 14
    elif string =="F":
        return 15
    else:
        return int(string)
if Toint(X) < Toint(Y):
    print("<")
elif Toint(X) > Toint(Y):
    print(">")
else:
    print("=")
