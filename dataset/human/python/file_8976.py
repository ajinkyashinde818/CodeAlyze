import sys
S = input()[::-1]
ls = ["maerd", "remaerd", "esare", "resare"]
n = 0
while n != len(S):
    flag = False
    for i in ls:
        tmp_n = len(i)
        if S[n:n+tmp_n] == i:
            n += len(i)
            flag = True
            break
    if not flag:
        print("NO")
        sys.exit()
print("YES")
