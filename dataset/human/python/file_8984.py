import re

def main():
    s = list(input())
    sr = ''.join(list(reversed(s)))
    t = ['dream', 'dreamer', 'erase', 'eraser']
    tr = list()
    for i in t:
        tr.append(''.join(list(reversed(i))))
    while sr:
        flag = False
        for i in tr:
            if sr.startswith(i):
                sr = sr.replace(i ,'', 1)
                flag = True
        if not flag:
            print('NO')
            break
        if sr == '':
            print('YES')
            break
if __name__ == '__main__':
    main()
