import sys
read = sys.stdin.read
readline = sys.stdin.readline
readlines = sys.stdin.readlines

def main():
    N,R = map(int, readline().split())

    if N >= 10:
        print(R)
    
    else:
        print(R + 100 * (10 - N))


if __name__ == "__main__":
    main()
