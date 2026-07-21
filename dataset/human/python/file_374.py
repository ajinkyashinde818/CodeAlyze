def main():
    N = int(input())

    neg_num = 0
    sum_abs = 0
    min_abs = 100000
    for i in input().split():
        number = int(i)
        if number < 0:
            neg_num +=1

        sum_abs += abs(number)
        min_abs = min(min_abs, abs(number))

    if neg_num % 2 == 0:
        print(sum_abs)
    else:
        print(sum_abs - min_abs*2)
    
if __name__ == "__main__":
    main()
