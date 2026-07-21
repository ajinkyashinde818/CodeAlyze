import sys
input = sys.stdin.readline


def main(n, a, b, c):
    total = sum(b)

    for i in range(n-1):
        if a[i]+1 == a[i+1]:
            total += c[a[i]-1]

    return total


if __name__ == "__main__":
    n = int(input())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    c = list(map(int, input().split()))
    print(main(n, a, b, c))
