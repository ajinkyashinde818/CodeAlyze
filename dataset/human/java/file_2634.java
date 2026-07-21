import java.util.*;

class Main{
  public static void main(String args[]){
    Scanner sc = new Scanner(System.in);
    StringBuffer s = new StringBuffer(sc.next());
    StringBuffer t = new StringBuffer(sc.next());
    for(int i=0;i<s.length();i++){
      for(int j=i;j>0;j--){
        if(s.charAt(j)<s.charAt(j-1)){
          char temp = s.charAt(j);
          s.setCharAt(j,s.charAt(j-1));
          s.setCharAt(j-1,temp);
        }else{
          break;
        }
      }
    }
    for(int i=0;i<t.length();i++){
      for(int j=i;j>0;j--){
        if(t.charAt(j)>t.charAt(j-1)){
          char temp = t.charAt(j);
          t.setCharAt(j,t.charAt(j-1));
          t.setCharAt(j-1,temp);
        }else{
          break;
        }
      }
    }
    if(s.toString().compareTo(t.toString())<0){
      System.out.println("Yes");
    }else{
      System.out.println("No");
    }
  }
}
