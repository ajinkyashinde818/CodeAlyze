S = input()
str_list = ['dream', 'erase', 'dreamer', 'eraser']
start = 0
success_flag = False
continue_flag = False


def reverse_str(var: str):
    return ''.join(list(reversed(var)))


reverse_S = reverse_str(S)
while True:
    for str_name in str_list:
        if reverse_S[start:start + len(str_name)] == reverse_str(str_name):
            if len(S) == start + len(str_name):
                success_flag = True
                break
            start += len(str_name)
            continue_flag = True
    if success_flag:
        print('YES')
        break
    if not continue_flag:
        print('NO')
        break
    else:
        continue_flag = False
