import sys

direction = {'N' : 0, 'E' : 1, 'S' : 2, 'W' : 3}
step = [( -1, 0 ), ( 0, 1 ), ( 1, 0 ), ( 0, -1 )]
vv = []

while True:
    W, H = map( int, sys.stdin.readline().rstrip().split() )
    if W == 0 and H == 0: break
    m = [ list( sys.stdin.readline().strip() ) for i in xrange( H ) ]
    people = [ [ i, j, direction[ m[i][j] ] ] for i in xrange( H ) for j in range( W )
               if m[i][j] in "NESW" ]
    time = 0
    while any( people ):
        time += 1
        if time > 180:
            time = -1
            break
        sched = []
        for n in xrange( len( people ) ):
            if people[n] is None: continue
            x, y, d = people[n]
            for i in range(1, -3, -1):
                    dx, dy = step[(d + i) % 4]
                    if 0 <= x+dx < H and 0 <= y+dy < W and m[x+dx][y+dy] in "X.":
                        people[n][2] = (d + i) % 4
                        beat = True
                        for k in range( len( sched ) ):
                            xx, yy, dd = sched[k][1:]
                            if ( x+dx, y+dy ) == ( xx, yy ):
                                if dd < (d + i) % 4:
                                    sched[k] = ( n, x+dx, y+dy, (d + i) % 4 )
                                    beat = False
                                    break
                                else:
                                    beat = False
                                    break
                        if beat:
                            sched.append( ( n, x+dx, y+dy, (d + i) % 4 ) )
			break
        for ( k, x, y, d ) in sched:
            m[ people[k][0] ][ people[k][1] ] = '.'
            if m[x][y] == 'X':
                people[k] = None
            else:
                m[x][y] = 'H'
                people[k] = list([x, y, d])
    if time >= 0:
        vv.append(time)
    else:
        vv.append('NA')

for v in vv:
    print v
