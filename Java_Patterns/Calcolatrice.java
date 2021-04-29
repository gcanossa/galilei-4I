import java.util.Scanner;

public abstract class Calcolatrice {
    protected double op1;
    protected double op2;

    public abstract double calcola();

    public double start() {
        Scanner sc = new Scanner(System.in);
        this.op1=sc.nextDouble();
        this.op2=sc.nextDouble();

        double result = this.calcola();

        System.out.println(result);

        return result*2;
    }
}
