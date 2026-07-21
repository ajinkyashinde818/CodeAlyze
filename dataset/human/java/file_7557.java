import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        String res = "NO";
        int index = 0;
        while (true){
            if (s.length() == index){
                res = "YES";
                break;
            }
            if (s.length() - index < 5){
                break;
            }
            
            if(s.startsWith("dream",index)){
               index += 5; 
               if (s.startsWith("eraser",index)){
                   index += 6;
               }else if (s.startsWith("erase",index)){
                   index += 5;
               }else if (s.startsWith("er",index)){
                   index += 2;
               }
               
            }else if (s.startsWith("erase",index)){
                index += 5;
                if (s.startsWith("eraser",index)){
                    index += 6;
                }else if (s.startsWith("r",index)){
                    index += 1;
                }
            }else{
                break;
            }
        }

        System.out.println(res);
        
    }

}
