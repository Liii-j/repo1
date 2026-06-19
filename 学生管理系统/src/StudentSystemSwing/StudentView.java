package StudentSystemSwing;

import java.util.List;
import java.awt.*;
import javax.swing.*;
import javax.swing.table.DefaultTableModel;

import Package1.Student;

public class StudentView extends JFrame {

  // 表格组件（展示学生列表）
  private DefaultTableModel tableModel;
  private JTable studentTable;

  private JTextField searchField = new JTextField(10);

  // 按钮组件
  public JLabel searchLabel = new JLabel("学号/姓名");
  public JButton searchbtn = new JButton("查询");
  public JButton addbtn = new JButton("添加");
  public JButton deletbtn = new JButton("删除");
  public JButton updatebtn = new JButton("修改");
  public JButton viewbtn = new JButton("浏览");

  public StudentView() {
    initFrame();
    initComponents();
  }

  // 初始化界面
  private void initFrame() {
    // 窗口配置
    setTitle("学生信息管理系统");
    setSize(1000, 600);
    setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    setLocationRelativeTo(null);
    setLayout(new BorderLayout());
  }

  private void initComponents() {
    // 顶部操作面板
    JPanel topPanel = new JPanel(new BorderLayout(10, 10));

    JPanel searchPanel = new JPanel(new FlowLayout(FlowLayout.LEFT, 10, 20));
    searchPanel.add(searchLabel);
    searchPanel.add(searchField);
    searchPanel.add(searchbtn);

    searchLabel.setFont(new Font("微软雅黑", Font.PLAIN, 17));
    searchField.setFont(new Font("微软雅黑", Font.PLAIN, 17));
    searchbtn.setFont(new Font("微软雅黑", Font.PLAIN, 17));

    JPanel btnPanel = new JPanel(new FlowLayout(FlowLayout.RIGHT, 20, 20));
    btnPanel.add(addbtn);
    btnPanel.add(deletbtn);
    btnPanel.add(updatebtn);
    btnPanel.add(viewbtn);

    addbtn.setFont(new Font("微软雅黑", Font.PLAIN, 17));
    deletbtn.setFont(new Font("微软雅黑", Font.PLAIN, 17));
    updatebtn.setFont(new Font("微软雅黑", Font.PLAIN, 17));
    viewbtn.setFont(new Font("微软雅黑", Font.PLAIN, 17));

    topPanel.add(searchPanel, BorderLayout.WEST);
    topPanel.add(btnPanel, BorderLayout.EAST);
    add(topPanel, BorderLayout.NORTH);

    // 中间操作面板
    String[] columnNames = { "学号", "姓名", "年龄", "专业", "班级", "偏爱学科" };
    tableModel = new DefaultTableModel(columnNames, 0) {
      @Override
      public boolean isCellEditable(int row, int column) {
        return false;
      }
    };
    studentTable = new JTable(tableModel);

    studentTable.setFont(new Font("微软雅黑", Font.PLAIN, 17));
    studentTable.setRowHeight(28);

    JScrollPane scrollPane = new JScrollPane(studentTable);
    add(scrollPane, BorderLayout.CENTER);

  }

  public void loadTableData(List<Student> studentList) {
    tableModel.setRowCount(0);

    for (Student st : studentList) {
      Object[] rowdata = {
          st.getId(),
          st.getName(),
          st.getAge(),
          st.getMajor(),
          st.getcLass(),
          st.getPreferSubject()
      };
      tableModel.addRow(rowdata);
    }
  }

  public Student getSelectStudent() {
    int selectRow = studentTable.getSelectedRow();
    if (selectRow == -1) {
      return null;
    }
    String id = (String) tableModel.getValueAt(selectRow, 0);
    String name = (String) tableModel.getValueAt(selectRow, 1);
    int age = (int) tableModel.getValueAt(selectRow, 2);
    String major = (String) tableModel.getValueAt(selectRow, 3);
    String cLass = (String) tableModel.getValueAt(selectRow, 4);
    String preferSubject = (String) tableModel.getValueAt(selectRow, 5);
    return new Student(id, name, age, major, cLass, preferSubject);
  }

  public void clearSearchInput() {
    searchField.setText("");
  }

  public String getSearchKeybord() {
    return searchField.getText().trim();
  }

  public void showMessage(String msg) {
    JOptionPane.showMessageDialog(this, msg);
  }

}
