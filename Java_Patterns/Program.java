import java.util.Iterator;

import javax.swing.plaf.synth.SynthStyle;

public class Program {

    public static void main(String[] args){
        Calcolatrice x;

        x = new CalcSum();
        x.start();

        x = new CalcConst();
        x.start();

        String[] y = new String[] {
            "Pinotti",
            "Luca",
            "Ciao"
        };

        Iterator<E> z = new Iterator(y);

        while(z.hasNext()){
            System.out.println(z.next());
        }
    }
}