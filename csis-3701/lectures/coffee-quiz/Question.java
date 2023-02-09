public class Question {
		
	private String text;
	private int number;
	private int correctChoiceIdx;
	private String[] choices = new String[4];
	
	public Question (String t, int n, int c) throws Exception {
		
		setText(t);
		setNumber(n);
		setCorrectChoiceIdx(c);
			
	}

	public void setChoices(String T0, String T1 ,String T2, String T3 ) throws Exception {

		checkChoice(T0);
		checkChoice(T1);
		checkChoice(T2);
		checkChoice(T3);
		
		choices[0] = T0;
		choices[1] = T1;
		choices[2] = T2;
		choices[3] = T3;
	}

	public String getText() {
		return text;
	}
	
	public void setText(String text) throws Exception {
		if ( (!text.equals(null) ) && (!text.equals("") ) ) {
			this.text = text;
		}else{
			throw new Exception("Invalid question text");
		}
	}
	
	public int getNumber() {
		return number;
	}
	
	public void setNumber(int number) throws Exception {
		if ( (number>=1) && (number<=5) ) {
			this.number = number;
		}else {
			throw new Exception("Invalid number - Number must be between 1-5");
		}
	}
	
	public int getCorrectChoiceIdx() {
		return this.correctChoiceIdx;
	}
	
	public void setCorrectChoiceIdx(int correctChoiceIdx) throws Exception {
		if ((correctChoiceIdx>=0) && (correctChoiceIdx<=3)) {
			this.correctChoiceIdx = correctChoiceIdx;
		}else{
			throw new Exception("Invalid choice - Number must be between 0-3");
		}
	}
	
	public void checkChoice(String T) throws Exception {
		if ( (T.equals(null) ) && (T.equals("") ) ) {
	
	   throw new Exception("Invalid answer text");	
	}
	}
		   
	public void printAnswers() {
		for(int i=0; i<4; i++) {
			System.out.println( "   " + (i+1) + ". " + this.choices[i] );
	}
	}

	public boolean isCorrectAnswer(Player p) {

		if( this.getCorrectChoiceIdx() == p.getPlayerAnswer(this.getNumber() ) ){
			System.out.println( "Question " + (this.getNumber()) + ": Great Job!");
			return true;
		}else{
			System.out.println( "Question " + (this.getNumber()) + ": Sorry, wrong answer.");
			return false;
	  }
	}
}
