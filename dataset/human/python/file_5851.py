import sys
input = lambda: sys.stdin.readline().rstrip()
input_nums = lambda: list(map(int, input().split()))

def main():
    N = int(input())
    A = input_nums()
    B = input_nums()
    C = input_nums()
    total = 0
    before = -2
    for a in A:
        total += B[a-1]
        if before + 1 == a - 1:
            total += C[a-2]
        before = (a - 1)
    print(total)

if __name__ == '__main__':
    main()
