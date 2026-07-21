import heapqueue, streams, sequtils, strutils, algorithm, math, future, sets, tables, hashes
proc `ceilDiv`*[T](x, y: T): T = x div y + ord(x mod y != 0)
proc `//=`*(x: var SomeInteger; y: SomeInteger) = x = x div y
proc `%=`*(x: var SomeInteger; y: SomeInteger) = x = x mod y
proc prime_factorization(N:int):Table[int,int] =
    var
        pf = initTable[int, int]()
        N = N
    for i in 2..sqrt(N.float).int:
        while N mod i == 0:
            if not pf.hasKey(i):
                pf[i] = 1
            else:
                pf[i] += 1
            N = N div i
    if N > sqrt(N.float).int:
        pf[N] = 1
    return pf

var
    N = stdin.readLine.parseInt
    ans = 0
    idx = 0
    pf = prime_factorization(N)
    cnt = 0
for k in pf.keys:
    idx = 1
    cnt = 0
    if N mod k == 0:
        while pf[k] >= cnt + idx:
            cnt += idx
            N //= k^idx
            idx += 1
            ans += 1
echo ans
