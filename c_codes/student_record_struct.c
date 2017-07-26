#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student_details {
	char name[20];
	unsigned int join_year;
	char gender;
}student_record;

student_record* find_specific(student_record*,int,int);

int main() {
	int number_of_records;
	int operator_num;
	int i;

	student_record* students;
	student_record* student_of_interest;

	scanf("%d",&number_of_records);

	students = (student_record*)malloc(number_of_records*sizeof(student_record));

	for(i = 0;i < number_of_records;i++) {
            //printf("%d\n",i);
		scanf("%s %d %c",students[i].name,&students[i].join_year,&students[i].gender);
	}

	/*for(i = 0;i < number_of_records;i++) {
		printf("%s %d %c\n",students[i].name,students[i].join_year,students[i].gender);
	}
*/
	scanf("%d",&operator_num);
	if(operator_num!=1&&operator_num!=2) return -1;
	student_of_interest = find_specific(students, operator_num, number_of_records);

	printf("%s %d %c\n",student_of_interest->name,student_of_interest->join_year,student_of_interest->gender);

	return 0;

}

student_record* find_specific(student_record* local_cpy, int op_num, int size) {
	int i;
	student_record* return_cpy;

	return_cpy = local_cpy;

	for(i=0;i<size;i++) {
		if(op_num==1) {
			if(strcmp(return_cpy->name,local_cpy[i].name)>0) {
				return_cpy = local_cpy+i;
			}
		}
		else {
			if(return_cpy->join_year>local_cpy[i].join_year) {
				return_cpy = local_cpy + i;
			}
		}
	}

	return return_cpy;
}
