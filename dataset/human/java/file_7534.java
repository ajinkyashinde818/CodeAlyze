import java.util.Scanner;

class Solver {

    private final String S;

    Solver(Scanner in){
        S = in.next();
    }

    void solve() {
        System.out.println(S.matches("(dream(er)?|eraser?)+") ? "YES" : "NO");
    }
}

class Main{
    public static void main(String[] args){
        Scanner in = new Scanner(System.in);

        new Solver(in).solve();

        in.close();
    }
}
