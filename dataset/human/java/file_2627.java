import java.util.*;


public class Main {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        String a = sc.next();
        String b = sc.next();

        ArrayList<Character> anagramA = new ArrayList<Character>();
        for(int i = 0; i < a.length(); i++){
            char c = a.charAt(i);
            int insertIndex = anagramA.size();
            for(int j = 0; j < anagramA.size(); j++){
                if(insertIndex == anagramA.size() && c <= anagramA.get(j)){
                    insertIndex = j;
                }
            }
            anagramA.add(insertIndex, c);
        }
        ArrayList<Character> anagramB = new ArrayList<Character>();
        for(int i = 0; i < b.length(); i++){
            char c = b.charAt(i);
            int insertIndex = anagramB.size();
            for(int j = 0; j < anagramB.size(); j++){
                if(insertIndex == anagramB.size() && c >= anagramB.get(j)){
                    insertIndex = j;
                }
            }
            anagramB.add(insertIndex, c);
        }

        String ans = "No";

        for(int i = 0; i < Math.min(anagramA.size(), anagramB.size()); i++){
            if(anagramA.get(i) < anagramB.get(i)){
                ans = "Yes";
                break;
            }else if(anagramA.get(i) > anagramB.get(i)){
                break;
            }else if(i == Math.min(anagramA.size(), anagramB.size())-1 && anagramA.size() < anagramB.size()){
                ans = "Yes";
            }
        }
        System.out.println(ans);
    }
}
