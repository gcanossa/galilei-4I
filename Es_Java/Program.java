import java.time.LocalDate;
import java.util.Iterator;

public class Program {
    public static void main(String args[]){
        System.out.println("Ciao mondo");

        for(int i=0;i<args.length;i++){
            System.out.println(args[i]);
        }

        // for(String value : args){
        //     System.out.println(value);
        // }

        Program.scriviBau();

        Program x = new Program();
        x.nome="Piero";
        x.scriviCiao();

        Program y = new Program();
        y.nome="Carlo";
        y.scriviCiao();

        Persona p = new Persona("Piero", "Rossi", LocalDate.of(1950, 3, 15), "Assassino");

        System.out.println(p);
        p.Agisci();
    }

    public String nome;

    public void scriviCiao(){
        System.out.println("Ciao "+this.nome);
    }

    public static void scriviBau(){
        System.out.println("Bau");
    }
}