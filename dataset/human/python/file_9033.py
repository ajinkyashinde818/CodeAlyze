import sys #追加
sys.setrecursionlimit(500*500)

s = input()
check_flag = True
def check_and_cut(string):
    tmp = '123'
    flag = True
    if len(string) <= 4:
        pass
    else:
        if len(string) >4:
            if string[-5:] == 'dream':
                tmp = string[:-5]
                flag = False
            elif string[-5:] == 'erase':
                tmp = string[:-5]
                flag = False
        if len(string) >5 and flag:
            if string[-6:] == 'eraser':
                tmp = string[:-6]
                flag = False
        if len(string) >6 and flag:
            if string[-7:] == 'dreamer':
                tmp = string[:-7]
                flag = False
    #print(string,len(string),string[-6:],tmp,string[-6:] == 'eraser')
    return tmp
while check_flag:
    t = check_and_cut(s)
    if t == '123':
        print('NO')
        exit()
    if len(t) == 0:
        print('YES')
        exit()
    s = t
