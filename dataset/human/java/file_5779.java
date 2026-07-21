import java.util.*;
import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(System.in);
		char arr[] = sc.nextLine().toCharArray();
		if(arr[0] != arr[1] && arr[1] != arr[2] && arr[2] != arr[0])
			System.out.println("Yes");
		else System.out.println("No");
	}
}
