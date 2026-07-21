def main():
  nagasa, num_house = map(int, input().split())
  house_list = [int(t) for t in input().split()]
  
  max_length = 0
  for i in range(num_house):
    if i != num_house-1:
      dif = house_list[i+1] - house_list[i]
    if i == num_house-1:
      dif = nagasa - house_list[i] + house_list[0]
    if max_length < dif:
      max_length = dif
  print(nagasa - max_length)

main()
