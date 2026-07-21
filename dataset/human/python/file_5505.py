a,b = input().split()

def xy(a):
    if a =="A":
        return 10
    elif a =="B":
        return 11
    elif a =="C":
        return 12
    elif a =="D":
        return 13
    elif a =="E":
        return 14
    elif a =="F":
        return 15
    
if xy(a) > xy(b):
    print(">")
elif xy(a) < xy(b):
    print("<")
else:
    print("=")
