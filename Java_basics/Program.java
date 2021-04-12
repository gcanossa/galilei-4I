import java.util.Scanner;
import Java_basics.people.*;

// import Java_basics.esempio.Persona;
// import Java_basics.esempio.*;

public class Program {
    public static void main(String[] args){

        // Esempio.salutaEBasta();

        // Esempio p = new Esempio();
        // p.nome = "Piero";

        // p.salutaNome();

        // p.salutaNomeConPunteggio(6);
        // p.salutaNomeConPunteggio(6.5);

        // Esempio q = new Esempio();
        // q.nome = "Mario";

        // q.salutaNome();

        // Esempio.salutaNomeStatic(p);
        // Esempio.salutaNomeStatic(q);
        // Esempio.salutaNomeStatic(p,q);

        // Esempio.salutaNomeStatic(p, 4);

        // Persona x = new Persona("Luca");
        Persona y = new Studente("Anna");
        y = new Professore("Ganmaria");
    //     y = new StudenteUni("Piero");

    //     Scanner s = new Scanner(System.in);

        int prova = 12; //s.nextInt();

        System.out.println(y.toString()+" = "+prova);

    //     Studente x = new Studente("fdfs");
    //     Persona s = x;
    //     ICamminatore prova = s;

    //     prova.cammina();

    //     ICamminatore[] arrp = new ICamminatore[] { new Studente(""), new Professore(""), new Dog() };

    //     for(int i=0;i<arrp.length;i++)
    //         arrp[i].cammina();

    //     y.parla();
    //     y.lamentati();

    //     ((Studente)y).lamentati("ho sonno");
    }
}