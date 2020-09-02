#include<conio.h>
#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<string.h>
using namespace std;
static int p=0;
class a
{
  char busn[5], driver[10], arrival[5], depart[5], from[10],to[10], seat[8][4][10];
public:
  void install();
  void allotment();
  void empty();
  void show() ;
  void avail();
  void position(int i);
}
bus[10];
void vline(char ch){
  for(int i=0; i<=80; i++){ cout<< ch;}
}
void a:: install(){
  cout<< "Enter bus no: "<<endl;
  cin>> bus[p].busn;
  cout<< "Enter Driver's Name: "<<endl;
  cin>> bus[p].driver;
  cout<< "Departure"<< endl;
  cin>> bus[p].depart;
  cout<< "From: "<< endl;
  cin>> bus[p].from;
  cout<< "To: "<< endl;
  cin>> bus[p].to;
  bus[p].empty();
  p++;
}
void a::allotment(){
  int seat;
  char number[5];
  top: cout<< "Bus No.: "; cin>> number;
  int n;
  for(n=0; n<=p; n++)
  {
    if(strcmp(bus[n].busn, number)==0)
    break;
  }
  while(n<=p)
  {
    cout<< "Seat Number:";
    cin>> seat;
    if(seat>32)
    {
      cout<< "There are only 32 seats!";
    }
    else{
      if (strcmp(bus[n].seat[seat/4][(seat%4)-1],"Empty")==0)
      {
        cout<< "Enter Passenger's Name:";
        cin>> bus[n].seat[seat/4][(seat%4)-1];
        break;
      }
      else
        cout<< "The Seat No. is already Reserved"<< endl;
    }
  }
  if(n>p)
  {
    cout<< "Enter Correct Bus No. "<<endl;
    goto top;
  }
}

void a::empty(){
  for(int i=0; i<8; i++)
  {
    for(int j=0; j<4; j++){
      strcpy(bus[p].seat[i][j], "Empty");
    }
  }
}
void a::show(){
	int n;
	char number[5];
	cout<< "Enter bus No. "<< endl;
	cin>> number;
	for(n=0; n<=p; n++)
	{
		if(strcmp(bus[n].busn,number)==0 )
		break;
	}
	while(n<=p)
	{
		vline('*');
		cout<< "Bus no: "<< bus[n].busn<< endl;
		cout<< "Driver: "<< bus[n].driver<< endl;
		cout<< "Arrival time:"<< bus[n].arrival<< endl;
    cout<< "Departure time:"<< bus[n].depart<< endl;
    cout<< "From:"<< bus[n].from<< endl;
    cout<< 'To:'<< bus[n].to<< endl;
    vline('*');
    bus[0].position(n);
    int a=1;
    for(int i=0; i<8; i++)
    {
      for(int j=0; j<4; j++)
      {
        a++;
        if(strcmp(bus[n].seat[i][j], "Empty")!=0)
        cout<< "The seat no."<< (a-1)<< "is reserved for"<< bus[n].seat[i][j]<< ".";
      }
    }
    break;
	} if(n>p)
     { cout<< "Enter Correct Bus No: "; }

}
void a::position(int l){
    int s=0; p=0;
     for(int i=0; i<8; i++)
     {
       cout<< endl;
       for(int j=0; j<4; j++)
       {
         s++;
         if(strcmp(bus[1].seat[i][j], "Empty")==0){
           cout.width(5);
           cout.fill(' ');
           cout<< s<< ".";
           cout.width(10);
           cout.fill(' ');
           cout<< bus[1].seat[i][j];
           p++;
         }
         else {
           cout.width(5);
           cout.fill(' ');
           cout<< s<< ".";
           cout.width(10);
           cout.fill(' ');
           cout<< bus[1].seat[i][j];
         }
       }
     }
     cout<< "There are"<< p << "Seats empty in Bus Bo: "<< bus[1].busn;
}

void a::avail(){
 for (int n=0; n<p; n++)
 {
    vline('*');
    cout<< "Bus no: "<< bus[n].busn<< "Driver: "<< bus[n].driver<<endl;
    cout<< "Arrival no: "<< bus[n].arrival<< "Departure Time "<< bus[n].depart<<endl;
    cout<< "From "<< bus[n].from<< "To: "<< bus[n].to<<endl;
    vline('*');
    vline('_');
 }

}
int main(){
  system("cls");
  int w;
  while(1){
    cout<< "--------WELCOME--------"<< endl;
    cout<< "Bus Reserve Program"<< endl;
    cout<< "1. Install"<< endl;
    cout<< "2. Reserve a Bus seat"<< endl;
    cout<< "3. Show"<< endl;
    cout<< "4. Buses Avaiable"<<endl;
    cout<< "5. Exit"<< endl;
    cout<< "Enter your choice:";
    cin>> w;
    switch (w) {
      case 1: bus[p].install();
      break;
      case 2: bus[p].allotment();
      break;
      case 3: bus[0].show();
      break;
      case 4: bus[0].avail();
      break;
      case 5: exit(0);
    }
  }
  return 0;
}
