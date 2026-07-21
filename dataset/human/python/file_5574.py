import math
s = input().strip()
A = []
B = [0 for _ in range(len(s)+1)]
y = ""
for i in range(len(s)):
    if s[i]!="x":
        y += s[i]
        A.append(i)
        B[i+1] = B[i]
    else:
        B[i+1] = B[i]+1
flag=0
cnt = 0
for i in range(len(y)//2):
    if y[i]!=y[-(i+1)]:
        flag = 1
        cnt = -1
        break
if flag==0 and len(y)>0:
    if B[A[0]]!=B[-1]-B[A[-1]]:
        cnt += abs(B[A[0]]-(B[-1]-B[A[-1]]))
    for i in range(1,math.ceil(len(A)/2)):
        if B[A[i]]-B[A[i-1]] != B[A[-i]]-B[A[-(i+1)]]:
            cnt += abs(B[A[i]]-B[A[i-1]]-(B[A[-i]]-B[A[-(i+1)]]))
print(cnt)
