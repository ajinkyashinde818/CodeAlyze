import math
import bisect
from queue import Queue
from collections import deque

s = input()

dp = [0 for _ in range(len(s)+1)]

dp[0] = 1

for i in range(len(s)+1):
    if(dp[i] == 1):
        if(i+4 < len(s)):
            if("".join(s[i:i+5]) == "dream"):
                dp[i+5] = 1
            if ("".join(s[i:i + 5]) == "erase"):
                dp[i+5] = 1
        if (i + 6 < len(s)):
            if ("".join(s[i:i + 7]) == "dreamer"):
                dp[i + 7] = 1
        if (i + 5 < len(s)):
            if ("".join(s[i:i + 6]) == "eraser"):
                dp[i + 6] = 1

if(dp[len(s)] == 1):
    print("YES")
else:
    print("NO")
