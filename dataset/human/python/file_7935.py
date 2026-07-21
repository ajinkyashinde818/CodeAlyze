def exec():
    s = input()
    a,b,c = 0,0,0
    for ch in s :
        if ch == 'a':
            a += 1
        elif ch == 'b':
            b += 1
        elif ch == 'c':
            c += 1
    if a == 1 and b == 1 and c == 1:
        print("Yes")
    else:
        print("No")

if __name__ == "__main__":
  exec()
