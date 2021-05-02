import java.util.Map;

public interface IItem {
    String getName();
    void attach(IUser user);
    void activate();
}

public interface IUser {
    void use(String item);
}

public interface IWeapon extends IItem {
}

public interface IPotion extends IItem {
}

public abstract class ItemBase implements IItem {
    private IUser _user;
    private String _name;

    ItemBase(String name){
        this._name = name;
    }

    public String getName(){
        return this._name;
    }
    public void attach(IUser user){
        this._user = user;
    }

    public abstract void activate();
}

public class Sword extends ItemBase implements IWeapon {
    public Sword(String name){
        super(name);
    }

    public void activate(){
        System.out.println("Cut!!!");
    }
}

public class Crossbow extends ItemBase implements IWeapon {

    public Crossbow(String name){
        super(name);
    }

    private int _arrowCount = 10;
    public int getRemainingArrows(){
        return this._arrowCount;
    }

    public void activate(){
        if(this._arrowCount-- > 0){
            System.out.println("Shoot!!!");
        }
    }
}

public class HealingPotion extends ItemBase implements IPotion {

    public HealingPotion(String name){
        super(name);
    }

    public void activate(){
        System.out.println("Heal!!!");
    }
}

public abstract class UserBase implements IUser {
    private List<IItem> _items = new ArrayList<IItem>();

    protected void equipImpl(IItem item){
        this._items.add(item);
    }

    public void use(String itemName){
        for(IItem item : this._items){
            if(item.getName() == itemName){
                item.activate();
                break;
            }
        }
    }
}

public class Worrior extends UserBase {
    public void equip(IWeapon item){
        this.equipImpl(item);
    }
}

public class Wizard extends UserBase {
    public void equip(IPotion item){
        this.equipImpl(item);
    }
}