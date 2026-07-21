import sys
cin = lambda: sys.stdin.readline().strip()
cout = sys.stdout.write

s = cin()

s = s.replace("eraser",'')
s = s.replace("erase",'')
s = s.replace("dreamer",'')
s = s.replace("dream",'')

if(s == ''):
	cout(f"YES"+'\n')
else:
	cout(f"NO"+'\n')
