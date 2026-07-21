S = input() 
Q = int(input())
rlist, llist = [], []
flag, cnt = 0, 0

def trans(f):
    if f == 1:
        f = 0
    elif f == 0:
        f = 1
    return f

def pros(f, r, add):
    if f == 0:
        if r == "1":
            llist.append(lists[2])
        elif r == "2":
            rlist.append(lists[2])
    elif f == 1:
        if r == "2":
            llist.append(lists[2])
        elif r == "1":
            rlist.append(lists[2])

for i in range(Q):
    lists = input().split()
    if lists[0] == "1":
        flag = trans(flag)
        cnt += 1
    else:
        pros(flag, lists[1], lists[2])
        
llist.reverse()
        
S = "".join(llist) + S + "".join(rlist)

if cnt % 2 == 1:
    S = S[::-1]
print(S)
