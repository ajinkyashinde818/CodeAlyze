def input_int():
    return map(int, input().split())

def one_int():
    return int(input())

def one_str():
    return input()

def many_int():
    return list(map(int, input().split()))

N,R = input_int()

ans = 0
if N>=10:
    print(R)
else:
    print(R + (100*(10-N)))
