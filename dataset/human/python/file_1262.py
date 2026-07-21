N = int(input())
A = [int(s) for s in input().split()]

def main():
    sum_n = sum(A)
    mid = sum_n / 2
    a = 0
    abs_list = []
    for i in range(N - 1):
        a += A[i]
        abs_list.append((abs(mid - a), i))    
    abs_list.sort()
    idx = abs_list[0][1]

    left = sum(A[:idx + 1])
    right = sum(A[idx + 1:])
    print(abs(left - right))

if __name__ == '__main__':
    main()
