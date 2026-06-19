package Package1;

public class Student {// Student类：储存学生基础信息
  private String id;
  private String name;
  private int age;
  private String major;
  private String cLass;
  private String preferSubject;

  public Student(String id, String name, int age, String major, String cLass, String preferSubject) {// Student类的构造方法
    this.id = id;
    this.name = name;
    this.age = age;
    this.major = major;
    this.cLass = cLass;
    this.preferSubject = preferSubject;
  }

  public String getId() {
    return id;
  }

  public String getName() {
    return name;
  }

  public int getAge() {
    return age;
  }

  public String getMajor() {
    return major;
  }

  public String getcLass() {
    return cLass;
  }

  public String getPreferSubject() {
    return preferSubject;
  }

  public void setId(String id) {
    this.id = id;
  }

  public void setName(String name) {
    this.name = name;
  }

  public void setAge(int age) {
    this.age = age;
  }

  public void setMajor(String major) {
    this.major = major;
  }

  public void setClass(String cLass) {
    this.cLass = cLass;
  }

  public void setPreferSubject(String preferSubject) {
    this.preferSubject = preferSubject;
  }

  @Override
  public String toString() {
    return id + "," + name + "," + age + "," + major + "," + cLass + "," + preferSubject;
  }
}
