import sys
s = list(input())
if list(set(s)) == ["x"]:
    print(0)
    sys.exit()
t = [i for i in s if i != "x"]
n = len(t)
if "".join(t) != "".join(t[::-1]):
    print(-1)
else:
    dic = {}
    cnt = 0
    if n % 2 == 0:
        for j in range(len(s)):
            if s[j] != "x":
                cnt += 1
                if cnt == n//2:
                    a = s[:j+1]
                    a = a[::-1]
                if cnt == n//2 + 1:
                    b = s[j:]
                    break
        c = 0
        fa = []
        fb = []
        for k in range(len(a)):
            if a[k] == "x":
                c += 1
            else:
                fa.append(c)
                c = 0
        fa.append(c)
        c = 0
        for p in range(len(b)):
            if b[p] == "x":
                c += 1
            else:
                fb.append(c)
                c = 0
        fb.append(c)
        ans = 0
        for q in range(len(fa)):
            ans += max(fa[q],fb[q]) - min(fa[q],fb[q])
        print(ans)
    else:
        for j in range(len(s)):
            if s[j] != "x":
                cnt += 1
                if cnt == int(n/2) + 1:
                    a = s[:j+1]
                    a = a[::-1]
                    b = s[j:]
                    break
        c = 0
        fa = []
        fb = []
        for k in range(len(a)):
            if a[k] == "x":
                c += 1
            else:
                fa.append(c)
                c = 0
        fa.append(c)
        c = 0
        for p in range(len(b)):
            if b[p] == "x":
                c += 1
            else:
                fb.append(c)
                c = 0
        fb.append(c)
        ans = 0
        for q in range(len(fa)):
            ans += max(fa[q],fb[q]) - min(fa[q],fb[q])
        print(ans)
