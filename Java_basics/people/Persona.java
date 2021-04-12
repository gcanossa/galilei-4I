package Java_basics.people;

public abstract class Persona implements ICamminatore, ICantante {
    private String nome;

    public Persona(String n){
        this.nome = n;
    }

    public abstract void parla();

    protected String getNome(){
        return this.nome;
    }

    @Deprecated
    public void lamentati(){
        System.out.println("Ufffa");
    }

    @Override
    public String toString() {
        
        return "Persona "+this.getNome();
    }

    @Override
    public void cammina() {
        // TODO Auto-generated method stub
        
    }

    @Override
    public void fermati() {
        // TODO Auto-generated method stub
        
    }

    @Override
    public void girati(String direzione) {
        // TODO Auto-generated method stub
        
    }

    @Override
    public void canta() {
        // TODO Auto-generated method stub
        
    }
}