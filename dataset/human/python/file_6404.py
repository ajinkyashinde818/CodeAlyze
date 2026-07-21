def count_five(n):
    res = 0
    i = 1
    while n//pow(5,i) - n//pow(10,i)> 0:
        res += n//pow(5,i) - n//(2*pow(5,i))
        i += 1
    return res

def main(N):
    if N%2:
        return 0
    M = list(str(N))
    L = len(M)
    temp = 0
    temp2 = 0
    res = 0
    for i, n in enumerate(M[:-1], start=1):
        temp *= 10
        temp += int(n)
        res += (temp - temp2)*(L-i)
        res += count_five(temp)
        temp2 = temp
    return res

N = int(input())
print(main(N))
