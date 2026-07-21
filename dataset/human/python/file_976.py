n = int(input())
s = input()
lr = ["" for i in range(2*n)]
sm = 0
for i in range(2*n):
    if s[i] == "W":
        if sm%2 == 0:
            lr[i] = "R"
            sm -= 1
        else:
            lr[i] = "L"
            sm += 1
    else:
        if sm%2 == 0:
            lr[i] = "L"
            sm += 1
        else:
            lr[i] = "R"
            sm -= 1
    if sm < 0:
        print(0)
        exit()
if sm != 0:
    print(0)
    exit()

def f(x,y):
    r = 1
    for i in range(y):
        r = (r * (x-i))%(10**9+7)
    return r


suml = 0
sumr = 0
sp = "R"
ans = 1
lr.append("L")
for i in range(2*n+1):
    if sp == "R" and lr[i] == "L":
        ans = (ans * f(suml,sumr)) % (10**9+7)
        suml = suml - sumr
        sumr = 0
    if lr[i] == "L":
        suml += 1
    elif lr[i] == "R":
        sumr += 1
    sp = lr[i]

for i in range(1,n+1):
    ans = (ans * i)%(10**9+7)
print(ans)
