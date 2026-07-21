N, M = map(int, raw_input().split())
A = []
B = []

for _ in xrange(N):
    A.append(raw_input())
for _ in xrange(M):
    B.append(raw_input())

def match(x, y):
    for i in xrange(M):
        for j in xrange(M):
            if A[x+i][y+j] != B[i][j]: return None
    return 1

def main():
    for x in xrange(N-M+1):
        for y in xrange(N-M+1):
            if match(x, y):
                return 'Yes'
    return 'No'

if __name__ == '__main__':
    print main()
