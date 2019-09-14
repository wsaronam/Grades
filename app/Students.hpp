#ifndef STUDENTS_CPP
#define STUDENTS_CPP


struct Student
{
	unsigned int id;
	char GradeOption;
	std::string name;
	double TotalScore;
};


int GetNumOfStudents();
void BuildStudentArray(Student* Array, unsigned int NumOfStudents);



#endif  // STUDENTS_CPP