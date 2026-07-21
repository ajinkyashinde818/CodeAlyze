import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);

		int a = sc.nextInt();
		int b = sc.nextInt();

		System.out.println(lcm(a, b));
	}

	static int gcd(int a, int b){
		int tmp;

		while (a % b != 0)
		{
			tmp = b;
			b = a % b;
			a = tmp;
		}
		return b;
	}
	
    static long lcm(int a, int b, int gcd){
    	return (long)a*(b/gcd);
    }

    static long lcm(int a, int b){
    	int g = gcd(a, b);

    	return lcm(a,b,g);
    }

}
