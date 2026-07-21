import java.util.*;
class Main {
    public static void main(String[] args) {
	Scanner sc = new Scanner(System.in);
	int A = Integer.parseInt(sc.next());
	int B = Integer.parseInt(sc.next());
	int K = Integer.parseInt(sc.next());
	int[] arr = new int[100];
	int cnt = 0;
	for(int i = 1; i<=Math.min(A,B); i++) {
	    if(A%i==0 && B%i == 0) {
		arr[cnt] = i;
		cnt++;
	    }
	}
	Arrays.sort(arr);
	System.out.println(arr[arr.length-K]);
    }
}
