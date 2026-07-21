def main():
    D, G = map(int, input().split())
    P = [0]*D
    C = [0]*D
    for i in range(D):
        P[i], C[i] = map(int, input().split())
    S = [0]*D
    ans = sum(P)
    for i in range(D):
        S[i] = (i + 1) * 100 * P[i] + C[i]
    # print(D, G, P, C, S)
    for i in range(2**D):
        score = 0
        count = 0
        num_solved = 0
        solved = [0]*D

        while i > 0:
            if i % 2 == 1:
                score += S[count]
                num_solved += P[count]
                solved[count] = 1
            i //= 2
            count += 1
        if score >= G:
            ans = min(ans, num_solved)
        else:
            d = G - score
            # print('d={}'.format(d))
            for j in range(D):
                index = D - j - 1
                # print('index={}, solved={}'.format(index, solved))
                if solved[index] == 1:
                    continue
                required = (d + (index + 1) * 100 - 1) // ((index + 1) * 100)
                # print('required={}'.format(required))
                if required < P[index]:
                    num_solved += required
                    ans = min(ans, num_solved)
                break
    print(ans)

if __name__ == '__main__':
    main()
