def main():
    input = sys.stdin.readline
    try:
        n = int(input())
        a = list(map(int, input().split()))
        if len([i for i in a if i < 0]) % 2 == 0:
            print(sum((abs(i) for i in a)))
        else:
            arr = [abs(i) for i in a]
            print(sum(arr) - min(arr) * 2)
        
    finally:
        input = None

import sys; sys.setrecursionlimit(50000)
if __name__ == "__main__":
    main()
