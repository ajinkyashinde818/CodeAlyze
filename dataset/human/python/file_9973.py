import math

def resolve():
    A, B = map(int, input().split())

    answer = least_common_multiple(A, B)    
    print(answer)

def least_common_multiple(a, b):
    if b > a:
        a, b = b, a
    
    ab = a*b

    while (a%b) != 0:
        a, b = b, a%b

    return int(ab/b)

if __name__ == "__main__":
    resolve()
