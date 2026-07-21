import sys

def main(lines):
  n, r = map(int,lines[0].split())

  if n >= 10:
    print(r)
  else:
    print(r + 100*(10-n))
  return
    
if __name__ == '__main__':
    lines = []
    for l in sys.stdin:
        lines.append(l.rstrip('\r\n'))
    main(lines)
