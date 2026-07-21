def main(input_str):
    nums = list(map(int, input_str.split()))

    count = 0
    for num_1 in range(nums[0]+1):
        for num_2 in range(nums[0]+1):
            if 0 <= nums[1]-(num_1+num_2) <= nums[0]:
                count += 1

    return count


if __name__ == "__main__":
    input_str = input()
    print(main(input_str))
