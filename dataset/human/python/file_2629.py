def main():
    d, g = [int(e) for e in input().split()]
    P, C = zip(*[[int(e) for e in input().split()] for i in range(d)])

    A = []
    for b in [format(i, '0{}b'.format(d)) for i in range(2**d)]:
        count = 0
        score = 0
        for ci, c in enumerate(b):
            if c == '1':
                count += P[-ci - 1]
                score += P[-ci - 1]*(d - ci)*100 + C[-ci - 1]

        if score >= g:
            A.append(count)
            continue

        for i in range(P[-b.index('0') - 1]):
            count += 1
            score += 100*(d - b.index('0'))
            if score >= g:
                A.append(count)
                break

    print(min(A))

if __name__ == "__main__":
    main()
