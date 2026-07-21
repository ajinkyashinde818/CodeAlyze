import numpy

n = int(input())
a = []
a = numpy.array([ int(e) for e in input().split(" ")])



if sum(a < 0)%2 == 0:
    print(numpy.abs(a).sum())
else:
    tmp = numpy.abs(a)
    print( tmp.sum() -2*min(tmp))
