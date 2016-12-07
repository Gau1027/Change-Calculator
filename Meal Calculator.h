// Gordon Upshaw
// Computational Problem Solving 1 CPET
// March 3 2015
//Lab 6
// Title: Change Calculator


#include <iostream>


#include <iomanip>


using namespace std;






double gettax (double m, double st)  //Function for calculating tax
{
double tax;
tax=m*(st/100.0);
return (tax); // Returns tax too main
}
void change (double& mealtotal, double amountpaid, double change)
{
change= amountpaid-mealtotal;
} // Function for calculating change


void tipcalc (double m,double& t15,double& t18, double& t20) //Tip percent calculations
{ t15= (m*0.15);
t18= (m*0.18);
t20 =(m*0.20);
}


void changebackcalc (double& changedue, int& twenties, int& tens, int& fives, int& ones, int& quarters, int& dimes, int& nickels, int& pennies )
{
do
{
if (changedue >20) // change function
{
	twenties =changedue/20;
	changedue-=twenties*20;
}
else if ( changedue > 10)
{
	tens = changedue/10;
	changedue-=tens*10;
}
else if (changedue >5)
{
	fives =changedue/5;
	changedue-=fives*5;
}
else if (changedue >= 1)
{
	ones= changedue/1;
	changedue-=ones*1;
}
else if (changedue >=.25)
{
quarters = changedue/.25;
changedue-=quarters*.25;
}
else if (changedue >= .10)
{
	dimes=changedue/.10;
	changedue-=dimes*.10;
}
else if (changedue >=.05)
{
	nickels =changedue/.05;
	changedue-=nickels*.05;
}
else if (changedue >=.01)
{
	pennies = changedue/.01;
	changedue-=pennies*.01;
}


}
while (changedue>.01);
}




int main (void) // main function
{ // Varaibles
double meal;
double salestax;
double taxamt;
double t15,t18,t20;
double totalbill;;
double tb15;
double tb18;
double tb20;
double amtpaid;
double changedue=0;
double changedueback=0;
int twenties=0;
int tens=0;
int fives=0;
int ones=0;
int quarters=0;
int dimes=0;
int nickels=0;
int pennies=0;
cout << "Enter in the price of the meal\n" <<endl;
cin >> meal;
cout << "Enter in the sales tax (2.8-14 ONLY)\n" <<endl;
cin >>salestax;
if (salestax<2.8||salestax>14)
	cout << "DO NOT ENTER A VALUE UNDER 2.8 OR 14 WRONG VALUES BELOW DO NOT USE" <<endl;
cout << "Sales tax is"  << salestax;
taxamt=gettax (meal,salestax);
cout << "The tax amount is\n "<< taxamt << endl;
tipcalc (meal, t15,t18,t20);
cout << "15% tip is\n" << std::setprecision(2) << fixed << t15 << endl;
cout << "18% tip is\n" << std::setprecision(2) << fixed << t18 << endl; 
cout << "20% tip is\n"<< std::setprecision(2) << fixed << t20 << endl;
//Tip percents


totalbill=taxamt+meal;
cout << "The Total Bill is\n "  << std::setprecision(2) << fixed << totalbill << "$" << endl;
tb15=totalbill+t15;
cout << "The Total Bill with 15% tip is\n"  << std::setprecision(2) << fixed <<tb15 << "$" << endl;
tb18=totalbill+t18;
cout << "The Total Bill with 18% tip is\n"   << std::setprecision(2) << fixed  <<tb18<<"$" << endl; //Tip Percent calculations with total bill
tb20=totalbill+t20;
cout << "The Total Bill with 20% tip is\n "  << std::setprecision(2) << fixed <<tb20<< "$"<< endl;


cout << "Enter in amount paid\n" <<endl;


cin>>amtpaid;
cout << "The amount paid is\n" << amtpaid;
change (totalbill,amtpaid,changedue);
changedue = amtpaid-totalbill;
cout << "The change due is" << changedue << endl;
changebackcalc (changedue,twenties,tens,fives,ones,quarters,dimes,nickels,pennies);
cout << "Twenties due back\n" <<twenties << endl;
cout << "Tens due back\n" <<tens << endl;
cout << "Fives due back\n" << fives << endl;
cout << " Ones due back\n" << ones << endl;
cout << " Quarters due back\n" <<quarters << endl; // Calculations for change from function
cout << " Dimes due back\n" << dimes << endl;
cout << " Nickles due back\n" << nickels << endl;
cout << " Pennies due back\n" << pennies<<  setprecision(2) << endl;
system ("pause");
return 0;
}