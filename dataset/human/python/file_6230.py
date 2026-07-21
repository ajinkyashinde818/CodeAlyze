S = input()

ans=0
num = [int(i) for i in S]
num.reverse()

def judge(keta):
    if keta >= len(S):
        return true
    tmp = num[keta]
    if tmp < 5:
        return false
    elif tmp > 5:
        num[keta] = 10 - num[keta]
        num[keta+1] += 1
        return true
    else:
        if judge(keta):
            pass
        
for i in range(len(S)-1):
    tmp = num[i]
    if tmp < 5:
        pass
    elif tmp > 5:
        num[i] = 10-num[i]
        num[i+1] +=1
    else:
        if num[i+1] >= 5:
            num[i] = 10-num[i]
            num[i+1] +=1
        else:
            pass

last = len(S)-1
ans = 0
if num[last] > 5:
    num[last] = 10 - num[last]
    ans =1
print(sum(num)+ans)
