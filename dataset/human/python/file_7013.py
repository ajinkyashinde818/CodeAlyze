import sys
readline = sys.stdin.buffer.readline
from collections import deque
s = readline().rstrip().decode('utf-8')
q = int(readline())
flag = 0
lst1 = deque([])
lst2 = deque([])
for i in range(q):
    t = readline().rstrip().decode('utf-8')
    if t[0] == "1":
        #reverse
        flag = 1-flag
    else:
        com,f,c = t.split()
        if f == "1": #先頭にc追加
            if not flag:
                lst1.append(c)
            else: #反転中
                lst2.append(c)
            

        else: #末尾にc追加
            if not flag:
                lst2.append(c)
            else:
                lst1.append(c)

if not flag:
    lst1.reverse()
    s = "".join(lst1) + s + "".join(lst2) 

    
else:
    lst2.reverse()
    s = s[::-1]
    s = "".join(lst2)+ s + "".join(lst1)



print(s)
