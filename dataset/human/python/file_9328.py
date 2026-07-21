import sys
def input(): return sys.stdin.readline().rstrip()

def main():
    N, K = map(int, input().split())
    A = tuple(map(int, input().split()))

    data = []
    visited = set()
    data.append(1)
    visited.add(1)
    ai = 1
    while True:
        ai = A[ai - 1]
        if ai in visited:
            break
        data.append(ai)
        visited.add(ai)
    d_index = data.index(ai)
    if K > d_index:
        rep_data = data[d_index:]
        rep_len = len(rep_data)
        K -= d_index
        print(rep_data[K - K // rep_len * rep_len])
    else:
        print(data[K])

if __name__ == '__main__':
    main()
