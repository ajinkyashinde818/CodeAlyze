def main():
  n = int(input())
  vs = list(map(int, input().split()))
  avs = [abs(v) for v in vs]
  mvs = [v for v in vs if v < 0]
  
  mvs_len = len(mvs)
  avs_sum = sum(avs)
  avs_min = min(avs)
  if mvs_len % 2 == 0:
    return avs_sum
  else:
    return avs_sum - avs_min * 2
    
  
print(main())
