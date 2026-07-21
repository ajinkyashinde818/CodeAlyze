from bisect import bisect_right
import math
import numpy as np

def primes(n):
    yield 2
    import numpy as np
    nn = int(math.sqrt(n)+1)
    a = np.arange(1, nn+1)
    b = a * a.reshape((nn, 1))
    b = b[1:,1:]
    c = b.reshape((nn-1)*(nn-1), )
    notprimes = set(c)
    for p in range(3, n+1, 2):
        if p not in notprimes:
            yield p

def bunkai(N):
    result = dict()
    for p in primes(int(math.sqrt(N))+1):
        if N == 1:
            return result
        count = 0
        while N % p == 0:
            count += 1
            N /= p
        if count != 0:
            result[p] = count
    
    if N != 1:
        result[N] = 1
    
    return result


def main():
    N = int(input())

    s = np.arange(math.log(N,2)+1, dtype=np.int32)
    S = (s * (s + 1) ) // 2
    p_list = bunkai(N)

    ans = 0
    for c in p_list.values():
        i = bisect_right(S, c) - 1
        #print(f"c={c} i={i}")
        ans += i
    
    print(ans)


if __name__ == '__main__':
    main()
