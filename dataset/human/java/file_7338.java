import java.util.*;
public class Main{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    String str = sc.next();
    String[] strs = {"dream", "dreamer", "erase", "eraser"};
    if(ans(0, str,strs)){
      System.out.println("YES");
    }else{
      System.out.println("NO");
    }
  }
  
  public static boolean ans(int index, String str, String[] strs){
    if(str.length() == index){
      return true;
    }
    for(int i = 0; i < strs.length; i++){
      if(str.indexOf(strs[i], index) == index){
        if(ans(index + strs[i].length(), str, strs)){
          return true;
        }
      }
    }
    return false;
  }
}
