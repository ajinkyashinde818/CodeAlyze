str_list = ['dream', 'dreamer','erase','eraser']
def reverse_str(str_):
    return str_[::-1]

s = str(input())
s = s[::-1]
find_list = list(map(reverse_str, str_list))
index = 0

while index < len(s):
    loop_flag = False
    for i in range(len(find_list)):
        str_value = find_list[i]
        if str(s[index:index+len(str_value)]) == str_value:

            loop_flag = True
            index += len(str_value)
    if not loop_flag:
        break
if index >= len(s):
    print('YES')
else:
    print('NO')
