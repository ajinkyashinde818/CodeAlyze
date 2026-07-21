import sys
inp=sys.stdin.readline()
K,S=map(lambda x: int(x), inp.split(' '))
K,S

if S<=K:
    ret=(S+1)*(S+2)/2
elif S>=K*2:
    S=K*3-S
    ret=(S+1)*(S+2)/2
else:
    ret=(S+1)*(S+2)/2-(S-K)*(S-K+1)/2*3
print(int(ret))
