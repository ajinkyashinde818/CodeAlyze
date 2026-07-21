from collections import deque

def main():
    S = input()
    Q = int(input())
    
    SS = deque()
    for s in S:
        SS.append(s)
    
    cnt = 0
    for i in range(Q):
        query = input().split()
        if(query[0] == "1"):
            cnt += 1
        else:
            if(query[1] == "1"):
                if(cnt%2 == 0):
                    SS.appendleft(query[2])
                else:
                    SS.append(query[2])
            else:
                if(cnt%2 == 0):
                    SS.append(query[2])
                else:
                    SS.appendleft(query[2])
    
    ans = list(SS)
    if(cnt%2 == 0):
        print(''.join(ans))
    else:
        print(''.join(ans[::-1]))
main()
