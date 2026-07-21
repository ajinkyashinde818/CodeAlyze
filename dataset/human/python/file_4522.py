n = int(input())
if n == 1:
    print(0)
    exit()
    
def fact(n):
    arr = []
    temp = n
    for i in range(2, int(-(-n**0.5//1))+1):
        if temp%i==0:
            cnt=0
            while temp%i==0:
                cnt+=1
                temp //= i
            arr.append(cnt)

    if temp!=1:
        arr.append(1)

    if arr==[]:
        arr.append(1)

    return arr

l = [0] + [1]*2+[2]*3+[3]*4+[4]*5+[5]*6+[6]*7+[7]*8+[8]*9+[9]*10
ls = fact(n)
ans = 0
for v in ls:
    ans += l[v]
print(ans)
