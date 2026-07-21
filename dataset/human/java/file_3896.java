import java.util.Scanner;

public class Main{
    public static void main(String[] args){
        Scanner input = new Scanner(System.in);
        String Str = input.nextLine();
          
        System.out.println(insertX(Str));
    }
    
    private static int insertX(String string){
        int start = 0;
        int end = string.length() - 1;
        int countx = 0;
        while(start < end){
            if(string.charAt(start) != string.charAt(end) && string.charAt(start) != 'x' && string.charAt(end) != 'x'){
                countx = -1;
                return countx;
            }
            else if(string.charAt(start) != string.charAt(end)){
                countx ++;
                if(string.charAt(start) == 'x') end ++;
                else start --;
            }
            start ++;
            end --;
        }
        return countx;
    }
}
