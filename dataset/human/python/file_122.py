import sys

def main(inp):
    r,g,b,n = map(int,next(inp).split())
    box = sorted([r,g,b],reverse = True)
    
    ans = 0
    for i in range(int(n/box[0])+1):
        for j in range(int((n-i*box[0])/box[1])+1):
            if((n-i*box[0]-j*box[1])%box[2] == 0):
                ans += 1
    
    return ans
  
print(main(sys.stdin))
