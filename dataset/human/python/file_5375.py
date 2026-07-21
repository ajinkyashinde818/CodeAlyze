import sys
 
input = sys.stdin.readline

a=input()
b=a.split(" ")
N=int(b[0])
M=int(b[1])
in2=[]
out2=[]
for i in range(M):
    c=input()
    d=c.split(" ")
    in1=int(d[0])
    out=int(d[1])
    if in1==1:
        in2.append(str(out))
    elif out==N:
        out2.append(str(in1))
        
in2_set=set(in2)
out2_set=set(out2)
matched_list=list(in2_set & out2_set)
#print(matched_list)
if len(matched_list)==0:
    print("IMPOSSIBLE")
else:
    print("POSSIBLE")
