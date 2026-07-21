import java.util.*;
public class Main{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    char[] s = sc.next().toCharArray();
    int cnt = 0;
    int l = 0;
    int r = s.length-1;
    while(l<=r){
      if(s[l]==s[r]){
        l++;
        r--;
      }else if(s[l]=='x'){
        l++;
        cnt++;
      }else if(s[r]=='x'){
        r--;
        cnt++;
      }else{
        cnt = -1;
        break;
      }
    }
    System.out.println(cnt);
  }
}
