package Package1;

import java.io.*;
import java.util.*;

public class StudentManage {
  private static final String FILE_PATH = "Students.txt";
  private List<Student> studentList;

  public StudentManage() {
    studentList = new ArrayList<>();
    loadFromFile();
  }

  public List<Student> getStudentList() {
    return Collections.unmodifiableList(studentList);
  }

  public void loadFromFile() {// 读取数据
    File file = new File(FILE_PATH);
    if (!file.exists()) {
      try {
        file.createNewFile();
      } catch (Exception e) {
        e.printStackTrace();
      }
      return;
    }

    try (BufferedReader br = new BufferedReader(new FileReader(file))) {
      String line;
      while ((line = br.readLine()) != null) {
        String[] parts = line.split(",");
        if (parts.length == 6) {
          String id = parts[0].trim();
          String name = parts[1].trim();
          String ageStr = parts[2].trim();
          String major = parts[3].trim();
          String cLass = parts[4].trim();
          String preferSubject = parts[5].trim();
          int age = Integer.parseInt(ageStr);
          Student student = new Student(id, name, age, major, cLass, preferSubject);
          studentList.add(student);
        }
      }
    } catch (Exception e) {
      e.printStackTrace();
    }
  }

  public boolean saveToFile() {// 保存数据
    try (BufferedWriter bw = new BufferedWriter(new FileWriter(FILE_PATH))) {
      bw.write("学号，名字，年龄，专业，班级，偏爱学科");
      bw.newLine();
      for (Student s : studentList) {
        bw.write(s.toString());
        bw.newLine();
      }
      return true;
    } catch (IOException e) {
      e.printStackTrace();
      return false;
    }
  }

  public boolean addStudent(Student student) {
    for (Student s : studentList) {
      if (s.getId().equals(student.getId())) {
        return false;// 学号重复
      }
    }
    studentList.add(student);
    return saveToFile();
  }

  public boolean updateStudent(String oldId, Student student) {
    if (!oldId.equals(student.getId())) {
      for (Student s : studentList) {
        if (s.getId().equals(student.getId())) {
          return false;
        }
      }
    }

    for (int i = 0; i < studentList.size(); i++) {
      if (oldId.equals(studentList.get(i).getId())) {
        studentList.set(i, student);
        return saveToFile();
      }
    }
    return false;
  }

  public List<Student> searchStudent(String index) {// 通过学号搜索学生
    List<Student> result = new ArrayList<>();

    for (Student s : studentList) {
      if (s.getId().contains(index) || s.getName().contains(index)) {
        result.add(s);
      }
    }
    return result;
  }

  public boolean deleteStudent(String id) {// 通过学号找到学生并删除
    for (int i = 0; i < studentList.size(); i++) {
      if (studentList.get(i).getId().equals(id)) {
        studentList.remove(i);
        return saveToFile();
      }
    }
    return false;
  }

}
