import java.io.*;

public class Program {

    public static void Step1(){
        try {
            File fp = new File("esempio/elenco.txt");
    
            if(fp.exists())
                System.out.println("Esiste");
            if(fp.isDirectory())
                System.out.println("Si tratta di una cartella");
            if(fp.isFile())
                System.out.println("Si tratta di un file");
    
            fp.mkdirs();
            fp.createNewFile();
    
            if(fp.exists())
                System.out.println("Esiste");
    
            //fp.delete();

            File fp2 = new File("esempio2/elenco2.txt");
            fp2.mkdirs();
            //fp2.createNewFile();
            fp.renameTo(fp2);

            Exception x = new EsempioException("Errore di prova", 5);
            throw x;
        }
        catch(ArithmeticException e){
            System.out.println(e.getMessage() + " " + e.getStackTrace()[0].getLineNumber());
        }
        catch(IOException e){
            System.out.println(e.getMessage() + " " + e.getStackTrace()[0].getLineNumber());
        }
        catch(Exception e){
            System.out.println(e.getMessage() + " " + e.getStackTrace()[0].getLineNumber());
        }
    }
    public static void main(String[] args){
        try{
            Step1();
        }
        catch(Exception e){
            throw e;
        }
    }
}