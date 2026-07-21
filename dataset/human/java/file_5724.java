import java.util.*;

public class Main {
    public static void main(String[] args){
    
    Scanner sc = new Scanner(System.in);
    String S = sc.next();
    char[]ss = S.toCharArray();
    
    int cou = 0;
    for(int i=0; i<3; i++){
    if(ss[0]==ss[1]){
        cou++;    
    }
    if(ss[1]==ss[2]){
        cou++;
    }
    if(ss[0]==ss[2]){
        cou++;    
    }
}
    if(cou>0){
    System.out.println("No");
     }else{
    System.out.println("Yes");   
        }
    }
}
