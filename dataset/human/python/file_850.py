def inner_rate(num_participate, outer_rate):
    if(num_participate >= 10):
        return outer_rate
    else:
        return outer_rate + 100 * (10 - num_participate)

if __name__ == '__main__':
  num_participate, outer_rate = input().split()
  num_participate = int(num_participate)
  outer_rate = int(outer_rate)
  
  print(inner_rate(num_participate, outer_rate))
