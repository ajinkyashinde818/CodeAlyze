import java.util.*;

public class Main{
  public static void main(String[]args){
    Scanner sc = new Scanner(System.in);
    String S = sc.nextLine();
    String T = sc.nextLine();
    
    List<Character> list1 = new ArrayList<>();
    List<Character> list2 = new ArrayList<>();
    for(int i = 0; i < S.length(); i++){
      list1.add(S.charAt(i));
    }
    for(int i = 0; i < T.length(); i++){
      list2.add(T.charAt(i));
    }
    
    Collections.sort(list1);
    Collections.sort(list2, Collections.reverseOrder());
    
    String s = "";
    String t = "";
    for(int i = 0; i < S.length(); i++){
      s = s + String.valueOf(list1.get(i));
    }
    for(int i = 0; i < T.length(); i++){
      t = t + String.valueOf(list2.get(i));
    }
    
    
    System.out.println(s.compareTo(t) < 0 ? "Yes" : "No");
  }
}
