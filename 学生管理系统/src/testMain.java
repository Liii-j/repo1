import Package1.*;
import Controller.*;
import StudentSystemSwing.*;

public class testMain {
    public static void main(String[] args) {
        javax.swing.SwingUtilities.invokeLater(new Runnable() {
            @Override
            public void run() {
                StudentView view = new StudentView();
                StudentManage manager = new StudentManage();
                new StudentController(manager,view);
                view.setVisible(true); // 显示界面
            }
        });
    }
}
