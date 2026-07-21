def main():
    s = input().strip()
    carry = 0
    result = 0
    for i in range(len(s) - 1, -1, -1):
        carry, x = divmod(ord(s[i]) - ord("0") + carry, 10)
        if x > 5 or (x == 5 and i > 0 and s[i - 1] >= "5"):
            carry += 1
            result += 10 - x
        else:
            result += x
    result += carry
    print(result)


main()
