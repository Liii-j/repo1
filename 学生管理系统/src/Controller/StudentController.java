package Controller;

import Package1.*;
import StudentSystemSwing.*;

import java.util.List;

public class StudentController {
  private StudentManage studentManage;

  private StudentView mainSwing;

  public StudentController(StudentManage studentManage, StudentView studentView) {
    this.studentManage = studentManage;
    this.mainSwing = studentView;

    registerListeners();
    mainSwing.loadTableData(studentManage.getStudentList());
  }

  private void registerListeners() {//按钮事件监听
    mainSwing.addbtn.addActionListener(e -> openInputView());
    mainSwing.updatebtn.addActionListener(e -> openUpdateView());
    mainSwing.searchbtn.addActionListener(e -> dealSearchbtn());
    mainSwing.deletbtn.addActionListener(e->dealDeletebtn());
    mainSwing.viewbtn.addActionListener(e->{
            mainSwing.loadTableData(studentManage.getStudentList());
      mainSwing.showMessage("已显示所有学生信息！");});
  }

  private void openInputView() {//添加按钮
    InputView inputView = new InputView(mainSwing);
    //保存按钮
    inputView.confirmbtn.addActionListener(e -> {
      Student student = inputView.getInputStudent();
      if (student == null) {
        mainSwing.showMessage("输入不合法！");
        return;
      }
      if (studentManage.addStudent(student)) {
        mainSwing.showMessage("添加成功！");
        mainSwing.loadTableData(studentManage.getStudentList());
        inputView.dispose();//关闭窗口
      } else {
        mainSwing.showMessage("添加失败!该学号已存在");
      }
    });
    //取消按钮
    inputView.cancelbtn.addActionListener(e -> inputView.dispose());

    inputView.setVisible(true);
  }

  private void openUpdateView() {//修改按钮
    Student oldStudent = mainSwing.getSelectStudent();
    if (oldStudent == null) {
      mainSwing.showMessage("请先在表格选中要修改的学生!");
      return;
    }

    UpdateView updateView = new UpdateView(mainSwing, oldStudent);

    updateView.confirmbtn.addActionListener(e -> {
      Student newStudent = updateView.getUpdatedStudent();
      if (newStudent == null) {
        mainSwing.showMessage("输入不合法！");
        return;
      }
      if (studentManage.updateStudent(updateView.getOldId(), updateView.getUpdatedStudent())) {
        mainSwing.showMessage("修改成功！");
        mainSwing.loadTableData(studentManage.getStudentList());
        updateView.dispose();
      } else {
        mainSwing.showMessage("修改失败！新学号已存在");
      }
    });

    updateView.cancelbtn.addActionListener(e -> updateView.dispose());

    updateView.setVisible(true);
  }

  private void dealSearchbtn() {//搜索按钮
    String index = mainSwing.getSearchKeybord();
if(index.isEmpty()){
  mainSwing.showMessage("请输入要搜索的学号/姓名");
  return;
}

    List<Student> student=studentManage.searchStudent(index);
if(student.isEmpty()){
  mainSwing.loadTableData(student);
  mainSwing.showMessage("未找到学生"+index);
}else {
 mainSwing.loadTableData(student);
  mainSwing.showMessage("已找到"+student.size()+"条匹配记录");
}
mainSwing.clearSearchInput();
  }

  private void dealDeletebtn(){//删除按钮
    Student oldstudent=mainSwing.getSelectStudent();
    if(oldstudent==null){
      mainSwing.showMessage("请先在表格选择要删除的学生！");
      return;
    }

    if(studentManage.deleteStudent(oldstudent.getId())){
      mainSwing.loadTableData(studentManage.getStudentList());
      mainSwing.showMessage("删除成功！");
    }else{
      mainSwing.showMessage("删除失败！");
    }
  }
}