s = input()

dic = ['dreameraser', 'dreamerase', 'dreamer', 'dream', 'eraser', 'erase']

def check():
    i = 0
    while i < len(s):
        found = False
        for k in dic:
            if s[i:i+len(k)] == k:
                found = True
                break
        if not found:
            return False
        i += len(k)
    return True


print('YES' if check() else 'NO')
