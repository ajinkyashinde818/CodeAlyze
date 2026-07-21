s = input()

def calc(s):
    if s == "":
        return print("YES")
    if s.find("dreameraser") != -1:
        s = s.replace("dreameraser", "")
        return calc(s)
    elif s.find("dreamerase") != -1:
        s = s.replace("dreamerase", "")
        return calc(s)        
    elif s.find("dreamer") != -1:
        s = s.replace("dreamer", "")
        return calc(s)
    elif s.find("dream") != -1:
        s = s.replace("dream", "")
        return calc(s)
    elif s.find("eraser") != -1:
        s = s.replace("eraser", "")
        return calc(s)
    elif s.find("erase") != -1:
        s = s.replace("erase", "")
        return calc(s)
    return print("NO")

calc(s)
