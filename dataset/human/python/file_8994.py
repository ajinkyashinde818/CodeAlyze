from sys import exit

s = input()
l = ['dream', 'dreamer', 'erase', 'eraser']

pos = len(s) - 1
while pos >= 0:
    flag = False

    for string in l:
        length = len(string)
        if pos >= length - 1 and s[pos-length+1:pos+1] == string:
            pos -= length
            flag = True

    if not flag:
        print('NO')
        exit()

print('YES')
