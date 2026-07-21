def resolve():
    s = input()
    t = input()
    ls = list()
    lt = list()
    for c in s:
        ls.append(ord(c))
    for c in t:
        lt.append(ord(c))
    ls.sort()
    lt.sort()
    
    can = False
    if len(ls) == ls.count(ls[0]) and len(lt) == lt.count(lt[0]) and len(ls) < len(lt):
        can = True
    else:
        for i in range(len(lt)-1, -1, -1):
            if ls[0] < lt[i]:
                can = True
                break

    if can:
        print("Yes")
    else:
        print("No")
resolve()
