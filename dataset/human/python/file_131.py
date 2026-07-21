import math
 
R,G,B,N = map(int,input().split())
 
maxRBox = math.ceil(3000/R)
maxGBox = math.ceil(3000/G)
maxBBox = math.ceil(3000/B)
 
ans = 0
for ri in range(maxRBox+1):
	if N < ri*R:
		break
	for gi in range(maxGBox+1):
		if N < ri*R+gi*G:
			break
			
		if (N - (ri*R+gi*G)) % B == 0:
			bi = (N - (ri*R+gi*G)) // B
			if ri*R+gi*G+bi*B == N:
				ans +=1
				#print(ri,gi,bi,ri*R+gi*G+bi*B)
				
print(ans)
