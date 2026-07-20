class Main {
    public static void main(String[] args)
{
        for (int row = 1; row <= 8; row++)
{
            for (int column = 1; column <= row; column++)
{
                System.out.print("*");
            }
            System.out.println();
        }
    }
}
