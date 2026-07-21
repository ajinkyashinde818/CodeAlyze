def main():
	S = input()

	border = len(S)

	while True:
		if S[border - 5: border] == "dream":
			border -= 5
		elif S[border - 7: border] == "dreamer":
			border -= 7
		elif S[border - 5: border] == "erase":
			border -= 5
		elif S[border - 6: border] == "eraser":
			border -= 6
		else:
			break

	if border == 0:
		print("YES")
	else:
		print("NO")
 
 
if __name__ == "__main__":
  	main()
