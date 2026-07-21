import sys
sys.setrecursionlimit(100000)

def str_read(s):
    while True:
        if len(s) == 0:
            return True
        else:
            if s[0:5] in ['maerd', 'esare']:
                s = s[5:]
            elif s[0:6] in ['resare']:
                s = s[6:]
            elif s[0:7] in ['remaerd']:
                s = s[7:]
            else:
                return False


si = input()
if str_read(si[::-1]):
    print('YES')
else:
    print('NO')
