import java.util.*;
class Main
{
  public static void main(String[] args)
  {
    Scanner sc = new Scanner(System.in);
    
    String s1 = sc.next();
    String s2 = s1.replace("eraser","").replace("erase","").replace("dreamer","").replace("dream","");
    
    if(s2.length()==0){
      System.out.println("YES");
    }else{
      System.out.println("NO");
    }
  }
}
