import sys
read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines

from collections import deque 
def main():
    s = deque(readline().rstrip().decode())
    q = int(readline())
    dir = 1
    for _ in range(q):
        txt = readline().rstrip().decode()
        if txt[0] == '1':
            dir += 1
            dir%=2
        elif txt[0] == '2':
            f = txt[2]
            c = txt[4]
            if ((dir==1) and (f=='1')) or ((dir==0) and (f=='2')):
                s.appendleft(c)
            else:
                s.append(c)
    if dir==0:
        print(''.join(reversed(s)))
    else:
        print(''.join(s))
if __name__ == '__main__':
    main()
