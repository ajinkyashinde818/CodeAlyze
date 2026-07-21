from collections import deque

s = str(input())
q = int(input())
flip = -1
strf = deque()
strb = deque()

for i in range(q):
    query = list(map(str, input().split()))
    if query[0] == '1':
        flip = flip * -1
    elif query[0] == '2':
        if query[1] == '1':
            if flip == -1:
                strf.appendleft(query[2])
            else:
                strb.append(query[2])
        elif query[1] == '2':
            if flip == -1:
                strb.append(query[2])
            else:
                strf.appendleft(query[2])

# print(strf)
# print(strb)
ans = ''.join(strf) + s + ''.join(strb)
if flip == 1:
    ans = ans[::-1]
print(ans)

# s = str(input())
# q = int(input())
# flip = -1
# strs = '/'
 
# for i in range(q):
#     query = list(map(str, input().split()))
#     if query[0] == '1':
#         flip = flip * -1
#     elif query[0] == '2':
#         if query[1] == '1':
#             if flip == -1:
#                 strs = query[2] + strs
#             else:
#                 strs = strs + query[2]
#         else:
#             if flip == -1:
#                 strs = strs + query[2]
#             else:
#                 strs = query[2] + strs
 
# if flip == -1:
#     ans = strs.replace('/', s)
# else:
#     ans = strs[::-1].replace('/', s[::-1])
 
# print(ans)
