import sys

def main():
    K, N = list(map(int, sys.stdin.readline().rstrip().split()))
    data = list(map(int, sys.stdin.readline().rstrip().split()))

    def iterate_difference(index):
        try:
            yield data[index + 1] - data[index]
        except IndexError:
            raise StopIteration

    difference = set()
    for x in range(N):
        try:
            difference.add(next(iterate_difference(x)))
        except StopIteration:
            continue
    else:
        difference.add(K - data[N - 1] + data[0])

    print(K - max(difference))

if __name__ == '__main__':
    main()
