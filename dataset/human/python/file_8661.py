def main():
    k, n = map(int, input().split())
    houses = list(map(int, input().split()))

    distances = []
    for i in range(n):
        if i != n-1:
            distances.append(houses[i+1] - houses[i])
        else:
            distances.append(k-houses[-1] + houses[0])

    print(sum(distances) - max(distances))


if __name__ == '__main__':
    main()
