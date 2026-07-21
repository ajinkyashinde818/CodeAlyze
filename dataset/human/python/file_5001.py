import sys

for s in sys.stdin:
    row = [1,2,1,2,1,4,1,4]
    d = map(int,s.split())
    mini = 10000000
    n = len(row)
    m_row = [4]*n
    for i in xrange(n):
        su = [d[j]-row[(i+j)%n] if d[j] > row[(i+j)%n] else 0 for j in xrange(n)  ]
        su = sum(su)
        if mini == su:
            m_row = min(m_row,[ row[(i+j)%n] for j in xrange(n) ])
        elif mini > su:
            mini = su
            m_row =[ row[(i+j)%n] for j in xrange(n) ]
    for m in m_row:
        print m,
    print
