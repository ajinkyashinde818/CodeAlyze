def main():
    N = int(input())
    A = list(map(int, input().split(" ")))
    B = list(map(int, input().split(" ")))
    C = list(map(int, input().split(" ")))
    result = 0
    meal_num = -5
    for a in A:
        if a == meal_num + 1:
            result += C[a - 2]
        result += B[a - 1]
        meal_num = a
    print(result)


if __name__ == '__main__':
    main()
