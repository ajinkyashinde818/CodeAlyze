from sys import stdin
data = stdin.readline().rstrip()

def shorten_phrase(x):
    l = len(x)
    if x.startswith("eraser"):
        x = x[6:]
    elif x.startswith("erase"):
        x = x[5:]
    elif x.startswith("dreamera"):
        x = x[5:]
    elif x.startswith("dreamer"):
        x = x[7:]
    elif x.startswith("dream"):
        x = x[5:]
    m = len(x)
    return l != m

while shorten_phrase(data):
    if data.startswith("eraser"):
        data = data[6:]
    elif data.startswith("erase"):
        data = data[5:]
    elif data.startswith("dreamera"):
        data = data[5:]
    elif data.startswith("dreamer"):
        data = data[7:]
    elif data.startswith("dream"):
        data = data[5:]
if len(data) == 0:
    print("YES")
else:
    print("NO")
