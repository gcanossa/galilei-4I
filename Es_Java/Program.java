import java.time.LocalDate;

public class Program {
    public static void main(String args[]){
        System.out.println("Ciao mondo");

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