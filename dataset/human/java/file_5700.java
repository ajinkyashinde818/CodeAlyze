import java.util.*;

class Main{
public static void main(String[] args){
Scanner sc = new Scanner(System.in);
String[] s = sc.next().split("");
  String[] n = {"a","b","c"};
  Arrays.sort(s);
  if(Arrays.equals(s,n)){
System.out.print("Yes");
  }else{
System.out.print("No");
  }
}
}
