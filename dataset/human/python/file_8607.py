import numpy

k, n = map(int,input().split())
a = list(map(int,input().split()))

distance = numpy.empty(n,dtype=numpy.int)
distance[0] = a[0]

for i in range(1,n):
    distance[i] =  a[i] - a[i-1]

distance[0] = k - a[n-1] + a[0]

print(k - max(distance))
