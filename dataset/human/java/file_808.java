import java.util.*;
import java.io.*;
class Main {

public static void main(String[] args) {
	Scanner sc = new Scanner(System.in);
  	int contests = sc.nextInt();
  	int display = sc.nextInt();
  	int inner = 0;
  	if (contests < 10) { 
    	System.out.println((100 * (10 - contests)) + display);
    }
  else System.out.println(display);
}
}
