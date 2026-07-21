if __name__ == "__main__":
    s = input()
    t = input()

    s_num = list()
    t_num = list()

    for ss in s:
        s_num.append(ord(ss))
    for tt in t:
        t_num.append(ord(tt))

    s_num.sort()
    t_num.sort(reverse=True)

    s_str = ''
    t_str = ''
    for ss in s_num:
        s_str += chr(ss)
    for tt in t_num:
        t_str += chr(tt)

    if s_str == t_str:
        print('No')
    elif min([s_str, t_str]) == s_str:
        print('Yes')
    else:
        print('No')
