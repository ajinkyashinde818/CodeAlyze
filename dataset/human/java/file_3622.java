import java.util.Scanner;
import java.util.HashMap;

class Main {
  public static void main(String[] args){

    Scanner sc = new Scanner(System.in);
    //HashMap.putは置き換え<文字列→数値>
    HashMap<String, Integer> hashmap = new HashMap<>();

    hashmap.put("A" , 10);
    hashmap.put("B" , 11);
    hashmap.put("C" , 12);
    hashmap.put("D" , 13);
    hashmap.put("E" , 14);
    hashmap.put("F" , 15);


    String X = sc.next();
    String Y = sc.next();


//HashMap.getで.putで書き換えた数値を取得
    if  (hashmap.get(X) > hashmap.get(Y)){
      System.out.println(">");
    }
    else if (hashmap.get(X) < hashmap.get(Y)) {
      System.out.println("<");
    }
    else {
      System.out.println("=");
    }
  }
}
