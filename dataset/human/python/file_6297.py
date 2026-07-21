import collections

def solution():
    n = [int(x) for x in input().strip()]
    res = 0
    carry = 0
    for i in range(len(n)-1, -1, -1):
        cur = n[i] + carry
        if cur == 10:
            carry = 1
        elif 6 <= cur <= 9:
            res += 10-cur
            carry = 1
        elif cur == 5:
            if i > 0 and n[i-1] >= 5:
                carry = 1
                res += 5
            else:
                carry = 0
                res += 5
        else:
            carry = 0
            res += cur
    print(res+carry)

def main():    
    # T = int(input().strip())
    for _ in range(1):
        solution()
    

main()
