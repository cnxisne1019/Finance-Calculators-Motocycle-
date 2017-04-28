#include <iostream>
#include <iomanip>

using namespace std;

void resultboard(int,int); //generate loan table
float getintr(int);	//get interest rate by down rate
int totalpay (int, int, float);	//total payment calcucator
int totalintr (int ,int ,float);	//total interst calculator
int paymonth (int, int, float);	//payment per month
int calc(int, int, float, float);	// main calculator
int main (void){
	int bprice, pdown;
	float intr, time;
	
	cout << "Price of your motocycle (ß) -> ";
	cin >> bprice;
	cout << "Down payment (%) -> ";
	cin >> pdown;
	system("CLS");
	cout << "Your motocycle price -> " << bprice << " Baht."<< endl;
	cout << "Your down payment -> " << (bprice * pdown)/100 << " Baht."<< endl;
	cout << "Interest rate per year -> " << getintr (pdown) << " %." << endl << endl;
	
	resultboard(bprice, pdown);	//show loan table
	
	char ask;
	cout << "\n\nRun again ? (Y/N) ";
	cin >> ask;
	if(ask == 'y'){
		system("CLS");	//clear screen
		main();
	}
}
void resultboard(int bp, int pd){
	cout << setw(17) << "Payment Time" << setw(25) << "Payment/Month" << setw(25) << "Total Payment" << setw(25) << "Total Interest" << endl;
	for (float i=1; i<4.5 ; i += 0.5){
		cout << setw(3) << i << " Year : " << '(' <<  i*12 << " Months)" << setw(15) << paymonth(bp, pd, i) << setw(26) << totalpay(bp, pd, i) << setw(25) << totalintr(bp, pd, i) << endl;
	}
}
int paymonth(int bp, int pd, float tm){
	return calc(bp, ((bp * pd)/100), tm, getintr(pd));	//shorter for long argument by calc function
}
int totalintr (int bp, int pd, float tm){
	return  totalpay(bp, pd, tm) - bp;	//total pay - bike price
}
int totalpay (int bp, int pd, float tm){
	return (paymonth(bp, pd,tm) * (tm*12)) + ((bp * pd)/100);	//(pay per month*pay time (month))+down price
}
int calc (int b, int d, float t, float i){
	int tloan, tintr, mpayment;
	
	tloan = b-d; //total loan
	tintr = tloan*((i*t)/100);	//total interest 
	tloan = tloan+tintr;	//total loan interest include
	return mpayment = tloan/(t*12);
}
float getintr (int d){
	if (d >= 30){	//d is a down price
		return 6.5;
	}
	else if (d >= 20){
		return 7;
	}
	else if (d >= 10){
		return 7.5;
	}
}
