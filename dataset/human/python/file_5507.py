def test():
    num = {"A":10,"B":11,"C":12,"D":13,"E":14,"F":15}
    x,y = input().split()
    if num[x] < num[y]:
        print("<")
    elif num[x] > num[y]:
        print(">")
    else:
        print("=")


if __name__ == "__main__":
    test()
