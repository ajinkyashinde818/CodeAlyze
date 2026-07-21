import java.io.IOException;
import java.util.Scanner;

public class Main {
  public static void main(String[] args) throws IOException {
    Scanner sc = new Scanner(System.in);
    int a = Integer.parseInt(sc.next(),16);
    int b = Integer.parseInt(sc.next(),16);
    String answer = "=";
    if(a>b){
      answer = ">";
    }else if(a<b){
      answer = "<";
    }
    System.out.println(answer);
    }
  }
