def strr():
 a=raw_input()
 return a
def sstrr():
 a=raw_input().split()
 return a
def intt():
 a=int(raw_input())
 return a
def iintt():
 a=[int(s) for s in raw_input().split()]
 return a
def nestt(t):
 a=[raw_input().split() for s in range(t)] 
 return a

nr=iintt()
n=nr[0]
r=nr[1]
if n>=10:
 a=r
else:
 a=r+100*(10-n)
print a
