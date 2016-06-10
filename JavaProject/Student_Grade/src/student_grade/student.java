package student_grade;

public abstract class student {

	public String name;
	public float quiz;
	private String id;
	public float midterm;
	public float project;
	public float final_exam;
	public static String major;
	
	
	public student() {
		// TODO Auto-generated constructor stub
	}
	public student(String name,float quiz,float midterm,float project,float final_exam){
		
		this.name = name;
		this.quiz = quiz;
		this.midterm = midterm;
		this.final_exam = final_exam;
		this.project = project;
	}
	
	public String getId() {
		return id;
	}
	public void setId(String id) {
		this.id = id;
	}
	
	public abstract float total_marks();
	public abstract char get_grade(float sum);
	public abstract void show();
}
