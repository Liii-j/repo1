package StudentSystemSwing;

import Package1.Student;
import java.awt.*;
import javax.swing.*;

public class InputView extends JDialog {
  // 输入组件
  private JTextField idField = new JTextField(10);
  private JTextField nameField = new JTextField(10);
  private JTextField ageField = new JTextField(5);
  private JTextField majorField = new JTextField(10);
  private JTextField classField = new JTextField(10);
  private JTextField preferSubjectField = new JTextField(10);

  public JButton confirmbtn = new JButton("保存");
  public JButton cancelbtn = new JButton("取消");

  public InputView(JFrame owner) {
    super(owner, "学生添加", true);
    setSize(430, 450);
    setLocationRelativeTo(owner);
    setDefaultCloseOperation(DISPOSE_ON_CLOSE);

    JPanel inputPanel = new JPanel();
    inputPanel.setLayout(new GridLayout(6, 2, 0, 10));

    JLabel idLabel = new JLabel("学号：");
    idLabel.setHorizontalAlignment(SwingConstants.CENTER);
    idField.setHorizontalAlignment(JTextField.CENTER);
    JLabel nameLabel = new JLabel("姓名：");
    nameLabel.setHorizontalAlignment(SwingConstants.CENTER);
    nameField.setHorizontalAlignment(JTextField.CENTER);
    JLabel ageLabel = new JLabel("年龄:");
    ageLabel.setHorizontalAlignment(SwingConstants.CENTER);
    ageField.setHorizontalAlignment(JTextField.CENTER);
    JLabel majorLabel = new JLabel("专业:");
    majorLabel.setHorizontalAlignment(SwingConstants.CENTER);
    majorField.setHorizontalAlignment(JTextField.CENTER);
    JLabel classLabel = new JLabel("班级:");
    classLabel.setHorizontalAlignment(SwingConstants.CENTER);
    classField.setHorizontalAlignment(JTextField.CENTER);
    JLabel preLabel = new JLabel("偏爱学科:");
    preLabel.setHorizontalAlignment(SwingConstants.CENTER);
    preferSubjectField.setHorizontalAlignment(JTextField.CENTER);

    inputPanel.add(idLabel);
    inputPanel.add(idField);
    inputPanel.add(nameLabel);
    inputPanel.add(nameField);
    inputPanel.add(ageLabel);
    inputPanel.add(ageField);
    inputPanel.add(majorLabel);
    inputPanel.add(majorField);
    inputPanel.add(classLabel);
    inputPanel.add(classField);
    inputPanel.add(preLabel);
    inputPanel.add(preferSubjectField);

    JPanel btnPanel = new JPanel(new FlowLayout(FlowLayout.CENTER, 20, 10));
    btnPanel.add(confirmbtn);
    btnPanel.add(cancelbtn);

    getContentPane().setLayout(new BorderLayout());
    getContentPane().add(inputPanel, BorderLayout.CENTER);
    getContentPane().add(btnPanel, BorderLayout.SOUTH);
  }

  public Student getInputStudent() {
    try {
      String id = idField.getText().trim();
      String name = nameField.getText().trim();
      int age = Integer.parseInt(ageField.getText().trim());
      String major = majorField.getText().trim();
      String cLass = classField.getText().trim();
      String preferSubject = preferSubjectField.getText().trim();
      if (id.isEmpty() || name.isEmpty() || age <= 0 || age >= 100 || major.isEmpty() || cLass.isEmpty()
          || preferSubject.isEmpty()) {
        return null;
      }
      return new Student(id, name, age, major, cLass, preferSubject);
    } catch (Exception E) {
      return null;
    }
  }

  public void clearInput() {
    idField.setText("");
    nameField.setText("");
    ageField.setText("");
    majorField.setText("");
    classField.setText("");
    preferSubjectField.setText("");
  }
}
