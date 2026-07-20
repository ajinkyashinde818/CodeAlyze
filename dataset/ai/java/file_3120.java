class Main {
	static long factorial(int number) {
		return number < 2 ? 1 : number * factorial(number - 1);
	}
	public static void main(String[] args) {
		System.out.println(factorial(2));
	}
}
