from collections import deque
def solve(S, Q):
    S = deque(S)
    flg = 0
    for _ in range(Q):
        que = input().split()
        if len(que) == 1:
            flg += 1
        else:
            if flg % 2 == 0:
                if que[1] == '1':
                    S.extendleft(que[2])
                elif que[1] == '2':
                    S.extend(que[2])
            elif flg % 2 == 1:
                if que[1] == '1':                 
                    S.extend(que[2])
                elif que[1] == '2':                
                    S.extendleft(que[2])
    S = ''.join(S)
    if flg % 2 == 1:
        S = S[::-1]
    print(S)

def main():
    S = input()
    Q = int(input())
    solve(S, Q)

if __name__ == "__main__":
    main()
