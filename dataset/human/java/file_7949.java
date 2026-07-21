class Main {
	public static void main(String[] args){
		java.util.Scanner sc = new java.util.Scanner(System.in);
		int sum = sc.nextInt();
		for(int i=0;i<9;i++){
			sum += sc.nextInt();
		}
		System.out.println(sum);
	}
}
