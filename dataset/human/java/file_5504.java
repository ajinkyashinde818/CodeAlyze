import java.util.Scanner;

public class Main {

    private static Scanner scan = new Scanner(System.in);

    public static void main(String[] args) {
	
	int rate = Integer.parseInt(scan.next());
	System.out.println(rate < 1200 ? "ABC" : "ARC");
	scan.close();
    }
}
