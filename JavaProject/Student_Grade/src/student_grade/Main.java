package student_grade;

import java.util.Scanner;

public class Main {
		
	static Scanner input = new Scanner(System.in);
	
	public static void main(String args[]){
		
		String name,id;
		
		float quiz,midterm,project,final_exam;
		
		name = input.nextLine();
		quiz = input.nextFloat();
		midterm = input.nextFloat();
		project = input.nextFloat();
		final_exam = input.nextFloat();
		input.nextLine();
		id = input.nextLine();
		student malestudent = new male(name,quiz,midterm,project,final_exam);
		malestudent.setId(id);
		
		malestudent.show();
	}
	
}
