import java.util.Arrays;
import java.util.Collections;
import java.util.Scanner;

 class Main {
    public static void main(String[]args){
        Scanner scan = new Scanner(System.in);
        char s1[] = scan.next().toCharArray();
        char s2[] = scan.next ().toCharArray();
        Character[] newarr = new Character[s2.length];
        int i =0 ;
        for(char ch : s2){
            newarr[i++] = Character.valueOf(ch) ; 
        }
        Arrays.sort(s1 );
        Arrays.sort( newarr,Collections.reverseOrder());
        StringBuilder sb = new StringBuilder();
        for(Character x : newarr){
            sb.append(x);
        }
         
        //System.out.println(String.valueOf(s1)  + " "+sb.toString());
        if(String.valueOf(s1).compareTo(sb.toString()) < 0){
            System.out.println("Yes");
        }
        else{
            System.out.println("No");
        }
        
        
    }
    
    
}
