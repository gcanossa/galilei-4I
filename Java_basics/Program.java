import java.util.ArrayList;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.List;
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
        // Persona y = new Studente("Anna");
        // y = new Professore("Ganmaria");
    //     y = new StudenteUni("Piero");

    //     Scanner s = new Scanner(System.in);

        // int prova = 12; //s.nextInt();

        // System.out.println(y.toString()+" = "+prova);

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

        ArrayList<Integer> al = new ArrayList<Integer>();
        LinkedList<Integer> ll = new LinkedList<Integer>();

        List<Integer> list;

        list = al;
        list.add(1);
        list.add(18);

        list = ll;
        list.add(123);
        list.add(-2);

        list = al;
        for (Integer item : list) {
            System.out.println(item);
        }

        list = ll;
        for (Integer item : list) {
            System.out.println(item);
        }

        Iterator<Integer> iter = list.iterator();

        while(iter.hasNext()){
            Integer item = iter.next();
            System.out.println(item);
        }
    }
}