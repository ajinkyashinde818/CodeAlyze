n = int(input())

inputs = []

for i in range(3):
    inp = [int(x) for x in input().split(' ')]
    inputs.append(inp)

def solve(n, inputs):
    a = inputs[0]
    b = inputs[1]
    c = inputs[2]

    satisfaction = 0
    last = -1
    dish = -1
    for d in range(n):
        dish = a[d]        
        if dish == last + 1:
            satisfaction += c[dish-2]
        last = a[d]        
        satisfaction += b[dish-1]

    print(satisfaction)

solve(n, inputs)
