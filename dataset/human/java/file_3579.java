import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main {

	private static Map<String,Integer> hexMap = new HashMap<String,Integer>();

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String in1 = sc.nextLine();
		createMap();
		String[] inArray = in1.split(" ");

		int hex1 = toHex(inArray[0]);
		int hex2 = toHex(inArray[1]);
		if (hex1 > hex2){
			System.out.println(">");
		} else if (hex1 < hex2) {
			System.out.println("<");

		} else if (hex1 == hex2) {
			System.out.println("=");
		}


	}

	private static void createMap(){
		hexMap.put("A", new Integer(10));
		hexMap.put("B", new Integer(11));
		hexMap.put("C", new Integer(12));
		hexMap.put("D", new Integer(13));
		hexMap.put("E", new Integer(14));
		hexMap.put("F", new Integer(15));

	}

	private static int toHex(String str) {
		int ret = hexMap.get(str).intValue();
		return ret;
	}
}
