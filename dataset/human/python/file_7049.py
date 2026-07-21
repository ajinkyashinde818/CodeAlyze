import sys
read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines

def main():
    from collections import deque
    S = deque(readline().strip().decode())
    Q = int(readline())
    Query = readlines()
    rev_flg = False
    for q in Query:
        if q[0] == ord('1'):
            rev_flg = not rev_flg
        else:
            _, f, c = q.decode().split()
            if int(f)-(rev_flg) == 1:
                S.appendleft(c)
            else:
                S.append(c)
    S = ''.join(S)
    if rev_flg is True:
        S = S[::-1]
    print(S)

    return
if __name__ == '__main__':
    main()
