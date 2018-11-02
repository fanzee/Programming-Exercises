package jdbc;

import org.junit.Test;

public class testJDBC {

    @Test
    public void query() {
        DAO dao = new DAOImpl();
        dao.query();
    }

    @Test
    public void insert() {
        DAO dao = new DAOImpl();
        dao.insert();
    }

    @Test
    public void delete() {
        DAO dao = new DAOImpl();
        dao.delete();
    }

    @Test
    public void update() {
        DAO dao = new DAOImpl();
        dao.update();
    }

}
