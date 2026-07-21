import sys
from collections import deque
input = lambda: sys.stdin.readline().rstrip()

def main():
    s = deque(input())
    q = int(input())
    reverse = False
    
    for _ in range(q):
        query = list(input().split())
        if query[0] == '1':
            reverse ^= True
        else:
            if reverse:
                if query[1] == '1':
                    s.append(query[2])
                else:
                    s.appendleft(query[2])
            else:
                if query[1] == '1':
                    s.appendleft(query[2])
                else:
                    s.append(query[2])
                    
    s = ''.join(s)
    if reverse:
        s = s[::-1]
    print(s)
        
if __name__ == '__main__':
    main()
