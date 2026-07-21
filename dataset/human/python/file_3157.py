import math
n = int( input() )

def prime_factorize( n ):
    a = {}
    while n % 2 == 0:
        try:
            a[ 2 ] += 1
        except KeyError:
            a[ 2 ] = 1
        n //= 2
    f = 3
    while f * f <= n:
        if n % f == 0:
            try:
                a[ f ] += 1
            except KeyError:
                a[ f ] = 1
            n //= f
        else:
            f += 2
    if n != 1:
        try:
            a[ n ] += 1
        except KeyError:
            a[ n ] = 1
    return a

a = prime_factorize( n )
ans = 0
for p in a.keys():
    ans += int( ( -1 + math.sqrt( 1 + 8 * a[ p ] ) ) / 2 )

print( ans )
