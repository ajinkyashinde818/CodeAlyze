import java.util.Scanner;
import java.util.Random;
import java.util.Arrays;
import java.util.Comparator;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.HashMap;

public class Main {
	
	public static void main(String[] args) {
		HashMap<String, Integer> map = new HashMap<>();
		
		map.put("A", 10);
		map.put("B", 11);
		map.put("C", 12);
		map.put("D", 13);
		map.put("E", 14);
		map.put("F", 15);
		
		
		Scanner sc = new Scanner(System.in);
		String x = sc.next();
		String y = sc.next();
		
		int a = map.get(x);
		int b = map.get(y);
		
		if(a < b) System.out.println("<");
		if(a == b) System.out.println("=");
		if(a > b) System.out.println(">");
		
	}
	
	
}
