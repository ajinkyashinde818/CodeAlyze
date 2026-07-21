import numpy as np

rawRounds = input()
rawDistances = input()

mizuumiRound = int(rawRounds.split()[0])
houseNumber = int(rawRounds.split()[1])
distances = [int(n) for n in rawDistances.split()]

sortedDistances = sorted(distances)

betweens = list(sortedDistances)
for i in range(len(betweens)-1) :
    betweens[i+1] -= sortedDistances[i]

betweens[0] = mizuumiRound - sortedDistances[len(sortedDistances)-1] + sortedDistances[0]

startPoint = betweens.index(max(betweens))

routeLen = sum(betweens) - betweens[startPoint]

print(routeLen)
