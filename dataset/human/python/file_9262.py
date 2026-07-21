import sys

S = input()

S = S[::-1]

chars = ['dreamer', 'eraser', 'dream', 'erase']
chars = [char[::-1] for char in chars]

while 1:
    end_flag = 1
    for char in chars:
        if ( S.find(char) == 0):
            S = S[len(char):]
            end_flag = 0

            if S == '':
                print('YES')
                sys.exit()
    if end_flag ==1:
            print('NO')
            sys.exit()
