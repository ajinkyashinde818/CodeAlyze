def solution(a):
    A = a[0]
    B = sum(a) - a[0]
    Min = abs(A - B)
    for i in xrange(1, len(a)-1):
        A += a[i]
        B -= a[i]
        if Min > abs(A- B):
            Min = abs(A - B)
    print Min
import math
N = int(raw_input())
a = map( int, raw_input().split())
solution(a)
