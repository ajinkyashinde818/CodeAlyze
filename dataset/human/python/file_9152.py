from sys import stdin
S=(stdin.readline().rstrip())
while 1:
    cnt=4
    for i in ["dream","dreamer","erase","eraser"]:
        if S[-len(i):] == i:
            S = S[:(len(S)-len(i))]
        else:
            cnt-=1
            
    if S == "":
        print("YES")
        break
        
    if cnt == 0:
        print("NO")
        break
