import math
n = int(input())
s = [0 if i == "W" else 1 for i in list(input())]
cnt = 0
c = 1
for i in range(n * 2):
    if (s[i] + cnt) % 2 != 0:
        cnt += 1
    else:
        c = (c * (cnt if cnt != 0 else 1)) % (10 ** 9 + 7)
        cnt -= 1
    if cnt < 0:
        print(0)
        exit()
if cnt != 0:
    print(0)
else:
    print((c * math.factorial(n)) % (10 ** 9 + 7))
