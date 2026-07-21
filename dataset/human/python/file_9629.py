import sys

def main():
    n, k = map(int, sys.stdin.buffer.readline().split())
    a = [0] + list(map(int, sys.stdin.buffer.readline().split()))

    visited = [0]*(n+1)
    town = 1
    for i in range(1, k+1):
        town = a[town]
        if visited[town] == 0:
            visited[town] = i
        else:
            cyc = (k - visited[town])%(i - visited[town]) + visited[town]
            print(visited.index(cyc))
            exit()
    print(town)

if __name__ == "__main__":
    main()
