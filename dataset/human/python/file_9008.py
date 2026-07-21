def we_can(s):
    ptr = 0
    while True:
        if len(s) == abs(ptr):
            return True
        else:
            if ptr == 0:
                if s[ptr-5:] == 'dream' or s[ptr-5:] == 'erase':
                    ptr -= 5
                    continue
                elif s[ptr-6:] == 'eraser':
                    ptr -= 6
                    continue
                elif s[ptr-7:] == 'dreamer':
                    ptr -= 7
                    continue
            if s[ptr-5:ptr] == 'dream' or s[ptr-5:ptr] == 'erase':
                ptr -= 5
                continue
            elif s[ptr-6:ptr] == 'eraser':
                ptr -= 6
                continue
            elif s[ptr-7:ptr] == 'dreamer':
                ptr -= 7
                continue
            return False


s = input()
if we_can(s):
    print('YES')
else:
    print('NO')
