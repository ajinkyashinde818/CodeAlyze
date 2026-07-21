def main():
    length, sum_num, subarray_sum = map(int, input().split())
    answer = [subarray_sum] * sum_num
    if subarray_sum == 10 ** 9:
        answer += [1] * (length - sum_num)
    else:
        answer += [subarray_sum + 1] * (length - sum_num)
    print(" ".join(map(str, answer)))


if __name__ == '__main__':
    main()
