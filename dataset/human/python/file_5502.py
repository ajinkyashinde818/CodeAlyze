X,Y = raw_input().split()
def check(a):
    if a == "A":
        return 1
    elif a == "B":
        return 2
    elif a == "C":
        return 3
    elif a == "D":
        return 4
    elif a == "E":
        return 5
    elif a == "F":
        return 6
x = check(X)
y = check(Y)
if x > y:
    print(">")
elif x < y:
    print("<")
else:
    print("=")
