import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		sc.nextLine();
		int count = 0;
		String str = "";
		String[] line;
		List<String[]> lineArray = new ArrayList() ;
		
      	while (sc.hasNextLine()) {
      		str = sc.nextLine();
      		line = str.split(" ");
      		lineArray.add(line);
        }
      	
      	for (String[] comLine : lineArray) {
      		if (comLine[0].equals(comLine[1])) {
      			count++;
      			if (count == 3) {
      				break;
      			}
      		} else {
      			count = 0;
      		}
      	}

      	if (count == 3) {
      		System.out.println("Yes");
      	} else {
      		System.out.println("No");
      	}
	}
}
