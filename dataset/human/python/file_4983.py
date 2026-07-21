while True:
  dic = {"#":-3, ".":-1, "X":-2, "E":0, "N":1, "W":2, "S":3}
  def fix(c):
    return dic[c]
  w, h = map(int, input().split())
  if w == 0:
    break
  mp = [list(map(fix, list(input()))) for _ in range(h)]
  
  persons = []
  for y in range(h):
    for x in range(w):
      if mp[y][x] in (0, 1, 2, 3):
        persons.append([x, y, mp[y][x]])
  
  vx = (1, 0, -1, 0)
  vy = (0, -1, 0, 1)
  
  time = 0
  while time < 180:
    if not persons:
      print(time)
      break
    reserve = {}
    for index, state in enumerate(persons):
      x, y, d = state
      for i in range(d - 1, d + 3):
        dx, dy = vx[i % 4], vy[i % 4]
        if mp[y + dy][x + dx] in (-1, -2):
          persons[index][2] = i % 4
          if (x + dx, y + dy) in reserve:
            if reserve[(x + dx, y + dy)][1] > (i + 2) % 4:
              reserve[(x + dx, y + dy)] = (index, (i + 2) % 4, mp[y + dy][x + dx])
          else:
            reserve[(x + dx, y + dy)] = (index, (i + 2) % 4, mp[y + dy][x + dx])
          break
    
    reserve = sorted(reserve.items(), key=lambda a:-a[1][0])
    for k, v in reserve:
      nx, ny = k
      index, nd, panel = v
      px, py, _ = persons[index]
      mp[py][px] = -1
      if panel == -1:
        persons[index] = [nx, ny, (nd + 2) % 4]
        mp[ny][nx] = (nd + 2) % 4
      else:
        persons.pop(index)
    
    time += 1
  
  else:
    print("NA")
