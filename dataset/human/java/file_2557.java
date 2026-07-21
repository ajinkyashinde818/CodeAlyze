import java.util.*;

public class Main{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    String s = sc.nextLine();
    //String blank = sc.nextLine();
    String t = sc.nextLine();
    char sary[] = new char[s.length()];
    char tary[] = new char[t.length()];

    for(int i = 0; i < s.length(); i++){
      sary[i] = s.charAt(i);
    }
    for(int i = 0; i < t.length(); i++){
      tary[i] = t.charAt(i);
    }

    Arrays.sort(sary);
    Arrays.sort(tary);
    //Collections.reverseOrder()はプリミティブ型は使えないっぽいので...
    //s = Arrays.toString(sary);//いわゆるStringにならない...
    String sorted_s = "";
    for(int i = 0; i < s.length(); i++){
      sorted_s += String.valueOf(sary[i]);
    }

    String sorted_t = "";//=nulだと"null"にtary[i]がくっついてしまう
    for(int i = t.length()-1; i >= 0; i--){
      sorted_t += String.valueOf(tary[i]);
    }


    if(sorted_s.compareTo(sorted_t) < 0){
      System.out.println("Yes");
    }else{
      System.out.println("No");
    }

  }
}

/*
Scanner sc = new Scanner(System.in);
int n = sc.nextInt();
String blank = sc.nextLine();
String s = sc.nextLine();
System.out.println();
System.exit(0)
*/
