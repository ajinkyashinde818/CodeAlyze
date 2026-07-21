import os

def main():
	n = int(input())
	a_list = list(map(int, input().split()))
	b_list = list(map(int, input().split()))
	c_list = list(map(int, input().split()))
	result_num = sum(b_list)

	for i,v in enumerate(a_list):
		count = v
		if i == (len(a_list)-1):
			break
		if (count+1) == a_list[i+1]:
			result_num += c_list[count-1]
	print(result_num)		

	
if __name__ == "__main__":
	main()
