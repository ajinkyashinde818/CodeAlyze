def main():
    n, k = tuple([int(e) for e in input().split()])
    arr = [0] + [int(e) for e in input().split()]

    seen = set()
    actual = 1
    seen.add(1)
    pos = [1]
    mp = {1:1}
    while k > 0:
        actual = arr[actual]
        k -= 1
        if actual in seen:
            break
        seen.add(actual)
        pos.append(actual)
        mp[actual] = len(pos)

    c = 1 + len(pos) - mp[actual]
    k = k % c
    print(pos[mp[actual] + k - 1])

if __name__ == '__main__':
    main()
