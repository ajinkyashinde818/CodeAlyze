import sys

s = sys.stdin.readline().replace('\n','')
q = sys.stdin.readline().replace('\n','')
q = int(q)

flag = 0
prev=""
end=""
for i in range(0,q):
	str = sys.stdin.readline().replace('\n','')
        if( str[0] == '1'):
          flag += 1
        if( str[0] == '2'):
          if( str[2] == '1'):
	    if( flag % 2 == 0):
	      prev = str[4] + prev
	    else:
	      end = end + str[4]
          if( str[2] == '2'):
	    if( flag % 2 == 0):
	      end = end + str[4]
	    else:
	      prev = str[4] + prev

ss = prev + s + end
if( flag % 2 == 1):
  ss = ss[::-1]

print ss
sys.stdout.flush()
