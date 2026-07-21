import sys 
sys.setrecursionlimit(10**6)
s = input()
def dfs(s):
    while True:
        f = True
        for i in ['dream', 'dreamer', 'erase', 'eraser']:
            if s[-len(i):]==i:
                s = s[:-len(i)]
                if s=='':
                    return True
                f = False
        if f: return False
    
if dfs(s):
    print('YES')
else:
    print('NO')
