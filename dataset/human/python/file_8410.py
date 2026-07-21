import sys
X=input().split()
LONG=int(X[0])
HOUSE=int(X[1])
X=input().split()
PLACE=[0]*LONG
for _ in range(HOUSE):
    place=int(X[_])
    PLACE[place]=1

i=0
while(PLACE[i]==0):
    i+=1
START=i
i=LONG-1
while(PLACE[i]==0):
    i-=1
END=i
"""
一番前にいるやつ: START
一番後ろにいるやつ: END
"""
s_g_long=LONG+START-END
MOST_LONG=s_g_long
"""
s_g_long: STARTとENDの間の距離
MOST_LONG: 最長の間隔
"""
where=START
for _ in range(HOUSE-1):
    """
    全ての間隔の長さをはかり、最長のものを通らないような道のりが最短
    """
    i_idash_long=0
    while(PLACE[where+1]==0):
        where+=1
        i_idash_long+=1
    where+=1
    i_idash_long+=1
    if MOST_LONG<i_idash_long:
        MOST_LONG=i_idash_long

print(LONG-MOST_LONG)
