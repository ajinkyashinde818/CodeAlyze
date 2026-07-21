def main():
    n, k = map(int, input().split())
    a = [int(v) - 1 for v in input().split()]
    path_to_idx = {}
    path = []
    current_node = 0
    while True:
        path.append(current_node)
        path_to_idx[current_node] = len(path_to_idx)
        if path_to_idx.get(a[current_node]) is not None:
            cyclic = path_to_idx[a[current_node]]
            break
        current_node = a[current_node]

    if k < len(path):
        print(path[k]+1)
    else:
        k -= cyclic
        k %= (len(path) - cyclic)
        print(path[cyclic+k]+1)


if __name__ == '__main__':
    main()
