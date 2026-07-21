import numpy as np
def calc(number):
    result = np.log10(number) - np.log10(number) % 1
    return(result)

input_num = int(input())

if(input_num % 2 == 1):
    print(0)
else:
    result_1 = 0
    num = 5
    while(input_num - num >= 0):
        result_1 += (input_num - num) // (num * 2) + 1
        num = num * 5
    num = 5
    result = 0
    while(input_num - num >= 0):
        result += input_num // num
        num = num * 5
    print(result - result_1)
