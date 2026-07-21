if __name__ == '__main__':
    s = input().rstrip().split(' ')
    N, K = int(s[0]), int(s[1])
    s = input().rstrip().split(' ')
    A = [int(elem) for elem in s]

    route_until_loop = []
    route_dict = {}
    loop = []
    pos = 0
    count = 0
    while True:
        route_until_loop.append(pos)
        route_dict[pos] = count
        count += 1
        # go next
        pos = A[pos]-1
        if pos in route_dict.keys():
            break;

    loop = route_until_loop[route_dict[pos]:]
    route_until_loop = route_until_loop[:route_dict[pos]]

    #print(route_until_loop)
    #print(loop)

    if K < len(route_until_loop):
        print(route_until_loop[K]+1)
    else:
        K -= len(route_until_loop)
        print(loop[K%len(loop)]+1)
