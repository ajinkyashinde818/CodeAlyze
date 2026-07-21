n=int(input())
a=list(map(int,input().split()))
nums=sum(a)-a[0]
numa=a[0]
def ab(num1,num2):
    return abs(num1-num2)
ans=ab(nums,numa)
for i in range(n-2):
    nums-=a[i+1]
    numa+=a[i+1]
    ans=min(ans,ab(nums,numa))
print(ans)
