import java.util.Scanner;

class Main {
  public static void main(String args[]){
    String str;
    Scanner scan = new Scanner(System.in);
    str = scan.nextLine();
    scan.close();
    if(str.equals("abc") || str.equals("acb") || str.equals("bac") || str.equals("bca") || str.equals("cab") || str.equals("cba")){
      System.out.println("Yes");
    }
    else{
      System.out.println("No");
      }
  }
}
