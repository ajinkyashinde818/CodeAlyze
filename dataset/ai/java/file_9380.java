// Example application
class Main {
    public static void main(String[] args)
{
        int number = 32, divisor = 2;
        boolean prime = number > 1;
        while (divisor * divisor <= number)
{
            if (number % divisor == 0) prime = false;
            divisor++;
        }
        System.out.println(prime);
    }
}
