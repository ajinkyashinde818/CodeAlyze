s = input().rstrip()
d = ['dream', 'dreamer']
e = ['erase', 'eraser']
ch = d + e

st = [s]

def search_(s, st, ch):
    if len(s) == 0:
        return
    if len(s) < len(ch):
        return
    else:
        if s[:len(ch)] == ch:
            st.append(s[len(ch):])

def search(s):
    if len(s) == 0:
        return True
    if s[0] == 'd' or s[0] == 'e':
        for ci in ch:
            if search_(s, ci):
                return True
    return False

while st:
    s = st.pop(0)
    if len(s) == 0:
        print('YES')
        exit()
    if s[0] == 'd' or s[0] == 'e':
        for ci in ch:
            search_(s, st, ci)
print('NO')
