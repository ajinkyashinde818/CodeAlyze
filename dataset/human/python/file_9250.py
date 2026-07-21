def main():
    s=input()
    rs=s[::-1]
    c1="maerd"
    c2="remaerd"
    c3="esare"
    c4="resare"
    t = ""
    cc=0
    while cc < len(rs):
        if rs[cc]=="m":
            t = t+c1
            cc += 5
        elif rs[cc]=="e":
            t = t+c3
            cc += 5
        elif rs[cc] =="r":
            if len(rs[cc:]) < 3:
                return "NO"
            elif rs[cc:cc+3] == "rem":
                t = t+c2
                cc += 7
            elif rs[cc:cc+3] == "res":
                t = t+c4
                cc += 6
            else:
                return "NO"
        else:
            return "NO"
    if rs == t:
        return "YES"
    else:
        return "NO"

print(main())
