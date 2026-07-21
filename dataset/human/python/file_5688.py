import collections

s = input()
slen = len(s)

sl = collections.deque(list(s))
sl_inv = collections.deque(list(s[::-1]))
cnt = 0
while len(sl)>0:
    if sl[0]== sl_inv[0]:
        sl.popleft()
        sl_inv.popleft()
    elif sl[0] == 'x' and sl_inv[0] !='x':
        sl.popleft()
    elif sl[0] != 'x' and sl_inv[0] == 'x':
        cnt += 1
        sl_inv.popleft()
    elif sl[0] != 'x' and sl_inv[0] != 'x' and sl[0]!=sl_inv[0]:
        print(-1)
        exit()
    if len(sl_inv) ==0:
        break
    #print(sl,sl_inv,cnt)
print(cnt+len(sl_inv))
