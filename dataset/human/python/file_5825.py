n = int(input())
a_list = list(map(int, input().split()))
b_list = list(map(int, input().split()))
c_list = list(map(int, input().split()))

def main(a_list, b_list, c_list):
    before_element = 999
    result = 0
    for element in a_list:
        result += b_list[element-1]
        if element == before_element + 1:
            result += c_list[before_element-1]
        before_element = element
    return result

print(main(a_list, b_list, c_list))
