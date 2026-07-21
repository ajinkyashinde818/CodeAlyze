def main():
    N, M = map(int, input().split())
    query = [ [int(a) for a in input().split()] for i in range(M)]
    query.sort(key=lambda x : x[0])
    mid = set()

    possible = False
    for q in query:
        a = q[0]
        b = q[1]

        if a == 1:
            mid.add(b)

        if b == N:
            if a in mid:
                possible = True
                break
    if possible:
        print("POSSIBLE")
    else:
        print("IMPOSSIBLE")
if __name__ == "__main__":
    main()
