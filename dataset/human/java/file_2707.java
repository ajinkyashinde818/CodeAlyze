import java.util.*;
import java.util.stream.*;
import static java.util.Comparator.*;

public class Main{
  public static void main(String[] args) throws Exception{
	Scanner sc = new Scanner(System.in);
    char[] s = sc.nextLine().toCharArray();
    char[] t = sc.nextLine().toCharArray();
    List<Character> charListS = new ArrayList<>();
    List<Character> charListT = new ArrayList<>();
    for(char x : s){
        charListS.add(x);
    }
    for(char y : t){
        charListT.add(y);
    }
    String str1 = charListS.stream().sorted(naturalOrder()).collect(StringBuilder::new,StringBuilder::append,StringBuilder::append).toString();
    String str2 = charListT.stream().sorted(reverseOrder()).collect(StringBuilder::new,StringBuilder::append,StringBuilder::append).toString();
    String result = str1.compareTo(str2) < 0 ? "Yes" : "No";
    System.out.println(result);
  }
}
