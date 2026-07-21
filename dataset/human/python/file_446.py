def main():
    _ = input()
    A = list(map(int, input().split()))
    A_list = []
    count = 0

    for a in A:
        if a < 0:
            count += 1
            A_list.append(a * -1)
        else:
            A_list.append(a)
    if count % 2 == 0:
        print(sum(A_list))
    else:
        print(sum(A_list)-min(A_list) * 2)


if __name__ == "__main__":
    main()
