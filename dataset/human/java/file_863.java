import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
	    int n = sc.nextInt();
	    int k = sc.nextInt();
	    int r;
	    if(n >= 10){
            r = k;
        }else{
	        r = k + 100 * (10 - n);
        }
        System.out.println(r);
    }
}
