import java.awt.*;
import java.awt.event.KeyEvent;
import java.util.HashMap;
import java.util.Map;
import java.util.Random;

public class Tanks {

    public static final int X_SPEED = 5;
    public static final int Y_SPEED = 5;
    public static final int WIDTH = 50;
    public static final int HEIGHT = 50;

    private int x;
    private int y;
    private int lastX;
    private int lastY;
    private int life = 100;
    private int tankStep = random.nextInt(20)+5;

    private boolean up = false;
    private boolean down = false;
    private boolean left = false;
    private boolean right = false;
    private boolean live = true;
    private boolean good;

    private static Random random = new Random();
    private ShowBlood showBlood = new ShowBlood();

    TanksClient tc;

    private Direction direction = Direction.STOP;
    private Direction bulletDirection = Direction.D;

    private static Toolkit tk = Toolkit.getDefaultToolkit();
    private static Map<String,Image> imgs = new HashMap();
    private static Image[] tankImgs = null;
    static {
        tankImgs = new Image[]{
            tk.getImage(Tanks.class.getClassLoader().getResource("images/tankU.png")),
            tk.getImage(Tanks.class.getClassLoader().getResource("images/tankD.png")),
            tk.getImage(Tanks.class.getClassLoader().getResource("images/tankL.png")),
            tk.getImage(Tanks.class.getClassLoader().getResource("images/tankR.png")),
            tk.getImage(Tanks.class.getClassLoader().getResource("images/tankLU.png")),
            tk.getImage(Tanks.class.getClassLoader().getResource("images/tankRU.png")),
            tk.getImage(Tanks.class.getClassLoader().getResource("images/tankLD.png")),
            tk.getImage(Tanks.class.getClassLoader().getResource("images/tankRD.png"))
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

    public Tanks(int x, int y, boolean good) {
        this.x = x;
        this.y = y;
        this.lastX = x;
        this.lastX = y;
        this.good = good;
    }

    public Tanks(int x,int y,boolean good,Direction direction,TanksClient tc){
        this(x,y,good);
        this.direction=direction;
        this.tc = tc;
    }

    public boolean isLive() {
        return live;
    }

    public void setLive(boolean live) {
        this.live = live;
    }

    public boolean isGood(){
        return good;
    }

    public int getLife() {
        return life;
    }

    public void setLife(int life) {
        this.life = life;
    }

    void moveTank(){

        this.lastX = x;
        this.lastY = y;

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
            case STOP:
                break;
        }
        if(this.direction != Direction.STOP){
            this.bulletDirection = this.direction;
        }

        if(x < 0)
            x = 0;
        if(y < 40)
            y = 40;
        if(x+Tanks.WIDTH > TanksClient.FRAME_WIDTH)
            x=TanksClient.FRAME_WIDTH-Tanks.WIDTH;
        if(y+Tanks.HEIGHT > TanksClient.FRAME_HEIGHT)
            y=TanksClient.FRAME_HEIGHT-Tanks.HEIGHT;

        if(!good){
            Direction[] directions = Direction.values();
            if(tankStep == 0){
                tankStep = random.nextInt(20)+5;
                int randomNumber = random.nextInt(directions.length);
                direction = directions[randomNumber];
            }
            tankStep--;
            if(random.nextInt(100) > 90) {
                this.fire();
            }
        }
    }

    public void drawTank(Graphics g){
        if(!live){
            if(!good){
                tc.tanks.remove(this);
            }
            return;
        }

        if(good) {
            showBlood.drawBlood(g);
        }
        switch (bulletDirection){
            case U:
                g.drawImage(imgs.get("U"),x,y,null);
                break;
            case D:
                g.drawImage(imgs.get("D"),x,y,null);
                break;
            case L:
                g.drawImage(imgs.get("L"),x,y,null);
                break;
            case R:
                g.drawImage(imgs.get("R"),x,y,null);
                break;
            case LU:
                g.drawImage(imgs.get("LU"),x,y,null);
                break;
            case LD:
                g.drawImage(imgs.get("LD"),x,y,null);
                break;
            case RU:
                g.drawImage(imgs.get("RU"),x,y,null);
                break;
            case RD:
                g.drawImage(imgs.get("RD"),x,y,null);
                break;
        }
        moveTank();
    }

    public void keyPressed(KeyEvent e) {
        int key = e.getKeyCode();
        switch (key){
            case KeyEvent.VK_UP :
                up = true;
                break;
            case KeyEvent.VK_DOWN :
                down = true;
                break;
            case KeyEvent.VK_LEFT :
                left = true;
                break;
            case KeyEvent.VK_RIGHT:
                right = true;
                break;
            case KeyEvent.VK_F1:
               if(!this.live){
                   this.live = true;
                   this.life = 100;
               }
                break;
        }
        actualDirection();
    }

    void  actualDirection(){
        if(left  && !up && !right && !down)
            direction = Direction.L;
        else if(left  && up && !right && !down)
            direction = Direction.LU;
        else if(left  && !up && !right && down)
            direction = Direction.LD;
        else if(!left  && !up && right && !down)
            direction = Direction.R;
        else if(!left  && up && right && !down)
            direction = Direction.RU;
        else if(!left  && !up && right && down)
            direction = Direction.RD;
        else if(!left  && up && !right && !down)
            direction = Direction.U;
        else if(!left  && !up && !right && down)
            direction = Direction.D;
        else if(!left  && !up && !right && !down)
            direction = Direction.STOP;
    }

    public void keyReleased(KeyEvent e) {
        int key = e.getKeyCode();
        switch (key){
            case KeyEvent.VK_SPACE:
                fire();
                break;
            case KeyEvent.VK_CONTROL:
                crazyFire();
                break;
            case KeyEvent.VK_UP :
                up = false;
                break;
            case KeyEvent.VK_DOWN :
                down = false;
                break;
            case KeyEvent.VK_LEFT :
                left = false;
                break;
            case KeyEvent.VK_RIGHT:
                right = false;
                break;
        }
        actualDirection();
    }

    public Bullet fire(){
        if(!live){
            return null;
        }
        int x = this.x + Tanks.WIDTH/2 - Bullet.WIDTH/2;
        int y = this.y + Tanks.HEIGHT/2 - Bullet.HEIGHT/2;
        Bullet bullet = new Bullet(x,y,good,bulletDirection,this.tc);
        tc.bullets.add(bullet);
        return bullet;
    }

    public Bullet fire(Direction dir){
        if(!live){
            return null;
        }
        int x = this.x + Tanks.WIDTH/2 - Bullet.WIDTH/2;
        int y = this.y + Tanks.HEIGHT/2 - Bullet.HEIGHT/2;
        Bullet bullet = new Bullet(x,y,good,dir,this.tc);
        tc.bullets.add(bullet);
        return bullet;
    }

    public Rectangle getRectangle(){
        return  new Rectangle(x,y,tankImgs[0].getWidth(null),tankImgs[0].getHeight(null));
    }

    private void stay(){
        x = lastX;
        y = lastY;
    }

    private void crazyFire(){
        Direction[] directions = Direction.values();
        for(int i=0;i<directions.length-1;i++){
            fire(directions[i]);
        }
    }

    public boolean hitWall(Wall w){
        if(this.live && this.getRectangle().intersects(w.getRectangle())){
            this.stay();
            return true;
        }
        return false;
    }
    private class ShowBlood{
        public void drawBlood(Graphics g){
            Color c = g.getColor();
            g.setColor(Color.RED);
            g.drawRect(x,y-10,WIDTH,5);
            int width = WIDTH * life / 100;
            g.fillRect(x,y-10,width,5);
            g.setColor(c);
        }
    }

}