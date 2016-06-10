package student_grade;

public class male extends student {
	
	public male() {
		// TODO Auto-generated constructor stub
	}
	public male(String name,float quiz,float midterm,float project,float final_exam){
		
		
		super(name,quiz,midterm,project,final_exam);
	}
	
	public float total_marks(){
		
		float q = (quiz*25)/100;
		float mid = (midterm*25)/100;
		float pro = (project*25)/100;
		float f_exam = (final_exam*25)/100;
		
		return q+mid+pro+f_exam;
	}
	public char get_grade(float sum){

    if(sum >=90)
    	return 'A';
    else if(sum >=80 && sum <90)
    	return 'B';
    else if(sum >=70 && sum <80)
    	return 'C';
    else if(sum >=60 && sum <70)
    	return 'D';
    else
    	return 'F';
	}
	public void show(){
	
	System.out.println("ID\t\tNAME\t\tQIUZ\tMIDTERM\tPROJECT\tFINAL\tGRADE");
	System.out.println("--\t\t----\t\t----\t-------\t-------\t-----\t-----");
	System.out.printf(getId()+"\t\t"+name+"\t\t"+quiz+"\t"+midterm+"\t"+project+"\t"+final_exam+"\t"+get_grade(total_marks()));
	//System.out.println(total_marks());
	}
}
