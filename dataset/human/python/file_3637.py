import sys
input = sys.stdin.readline


def factorization(n):
    arr = []
    temp = n
    for i in range(2, int(-(-n**0.5//1))+1):
        if temp % i == 0:
            cnt = 0
            while temp % i == 0:
                cnt += 1
                temp //= i
            arr.append([i, cnt])

    if temp != 1:
        arr.append([temp, 1])

    if arr == []:
        arr.append([n, 1])

    return arr


def main():
    N = int(input())
    answer = 0
    ans_list = factorization(N)
    sum_list = [1, 3, 6, 10, 15, 21, 28, 36, 45]
    if N == 1:
        print(0)
        exit()
    for i in ans_list:
        for j in range(len(sum_list)):
            if i[1] < sum_list[j]:
                answer += j
                break
    print(answer)


if __name__ == '__main__':
    main()
