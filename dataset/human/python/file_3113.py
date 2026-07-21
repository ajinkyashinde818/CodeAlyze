import math


inf = 10**12

def main():
    N = int(input())
    print(solve(N))

def get_count(k):
    for i in range(inf):
        k -= i
        if k < 0:
            return i-1

def solve(N):
    result = 0
    
    current_count = 0
    while N % 2 == 0:
        current_count += 1
        N //= 2
    result += get_count(current_count)

        
    d = 3
    sqrt = math.sqrt(N)
    while N > 1:
        current_count = 0
        # print(f'd: {d}')
        # print(f'N: {N}')
        if d > sqrt:
            # print("hello")
            if N > 1:
                result += 1
                N = 1
        while N % d == 0:
            current_count += 1
            N //= d
            # print(N)
        if current_count:
            result += get_count(current_count)
            sqrt = math.sqrt(N)
        # print(f'N: {N}')
        d += 2

    return result


if __name__ == '__main__':
    main()
