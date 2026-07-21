import math
import decimal


def main():

    N = int(input())
    ans = 0
    A = int(math.ceil(N**0.5)+1)
    explist = []
    flag = False
    if N >= 3:
        for L in range(2, A):
            if N < L:
                break
            d = L
            cnt = 0
            while(True):
                if N % d == 0:
                    N /= d
                    cnt += 1
                    flag = True
                else:
                    break
            explist.append([d, cnt])
        for i in explist:
            c = i[1]
            for j in range(1, A):
                if c >= j:
                    ans += 1
                    c -= j
                else:
                    break
        if N >= A:
            ans += 1
        if flag:
            print(ans)
            return
        else:
            print(1)
            return
    elif N == 2:
        print(1)
        return
    else:
        print(0)
        return


if __name__ == '__main__':
    main()
