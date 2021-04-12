package Java_basics.people;

public class Studente extends Persona {

    public Studente(String n){
        super(n);
    }

    public void parla(){
        System.out.println("Cose a caso");
    }

    @Override
    public void lamentati(){
        //super.lamentati();
        System.out.println("troppo da studiare");
    }

    public void lamentati(@Deprecated String motivo){
        super.lamentati();
        System.out.println(motivo);
    }

    public String toString() {
        
        return super.toString() + " è uno studente";
    }
}