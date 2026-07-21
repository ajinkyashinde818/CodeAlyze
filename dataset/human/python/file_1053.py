def inWall(x,y,x1,y1,r):
	return True if ((x-x1)**2+(y-y1)**2)**0.5 <= r + 1e-9 else False

def isHide(x,y,r,a,b,c):
	D = abs(a*x+b*y+c)/(a**2+b**2)**0.5
	return True if D <= r + 1e-9 else False

def isBetween(x,y,tx,ty,sx,sy):
	a,b,c = (x-tx)**2+(y-ty)**2,(x-sx)**2+(y-sy)**2,(sx-tx)**2+(sy-ty)**2
	if c > b and c > a: return True
	a,b,c = sorted([a,b,c])
	return True if c-a-b <= 0 else False

while 1:
	n = input()
	if n == 0: break
	wall = [map(int,raw_input().split()) for i in range(n)]
	for i in range(input()):
		tx,ty,sx,sy = map(int,raw_input().split())
		a,b,c = -(ty-sy),tx-sx,sx*ty-sy*tx
		for x,y,r in wall:
			t_in,s_in = inWall(x,y,tx,ty,r),inWall(x,y,sx,sy,r)
			if t_in != s_in or (not t_in and isHide(x,y,r,a,b,c) and isBetween(x,y,tx,ty,sx,sy)):
				print "Safe"
				break
		else:
			print "Danger"
