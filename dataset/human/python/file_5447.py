def print_ans(N):
  """
  Parameters
  --------------
  >>> print_ans("99")
  Yes
  >>> print_ans("19") 
  Yes
  >>> print_ans("17")
  No
  """
  if N[0] == "9" or N[1] == "9":
    print("Yes")
  else:
    print("No")
  

def main():
  N = input()
  print_ans(N)


if __name__ == '__main__':
  main()
