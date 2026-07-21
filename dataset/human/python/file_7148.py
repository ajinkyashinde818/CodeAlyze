def main():
    from sys import stdin
    from collections import deque
    S = input()
    Q = int(input())
    reverse = 0
    head = []
    tail = []
    head_deque = deque(head)
    tail_deque = deque(tail)
    
    for _ in [0] * Q:
        readline = stdin.readline
        s = readline().split()
        if int(s[0]) == 1:
            if reverse == 1:
                reverse = 0
            else:
                reverse = 1
        else:
            if int(s[1]) == 1:
                if reverse == 1:
                    tail.append(s[2])
                else:
                    head_deque.appendleft(s[2])
            else:
                if reverse == 1:
                    head_deque.appendleft(s[2])
                else:
                    tail.append(s[2])
    head = list(head_deque)
    head = ''.join(head)
    tail = ''.join(tail)
    if reverse == 1:
        print(tail[::-1]+S[::-1]+head[::-1])
    else:
        print(head+S+tail)
        
main()
