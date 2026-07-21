import sys, os

f = lambda:list(map(int,input().split()))
if 'local' in os.environ :
    sys.stdin = open('./input.txt', 'r')

a = ['dream', 'dreamer', 'erase', 'eraser']

def solve():
    s = input()

    s = s[::-1]

    for i in range(4):
        a[i] = a[i][::-1]
    
    t = ''

    while t!=s:
        ok = False
        for i in a:
            temp = t+i
            if len(temp)<= len(s) and temp == s[:len(temp)]:
                t = temp
                ok = True
                continue
        if not ok:
            print('NO')
            return

        



    print('YES')



solve()
