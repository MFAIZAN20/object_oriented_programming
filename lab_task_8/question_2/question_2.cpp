#include <iostream>
#include <string>
using namespace std;
class Employee
{
private:
    string Emp_Name;
    int work_hour;
    double hour_rate;
public:
    Employee(string name_emp = " "){
        setEmp_name(name_emp);
    }
    
    /* Setter For Employee*/
    void setEmp_name(string name)
    {
        if (!name.empty())
        {
            Emp_Name=name;
        }
        else{
            Emp_Name="Noname";
        }
    }
    void setEmp_work_hour(double w_hour){
        
        if (w_hour >= 0)
        {
            work_hour = w_hour;
        }
        else
        {
        work_hour = 0;
        }
    }
    void setEmp_hour_rate(int r_hour)
    {
        if (r_hour >= 0)
        {
            hour_rate = r_hour;
        }
        else
        {
            hour_rate = 0;
        }
    }

    /* Getter For The Base Class */
    string get_name(){
        return Emp_Name;
    }
    double get_hour_rate()
    {
        return hour_rate;
    }

    int get_hour_work()
    {
        return work_hour;
    }

    double calculate()
    {    
        return 0;
    }
};
class hourly_emp:public Employee
{
    double salary;
    public:
        /* Constructor */
        hourly_emp(double sal = 0.0){
            setEmp_salary(sal);
        }
        /* Setter */
    void setEmp_salary(double salr){
        if (salr >= 0)
        {
            salary = salr;
        }
        else
        {
            salary = 0;
        }
    }
    /* Getters */
    double getEmp_salary(){
        return salary;
    }
    void calculate(){
        int h_rate,num_hour,total_sal;

        total_sal=h_rate*num_hour;
        setEmp_salary(total_sal);
    }
};
    
    
class salaried_emp:public Employee{
    double salaray;
    double annual_sal;
    public:
        /* Constructor */
        salaried_emp(double sala = 0.0,double annual = 0){
            setEmp_salaray(sala);
            setEmp_annual(annual);
        }
        /* Setter */
    void setEmp_salaray(double salra){        
        salaray = salra;
    }
    void setEmp_annual(double sal){
        if (sal >= 0)
        {
            annual_sal = sal;
        }
        else
        {
            annual_sal = 0;
        }
    }
    /* Getters */
    double getEmp_salaray(){
        return salaray;
    }
    double getEmp_annual(){
        return annual_sal;
    }

    /* Main Functions */
    void calculate(){
        double An_Sal,Total_Sal;
    An_Sal = getEmp_annual();
    Total_Sal=An_Sal/12;    
    setEmp_salaray(Total_Sal);
    }


}; 
int main(){
    string name;
    double hour_rate;
    int hour_work;
    
    Employee emp_obj;
    hourly_emp hourly_obj;
    salaried_emp salaried_obj;

    cout<<"Please Enter Employee Name "<<endl;
    getline(cin,name);
    emp_obj.setEmp_name(name);

    cout<<"PLease Enter The Hourly Rate For The Employee"<<endl;
    cin>>hour_rate;
    emp_obj.setEmp_hour_rate(hour_rate);

    cout<<"PLease Enter The Number Worked For The Employee"<<endl;
    cin>>hour_work;
    emp_obj.setEmp_work_hour(hour_work);

    cout<<"Choose An Option \n\t 1. To Show The Hourly Detail \n\t 2. To Show The Salried Detail \n\t 3. Exit Form Program"<<endl;
    int choose;

    while (choose !=3)
    {
        cin>>choose;
        switch (choose)
        {
        case 1:
            cout<<"The Name OF Employee is :"<<emp_obj.get_name()<<endl;
            cout<<"The Houly rate is : "<<emp_obj.get_hour_rate()<<"$"<<endl;
            cout<<"The Number Of Hour Worked By Employee is :"<<emp_obj.get_hour_work();
            break;
        case 2:
        int anual_Sal;
            cout<<"Please Enter The Total Annual Salary"<<endl;
            cin>>anual_Sal;
            salaried_obj.setEmp_annual(anual_Sal);
            salaried_obj.calculate();
            cout<<"The Name OF Employee is :"<<emp_obj.get_name()<<endl;
            cout<<"The Monthly Salaray For Employee is :"<<salaried_obj.getEmp_salaray();
            break;
        }
    }
    
    return 0;
}