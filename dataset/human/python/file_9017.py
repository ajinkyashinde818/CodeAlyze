from collections import deque
import sys

def fnw(n,s):
    sm=deque([])
    if n<=len(s):
        for _ in range(n):
            sm.append(s.popleft())
    return ''.join(sm)

def jfws(s):
    fws=fnw(5,s)
    if fws=='dream':
        fws=fnw(2,s)
        if fws=='er':
            if s:
                if s[0]=='a':
                    s.extendleft(deque(reversed(list(fws))))
        else:
            s.extendleft(deque(reversed(list(fws))))
        return False
    elif fws=='erase':
        fws=fnw(1,s)
        if fws!='r' and fws!='':
            s.appendleft(fws)
        return False
    else:
        return True 

def main(s):
    while s:
        if jfws(s):
            return 'NO'
    return 'YES'

s=deque(sys.stdin.readline().strip())
print(main(s))
