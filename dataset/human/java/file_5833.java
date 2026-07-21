import java.util.*;
class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String n = sc.nextLine();
        String[] splitedString = n.split("", 0);
        int a = 0;
        int b = 0;
        int c = 0;
        boolean judge = true;
        for(int i = 0; i < splitedString.length; i++){
            switch(splitedString[i]){
                case  "a":
                    if(a == 1){
                        judge = false;
                    }else{
                        a++;   
                    }
                    break;
                case  "b":
                    if(b == 1){
                        judge = false;
                    }else{
                        b++;   
                    }
                    break;
                case  "c":
                    if(c == 1){
                        judge = false;
                    }else{
                        c++;   
                    }
                    break;
            }
        }
        if(!judge){
            System.out.println("No");
        }else{
            System.out.println("Yes");
        }
    }
}
