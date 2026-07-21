import java.util.*;
class Main {
    public static void main(String[] args) {
	Scanner sc = new Scanner(System.in);
	int A = sc.nextInt();
	int B = sc.nextInt();
	int C = sc.nextInt();
	int result = B;
	if(C<= A+B) {
	    result = result+C;
	}else {
	    result = result + (A+B) + 1;
	}
	System.out.println(result);

    }
}
