# Example program
def factorial(number):
return 1 if number < 2 else number * factorial(number - 1)
print(factorial(9))
