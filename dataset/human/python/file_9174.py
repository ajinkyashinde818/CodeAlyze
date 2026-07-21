s = input()
n = len(s)
def judge(n,s):
    if s[n-5:n] == "erase":
        return n-5
    elif s[n-5:n] == "dream":
        return n-5
    elif s[n-6:n] == "eraser":
        return n-6
    elif s[n-7:n] == "dreamer":
        return n-7
    else:
        return -1

while n>=5:
    n = judge(n,s)

if n == 0:
    print("YES")
else:
    print("NO")
