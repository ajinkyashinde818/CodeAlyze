import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class Main {
    
    public static void main(String[] args) {
	int N;
	Scanner scan = new Scanner(System.in);

	N = scan.nextInt();
	List<Long> A = new ArrayList<>(N);
	for (int i = 0; i < N; i++) {
	    A.add(scan.nextLong());
	}

	Collections.sort(A);

	for (int i = 0; i < N-1; i++) {
	    if (A.get(i) + A.get(i+1) < 0) {
		A.set(i, A.get(i) * -1);
		A.set(i+1, A.get(i+1) * -1);
	    }
	}

	long sum = 0;
	for (int i = 0; i < N; i++) {
	    sum += A.get(i);
	}
	System.out.println(sum);
	return;
    }
}
