import numpy

N = int( input() )
A = list( map( int ,input().split()) )
cnt = sum( lop < 0 for lop in A)

nA = numpy.array(A)
nA = numpy.abs(nA)

lA = nA.tolist()
if min(lA) == 0 or cnt % 2 == 0:
    print(sum(lA))
else :
    print(sum(lA)-min(lA)*2)
