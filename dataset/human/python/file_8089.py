import sys
input = sys.stdin.readline

def main():
    K,S = [int(x) for x in input().split()]

    count = 0

    for x in range(K+1):
        for y in range(K+1):
            z = S - (x + y)
            if z >= 0 and z <= K:
                count += 1

    print(count)

if __name__ == '__main__':
    main()
