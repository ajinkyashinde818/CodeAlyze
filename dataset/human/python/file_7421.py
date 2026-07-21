from collections import deque

def main():
    s=deque(input())
    q=int(input())
    
    right=True
    for _ in range(q):
        l=list(map(str,input().split()))
        if l[0]=='1':
            if right:
                right=False
            else:
                right=True
        else:
            if l[1]=='1':
                if right:
                    s.appendleft(l[2])
                else:
                    s.append(l[2])
            else:
                if right:
                    s.append(l[2])
                else:
                    s.appendleft(l[2])
    
    if right:
        print(''.join(s))
    else:
        print(''.join(list(s)[::-1])) 

if __name__=='__main__':
    main()
