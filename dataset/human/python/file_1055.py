from __future__ import division
from collections import namedtuple
import math
Vector=namedtuple('Vector','x y')

def size(H):
    return math.sqrt(pow(H.x,2)+pow(H.y,2))

def inner(A,B):
    return A.x*B.x+A.y*B.y

def collision(tx,ty,sx,sy,px,py,r):
    #if collision: return True
    #else: return False
    S=Vector(x=tx-sx,y=ty-sy)
    A=Vector(x=px-sx,y=py-sy)
    B=Vector(x=px-tx,y=py-ty)
    d=abs(S.x*A.y-A.x*S.y)/size(S)
#    print d,r,inner(A,S)*inner(B,S),size(A),size(B),px,py,r
    if d>r:
        return False
    elif r>size(A) and r>size(B):
        return False
    elif inner(A,S)*inner(B,S)<=0:
        return True
    elif r>size(A) or r>size(B):
        return True
    else:
        return False

while True:
    n=input()
    if n==0:break
    wall=[map(int,raw_input().split()) for i in range(n)]
    m=input()
    for i in range(m):
        tx,ty,sx,sy=map(int,raw_input().split())
        for wx,wy,r in wall:
            if collision(tx,ty,sx,sy,wx,wy,r):
                print 'Safe'
                break
        else:
            print 'Danger'
