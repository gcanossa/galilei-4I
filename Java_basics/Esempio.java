public class Esempio<T>{

    public String nome;

    private int anni;

    public T valore;

    public void salutaNome(){
        System.out.println("Ciao "+this.nome);
    }

    public void salutaNomeConPunteggio(int punteggio){
        System.out.println("Ciao "+this.nome+", voto:"+punteggio);
    }
    public void salutaNomeConPunteggio(double punteggio){
        System.out.println("Ciao "+this.nome+", voto:"+punteggio);
    }

    public static void salutaEBasta(){
        System.out.println("Ciao e basta");
    }

    public static void salutaNomeStatic(Esempio x){
        System.out.println("Ciao "+x.nome);
    }
    public static void salutaNomeStatic(Esempio x, Esempio d){
        System.out.println("Ciao "+x.nome+" e "+d.nome);
    }
    public static void salutaNomeStatic(Esempio x, int punteggio){
        System.out.println("Ciao "+x.nome+", voto:"+punteggio);
    }
}