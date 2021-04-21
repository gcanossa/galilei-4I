public class EsempioException extends Exception {
    public int voto;

    EsempioException(String message, int voto){
        super(message);

        this.voto = voto;
    }

    @Override
    public String getMessage(){
        return super.getMessage() + " con voto: "+this.voto;
    }
}