def main():
    n, k = map(int, input().split())
    a =  list(map(int, input().split()))

    path = [1]
    for _ in range(n-1):
        path.append(a[path[-1]-1])

    if k > n:
        start = path.index(path[-1])
        index = (k - start) % (len(path) - start - 1) + start
        t = path[index]
    else:
        t = path[k]
    return print(t)

if __name__ == '__main__':
    main()
