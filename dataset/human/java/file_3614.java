import java.util.Scanner;
class Main{
    public static void main(String[] args) {
        Scanner scn=new Scanner(System.in);
        String a=scn.next();
        String b=scn.next();
        scn.close();
        String answer="=";
        int ai=0;
        int bi=0;
        switch(a){
            case "A":
                ai=10;
                break;
            case "B":
                ai=11;
                break;
            case "C":
                ai=12;
                break;
            case "D":
                ai=13;
                break;
            case "E":
                ai=14;
                break;
            case "F":
                ai=15;
                break;
            default:
                ai=Integer.parseInt(a);
        }
        switch(b){
            case "A":
                bi=10;
                break;
            case "B":
                bi=11;
                break;
            case "C":
                bi=12;
                break;
            case "D":
                bi=13;
                break;
            case "E":
                bi=14;
                break;
            case "F":
                bi=15;
                break;
            default:
                bi=Integer.parseInt(b);
        }
        if(ai>bi){
            answer = ">";
        }
        else if(ai<bi){
            answer = "<";
        }
        System.out.println(answer);
    }
}
