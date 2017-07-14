#include <stdio.h>
#include <string.h>

typedef enum E_TYPE {Er=1, Mgr, Dir}E_TYPE;

typedef struct Engineer
{
	char* name_;
}Engineer;
Engineer* InitEngineer(const char* name) {
	Engineer* e = (Engineer*)malloc(sizeof(Engineer));
	e->name_ = strdup(name);
	return e;
}
void processEngSalary(Engineer* e)
{
	printf("%s: Process Salary for Engineer\n",e->name_ );
}


typedef struct Manager
{
	char* name_; Engineer* reports_[10];
}Manager;
Manager* InitManager(const char* name) {
	Manager* m = (Manager*)malloc(sizeof(Manager));
	m->name_ = strdup(name);
	return m;
}
void processMgrSalary(Manager* m) {
	printf("%s: Process Salary for Manager\n",m->name_ );
}

typedef struct Director
{
	char* name_; Manager* reports_[10];
}Director;
Director* InitDirector(const char* name) {
	Director* d = (Director*)malloc(sizeof(Director));
	d->name_ = strdup(name);
	return d;
}
void processDirSalary(Director* d) {
	printf("%s: Process Salary for Director\n",d->name_ );
}

typedef struct Staff {
	E_TYPE type_;
	union {
		Engineer* pE; Manager* pM; Director* pD;
	};
}Staff;

int main()
{
	E_TYPE type;
	int i;
	char name[10];
	Staff allstaff[10];
	/*scanf("%s",&name);
	printf("%s\n",name);
*/
	for(i = 0;i<7;++i)
	{
		printf("Enter the type of employee\n(1--Eng,2--Mgr,3--Dir): " );
		scanf("%d",&type);
		allstaff[i].type_ = type;
		if(type>3) {
            printf("Invalid type! retry\n");
            --i;
            continue;
		}
		printf("Enter the name of the employee: ");
		scanf("%s",&name);
		if(type==Er)
			allstaff[i].pE = InitEngineer(name);
		else if(type==Mgr)
			allstaff[i].pM = InitManager(name);
		else if(type==Dir)
			allstaff[i].pD = InitDirector(name);
        else {
            printf("Invalid type! retry\n");
            --i;
        }
	}
    printf("\n");
	for(i = 0;i<7;++i) {
		E_TYPE t = allstaff[i].type_;
		if(t==Er) processEngSalary(allstaff[i].pE);
		else if(t==Mgr) processMgrSalary(allstaff[i].pM);
		else processDirSalary(allstaff[i].pD);
	}
	return 0;
}
