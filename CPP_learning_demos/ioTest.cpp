#include<iostream>
#include<iomanip>
#include<string>
using namespace std;
 
int main(){
	int hour = 5;
	int minute = 30;
	int second = 0;	
	string time = "12:34:56";
	char chara = 'a';
	cout << setw(2) << hour  << endl 
		 << setw(10) << time <<":"
		 << setw(2) << chara << endl;
	for (int i = 0; i < time.length()+5; i++){
		cout << (int)time[i] << " ";
	}
	cout <<  setprecision(4) << 999991<< endl;
	cout << (float)time.length() << endl;
	cout << sizeof(time) << endl;
} 