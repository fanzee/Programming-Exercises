import java.awt.*;

public class Wall {

    int x;
    int y;
    int width;
    int height;
    TanksClient tc;

    public Wall(int x, int y, int width, int height,TanksClient tc) {
        this.x = x;
        this.y = y;
        this.width = width;
        this.height = height;
        this.tc = tc;
    }

    public void drawWall(Graphics g){
        Color c = g.getColor();
        g.setColor(new Color(235,237,244));
        g.fillRect(x,y,width,height);
        g.setColor(c);
    }

    public Rectangle getRectangle(){
        return new Rectangle(x,y,width,height);
    }

}
