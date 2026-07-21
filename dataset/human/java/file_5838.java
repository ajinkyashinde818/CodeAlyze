import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String S = sc.next();
        
        List<String> strs = new ArrayList<>(Arrays.asList("a","b","c"));

        boolean flag = false;
        for(String str : strs){
            if(!S.contains(str)) flag = true;
        }
        String kotae = flag ? "No" : "Yes";
        System.out.println(kotae);
    }
}
