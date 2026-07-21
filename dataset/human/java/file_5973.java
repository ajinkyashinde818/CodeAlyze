import java.util.Scanner;
 
public class Main {
public static void main(String args[]){
Scanner sn=null;
sn= new Scanner(System.in);
String S=sn.nextLine();
if(S.equals("abc") || S.equals("acb") || S.equals("bac") ||S.equals("bca")||S.equals("cab")||S.equals("cba")){
System.out.println("Yes");
}else{
System.out.println("No");
}
}
}
