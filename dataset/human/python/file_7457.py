from collections import deque

letters = deque(input())
n = int(input())

top = "head"

for i in range(0,n):
    command = list(input().split())
    if command[0] == "1":
        if top == "head":
            top = "tail"
        else:
            top = "head"
        
    
    else:
        if (command[1] == "2" and top == "head") or (command[1] == "1" and top == "tail"):
            letters.append(command[2])
        else:
            letters.appendleft(command[2])

if top == "tail":
    letters.reverse()
    
 
ans = "".join(letters)
print(ans)
