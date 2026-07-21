import sys
 
if sys.platform =='ios':
    sys.stdin=open('input_file.txt')
 
a=input()
b=input()
 
a=sorted(a)
b=sorted(b)
cnt=0
 
if a==b:
	print("No")
	sys.exit()
 
for i in range(min(len(a),len(b))):
	if a[i]<b[-(i+1)]:
		print("Yes")
		break
	
	elif a[i]==b[-(i+1)]:
		cnt+=1
		continue
		
	else:
		print("No")
		break
		
if cnt==min(len(a),len(b)) and len(a)<len(b):
	print("Yes")
	
elif cnt==min(len(a),len(b)) and len(a)>len(b):
	print("No")
