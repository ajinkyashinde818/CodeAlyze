def resolve():
    citys_num, k = map(int, input().split())
    cities = list(map(int, input().split()))

    visited = set()
    route = []
    isAgain = False
    currectCity = 1
    while not isAgain:
        if currectCity in visited:
            route.append(currectCity)

            isAgain = True
        else:
            visited.add(currectCity)
            route.append(currectCity)

            currectCity = cities[currectCity - 1]
    if len(route) > k:
        print(route[k])
        return
    loopstart = route.index(route[-1])
    loop = route[loopstart:-1]

    k = k - loopstart
    k = k % len(loop)

    print(loop[k])
resolve()
