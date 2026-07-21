from sys import stdin
import math

def factorization(n):
    arr = []
    temp = n
    for i in range(2, int(-(-n**0.5//1))+1):
        if temp%i==0:
            cnt=0
            while temp%i==0:
                cnt+=1
                temp //= i
            arr.append([i, cnt])
    if temp!=1:
        arr.append([temp, 1])
    if arr==[]:
        arr.append([n, 1])

    return arr


def main():
    _in = [_.rstrip() for _ in stdin.readlines()]
    N = int(_in[0])  # type:int
    # vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
    N_fac = factorization(N)
    cnt = 0
    if N == 1:
        pass
    else:
        for fac,power in N_fac:
            for i in range(power+10):
                if i*(i+1)/2 > power:
                    i -= 1
                    cnt += i
                    break
    # ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
    print(cnt)


if __name__ == "__main__":
    main()
