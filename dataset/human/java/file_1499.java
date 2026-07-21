import java.util.Scanner;

class Main{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int M = sc.nextInt();
		String A[] = new String[N];
		String B[] = new String[M];

		for (int i = 0; i < N; i++) {
				A[i]= sc.next();
			}
		for (int i = 0; i < M; i++) {
				B[i]= sc.next();
		}

		int temp = 0;
		for (int i = 0; i < A.length - B.length; i++) {
			String a = A[i];
			String b = B[i];
			int point = a.indexOf(b);
			if(point == -1){
				temp = point;
				break;
			}else if(i == 0){
				temp = point;
			}else{
				if(temp == point){
					continue;
				}else{
					break;
				}
			}
		}
		if(temp == -1){
			System.out.println("No");
		}else{
			System.out.println("Yes");
		}
		sc.close();
	}
}
