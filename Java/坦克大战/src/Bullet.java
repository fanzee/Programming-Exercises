import java.awt.*;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class Bullet {

    public static final int X_SPEED = 10;
    public static final int Y_SPEED = 10;
    public static final int WIDTH = 10;
    public static final int HEIGHT = 10;

    private boolean bulletLive = true;
    private boolean good;

    int x;
    int y;

    Direction direction;

    private TanksClient tc;

    private static Toolkit tk = Toolkit.getDefaultToolkit();
    private static Map<String,Image> imgs = new HashMap();
    private static Image[] tankImgs = null;
    static {
        tankImgs = new Image[]{
                tk.getImage(Bullet.class.getClassLoader().getResource("images/子弹U.png")),
                tk.getImage(Bullet.class.getClassLoader().getResource("images/子弹D.png")),
                tk.getImage(Bullet.class.getClassLoader().getResource("images/子弹L.png")),
                tk.getImage(Bullet.class.getClassLoader().getResource("images/子弹R.png")),
                tk.getImage(Bullet.class.getClassLoader().getResource("images/子弹LU.png")),
                tk.getImage(Bullet.class.getClassLoader().getResource("images/子弹RU.png")),
                tk.getImage(Bullet.class.getClassLoader().getResource("images/子弹LD.png")),
                tk.getImage(Bullet.class.getClassLoader().getResource("images/子弹RD.png"))
        };
        imgs.put("U",tankImgs[0]);
        imgs.put("D",tankImgs[1]);
        imgs.put("L",tankImgs[2]);
        imgs.put("R",tankImgs[3]);
        imgs.put("LU",tankImgs[4]);
        imgs.put("RU",tankImgs[5]);
        imgs.put("LD",tankImgs[6]);
        imgs.put("RD",tankImgs[7]);
    }

    public Bullet(int x, int y, Direction direction) {
        this.x = x;
        this.y = y;
        this.direction = direction;
    }

    public Bullet(int x, int y, boolean good, Direction direction, TanksClient tc) {
        this(x,y,direction);
        this.good = good;
        this.tc = tc;
    }

    public void drawBullet(Graphics g){
        if(bulletLive == false){
            tc.bullets.remove(this);
            return;
        }
        switch (direction) {
            case U:
                g.drawImage(imgs.get("U"), x, y, null);
                break;
            case D:
                g.drawImage(imgs.get("D"), x, y, null);
                break;
            case L:
                g.drawImage(imgs.get("L"), x, y, null);
                break;
            case R:
                g.drawImage(imgs.get("R"), x, y, null);
                break;
            case LU:
                g.drawImage(imgs.get("LU"), x, y, null);
                break;
            case LD:
                g.drawImage(imgs.get("LD"), x, y, null);
                break;
            case RU:
                g.drawImage(imgs.get("RU"), x, y, null);
                break;
            case RD:
                g.drawImage(imgs.get("RD"), x, y, null);
                break;
        }
        moveBullet();
    }

    private void moveBullet() {
        switch (direction){
            case U:
                y -= Y_SPEED;
                break;
            case D:
                y += Y_SPEED;
                break;
            case L:
                x -= X_SPEED;
                break;
            case R:
                x += X_SPEED;
                break;
            case LU:
                x -= X_SPEED;
                y -= Y_SPEED;
                break;
            case LD:
                x -= X_SPEED;
                y += Y_SPEED;
                break;
            case RU:
                x += X_SPEED;
                y -= Y_SPEED;
                break;
            case RD:
                x += X_SPEED;
                y += Y_SPEED;
                break;
        }
        if( x < 0 || y < 0 || x > TanksClient.FRAME_WIDTH || y > TanksClient.FRAME_HEIGHT ){
            bulletLive = false;
        }
    }

    public Rectangle getRectangle(){
        return  new Rectangle(x,y,WIDTH,HEIGHT);
    }

    public boolean destroyTank(Tanks t){
        if(this.bulletLive && this.getRectangle().intersects(t.getRectangle()) && t.isLive() && this.good!=t.isGood()){
            if(t.isGood()){
                t.setLife(t.getLife()-20);
                if(t.getLife() <= 0){
                    t.setLive(false);
                }
            }
            else {
                t.setLive(false);
            }
            this.bulletLive = false;
            Explode e = new Explode(x,y,tc);
            tc.explodes.add(e);
            return true;
        }
        return false;
    }

    public boolean destroyTanks(List<Tanks> tanks){
        for(int i = 0;i<tanks.size();i++){
            if(destroyTank(tanks.get(i))){
                return true;
            }
        }
        return false;
    }

    public boolean hitWall(Wall w){
        if(this.bulletLive && this.getRectangle().intersects(w.getRectangle())){
            this.bulletLive = false;
            return true;
        }
        return false;
    }

}