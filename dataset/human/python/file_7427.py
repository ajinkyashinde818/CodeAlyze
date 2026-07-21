from collections import deque
def main():
    S = input()
    d = deque(S)
    Q = int(input())
    direction = True
    for _ in range(Q):
        x = input()
        if x[0] == '1':
            direction = not direction
        else:
            a,f,c = x.split(' ')
            if (int(f) == 1 and direction) or (int(f) == 2 and not direction):
                d.appendleft(c)
            else:
                d.append(c)
    if direction:
        print(''.join(d))
    else:
        print(''.join(reversed(d)))
                
main()
