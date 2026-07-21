def read_input():
    n, m = map(int, input().split())

    ships = []
    for i in range(m):
        a, b = map(int, input().split())
        ships.append((a, b))

    return n, m, ships


def submit():
    n, m, ships = read_input()

    links = {i: [] for i in range(1, n+1)}

    for ship in ships:
        links[ship[0]].append(ship[1])
        links[ship[1]].append(ship[0])

    set1 = set(links[1])
    set2 = set(links[n])

    if set1.intersection(set2):
        print('POSSIBLE')
    else:
        print('IMPOSSIBLE')



if __name__ == '__main__':
    submit()
