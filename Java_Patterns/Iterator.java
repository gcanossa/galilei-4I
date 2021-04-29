public class Iterator {
    private String[] persone;

    private int index=0;

    Iterator(String[] p){
        this.persone = p;
    }

    public boolean hasNext(){
        return this.index < this.persone.length;
    }

    public Persona next(){
        Persona p = new Persona(this.persone[this.index]);
        this.index++;
        return p;
    }
}
