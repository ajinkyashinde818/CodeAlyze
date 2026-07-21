import java.util.*;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    String s = sc.next();
    String t = sc.next();
    char[] s_array = s.toCharArray();
    char[] t_array = t.toCharArray();
    Arrays.sort(s_array);
    Arrays.sort(t_array);
    t = reverse_array(t_array);
    t_array = t.toCharArray();
    int s_len = s_array.length;
    int t_len = t_array.length;
    boolean judge = true;
    if(s_len < t_len) {
      for(int i = 0; i < s_len; i++) {
        if(s_array[i] > t_array[i]) {
          judge = false;
          break;
        } else if(s_array[i] < t_array[i]) {
          judge = true;
          break;
        }
      }
    } else {
      for(int i = 0; i < t_len; i++) {
        if(s_array[i] > t_array[i]) {
          judge = false;
          break;
        } else if(s_array[i] < t_array[i]) {
          judge = true;
          break;
        } else {
          judge = false;
        }
      }
    }
    if(judge == true) {
      System.out.println("Yes");
    } else {
      System.out.println("No");
    }
  }

  public static String reverse_array(char[] array) {
    int len = array.length;
    char[] new_array = new char[len];
    int count = len - 1;
    for(int i = 0; i < len; i++) {
      new_array[i] = array[count];
      count--;
    }
    String s = String.valueOf(new_array);
    return s;
  }
}
