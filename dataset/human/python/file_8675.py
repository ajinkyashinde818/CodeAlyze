def main():
    x = list(map(int, input().split()))
    k = x[0]
    n = x[1]
    a = list(map(int, input().split()))

    max_distance = 0

    for i in range(n):
        distance = a[i]-a[i-1]
        if distance < 0:
            distance = k+distance
        if max_distance < distance:
            max_distance = distance

    answer = k - max_distance
    print(answer)


if __name__ == "__main__":
    main()
