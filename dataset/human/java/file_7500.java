import java.util.*;
public class Main{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    String s = sc.next();
    int slen = s.length();
    String t = "";
    int i = 0;
    while(i < slen){
      //いろいろ判断。適合すれば、文字数分iをずらす
      if(s.substring(slen-5-i,slen-i).equals("dream") || s.substring(slen-5-i,slen-i).equals("erase")){
        i += 5;
        continue;
      }else if(s.substring(slen-6-i,slen-i).equals("eraser")){
        i += 6;
        continue;
      }else if(s.substring(slen-7-i,slen-i).equals("dreamer")){
        i += 7;
        continue;
      }else{//どの条件にも適合しないので、等しくならない
        System.out.println("NO");
        return;
      }
    }
    System.out.println("YES");
  }
}
