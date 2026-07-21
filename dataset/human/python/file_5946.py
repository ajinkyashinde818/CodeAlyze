def get_list(str):
    str_list = str.split(" ")
    result_list = []
    for str in str_list:
        result_list.append(int(str))
    return result_list

n = input()
a_str = input()
b_str = input()
c_str = input()
a_list = get_list(a_str)
b_list = get_list(b_str)
c_list = get_list(c_str)

pre_index = -100
result = 0
for i in range(len(a_list)):
    index = a_list[i] - 1
    result += b_list[index]
    if pre_index+1 == index:
        result += c_list[pre_index]
    pre_index = index

print(result)
