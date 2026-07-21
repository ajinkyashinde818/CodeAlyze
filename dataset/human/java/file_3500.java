import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int[] nums=new int[100];
        for(int i=0;i<6;i++){
            nums['A'+i]=i;
        }
        String s=sc.nextLine();
        if(nums[s.charAt(0)]>nums[s.charAt(2)])System.out.println(">");
        else if(nums[s.charAt(0)]<nums[s.charAt(2)])System.out.println("<");
        else System.out.println("=");

    }
}
