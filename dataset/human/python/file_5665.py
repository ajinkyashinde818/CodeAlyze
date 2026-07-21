s = input()
def isp(str): return 1 if str == str[::-1] else 0

x_cnt=0
nox_s=[]
for c in s:
    if c=="x":
        x_cnt+=1
    else:
        nox_s.append(c)

if not isp(nox_s):
    print("-1")
    exit()

x_lis=[]
cnt=0
for c in s:
    if c=="x":
        cnt+=1
    else:
        x_lis.append(cnt)
        cnt=0
x_lis.append(cnt)
ans=0

for i in range(len(x_lis)):
    if x_lis[i] != x_lis[-i-1]:
        ans+= abs(x_lis[i] - x_lis[-i-1])

print(int(ans/2))
