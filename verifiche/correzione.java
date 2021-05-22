public class Classe {
    public List<Studente> stundenti;
    public Insegnante insegnante;

    public Classe(Insegnante insegnante, List<Studente> stundenti){
        this.insegnante = insegnante;
        this.studenti = studenti;
    }
}

public class Scuola{
    public List<Classe> classi;
    public List<Animale> animali = new ArrayList<Animale>();

    public Scuola(List<Classe> classi){
        this.classi = classi;
    }

}

public FantasyMachinegun exteds ItemBase implements IWeapon {
    private Machinegun pistola;
    
    public FantasyMachinegun(String name,Machinegun pistola){
        super(name);
        this.pistola = pistola;
    }

    public void activate(){
        this.pistola.shoot();
    }
}

public class FileIterator implements Iterator {
    private File file;
    private Scanner scanner;

    public FileIterator(String name){
        this.file = new File(name);
        if(!this.file.exists())
            this.file.createNew();
        this.scanner = new Scanner(this.file);
    }

    public bool hasNext(){
        return this.scanner.hasNextLine();
    }

    public string next(){
        return this.scanner.nextLine();
    }
}

for(String line : new FileIterator("miofile.txt")){
    System.out.println(line);
}

public interface IWarriorMemento{
    void Save(Warrior w);
    Warrior Load();
}

public class WarriorMemento implements IWarriorMemento {
    private File file;

    public WarriorMemento(String name){

        this.file = new File(name);
        if(!this.file.exists())
            this.file.createNew();
    }


    public void Save(Warrior w){
        FileWriter fw = new FileWriter(this.file);
        fw.write(w.toString());
    }

    public Warrior Load(){
        Scanner sc = new Scanner(this.file);

        Warrior w = new Warrior();
        while(sc.hasNextLine()){
            w.attach(new Sword(sc.nextLine()));
        }

        return w;
    }
}

public interface Grilletto {
    void tira();
}

public class GrillettoDiPistola implements Grilletto {
    public void tira(){}
}

public class GrillettoMultiplo implements Grilletto {
    public final List<Grilletto> grilletti = new ArrayList<Grilletto>();


    public void tira(){
        for(Grilletto g :this.grilletti){
            g.tira();
        }
    }
}

public class Armeria {
    private static Armeria instance;
    public static Armerira getArmeria(){
        return 
    }
    private Armeria(){}
}