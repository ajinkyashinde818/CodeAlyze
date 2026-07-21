s = input()
n = len(s)
e = 0
def judge(a,b,c):
    if c[a-5:a] == "erase":
        b = 5
        return b
    elif c[a-5:a] == "dream":
        b = 5
        return b
    elif c[a-6:a] == "eraser":
        b = 6
        return b
    elif c[a-7:a] == "dreamer":
        b = 7
        return b
    else:
        return 100
while n >= 5:
    e = judge(n,e,s)
    if e == 100:
        break
    else:
        n = n - e
if n == 0:
    print("YES")
else:
    print("NO")
