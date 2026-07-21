n = int(input())

def prime(n_):
    if n_ == 1:
        return []
    num = int(pow(n_, 0.5)) + 1
    pr = [True] * (num + 1)
    pr[0], pr[1] = False, False
    for i in range(2, int(pow(num, 0.5) + 1)):
        if not pr[i]:
            continue
        for j in range(i * 2, num + 1, i):
            pr[j] = False
    return [i for i in range(num + 1) if pr[i]]

def factorization(num):
    pr = prime(num)
    data = []
    temp = num
    for i in pr:
        if temp % i == 0:
            count = 0
            while temp % i == 0:
                count += 1
                temp //= i
            data.append([i, count])
    if temp != 1:
        data.append([temp, 1])
    if data == []:
        data.append([n, 1])
    return data

def main():
    ans = 0
    pr = factorization(n)
    for i, j in pr:
        count = 1
        sub = j
        while sub >= count:
            ans += 1
            sub -= count
            count += 1
    if n == 1:
        ans = 0
    print(ans)


if __name__ == "__main__":
    main()
