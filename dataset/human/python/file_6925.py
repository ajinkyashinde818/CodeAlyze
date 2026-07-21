import sys
input=sys.stdin.readline
from collections import deque

def main():
    S=deque(input().strip())
    q=int(input())
    rev=0
    for _ in range(q):
        query=input().strip()
        if query=='1':
            rev^=1
        else:
            _,f,c=query.split()
            if (int(f)+rev)%2:
                S.appendleft(c)
            else:
                S.append(c)
    if rev:
        S.reverse()
    print(''.join(S))
    
if __name__=='__main__':
    main()
