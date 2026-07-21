def main():
    N = input()
    ans = 0
    carry = 0
    prev_5 = False
    for c in N[::-1]:
        if prev_5 and int(c) >= 5:
            carry = 1
        if int(c) + carry <= 4:
            ans += int(c) + carry
            carry = 0
            prev_5 = False
        elif int(c) + carry == 5:
            ans += 10 - (int(c) + carry)
            carry = 0
            prev_5 = True
        else:
            ans += 10 - (int(c) + carry)
            carry = 1
            prev_5 = False
    if carry == 1:
        ans += 1
    print(ans)


if __name__ == "__main__":
    main()
