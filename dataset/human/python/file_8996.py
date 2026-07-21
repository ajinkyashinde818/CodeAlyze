import collections
q = collections.deque()
q.append(input())

cnt = 0

while q:
    x = q.popleft()
    
    if x in ["dream","dreamer","erase","eraser"]:
        cnt += 1
        
    else:
        if 5 < len(x):
            if x[:5] in ["dream","erase"]:
                q.append(x[5:])
                
        if 6 < len(x):
            if x[:6] == "eraser":
                q.append(x[6:])
                
        if 7 < len(x):
            if x[:7] == "dreamer":
                q.append(x[7:])
                
print("YNEOS"[cnt==0::2])
