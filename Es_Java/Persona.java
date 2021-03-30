import java.time.LocalDate;
import java.util.Date;

public class Persona {
    public String nome;
    public String cognome;

    private String lavoroSegreto;

    public LocalDate dataDiNascita;

    public Persona(String nome, String cognome, LocalDate nascita, String lavoro){
        this.nome = nome;
        this.cognome = cognome;
        this.dataDiNascita = nascita;
        this.lavoroSegreto = lavoro;
    }

    public String toString(){

        // String x = String
        //     .format("Nome 1% Cognome: 2%, Data di nascita: %3", this.nome, this.cognome, this.dataDiNascita);
            
        return "Nome: "+this.nome+" Cognome: "+this.cognome+" Data di nascita: "+this.dataDiNascita;
    }

    public void Agisci(){
        if(this.lavoroSegreto.equals("Assassino"))
            System.out.println("Uccido");
        else
            System.out.println("Lavoro");
    }
}
