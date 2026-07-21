from sys import stdin
S = input()
x = S
y =str()   
N = int(input())
Q =  [list(map(str, stdin.readline().split())) for _ in range(N)]
flag = True
for i in range(N):
    if Q[i][0]=="1":
        flag = not(flag)                
    else: 
        if (Q[i][1] == "2") == (flag == True):
            x += Q[i][2]#先頭
        else :
            y += Q[i][2]
M = "".join([y[::-1],x])
if flag == True:
    print(M)
else:
    print(M[::-1])
