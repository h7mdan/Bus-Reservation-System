#include<bits/stdc++.h>

	using namespace std;
	
 int p=0;

class a {
	
	char busno[5], driver[10],arrival[10], departure[10],from[10], to[10], seat[8][4][10];
	
	public:
			void addNewBus(); //Add new bus detail.
			void Allotment(); //allotment of seats
			void empty(); //Used to intilialize all bus seats as vacent
			void showSeats();      //shows avialble bus seats from a bus
			void availBuses();     //shows all avialable buses
			void showReservedSeats(int i); //to get the all reserved bus seats from a bus

}
	bus[25]; //array to store busses upto 25.
	
void vline(char ch)
{
	for(int i=80;i>0;i--)
	{
	cout<<ch;
	}

cout<<endl;
}
	void a::addNewBus()
	{
		cout<<"Enter Bus Number: ";
		cin>>bus[p].busno;
		
		cout<<"\nEnter Driver Name: ";
		cin>>bus[p].driver;
		
		cout<<"\nArrival: ";
		cin>>bus[p].arrival;
		
		cout<<"\nEnter Departure: ";
		cin>>bus[p].departure;
		
		cout<<"\nEnter From: \t\t\t";
		cin>>bus[p].from;
		
		cout<<"\nEnter To: \t\t\t";
		cin>>bus[p].to;
		bus[p].empty(); //It will fill all seats with empty.
		
		p++;
	}
	
	//Allotting seats in the bus.
	void a::Allotment()
	{
		int seat; //enter seat from 1 to 32
		
		char number[5];
		
		top:
			cout<<"Bus no.: ";
			cin>>number;
			int n;
			for(n=0;n<=p;n++)
			{
				if (strcmp(bus[n].busno, number)==0)
				break;
			}
			while(n<=p)
			{
				cout<<"\nSeat number: ";
				cin>>seat;
				
				if(seat>32)
				{
					cout<<"\nThere are only 32 seats available in this BUS. ";
				}
				else
				{
					if(strcmp(bus[n].seat[seat/4][(seat%4)-1],"Empty")==0)
					{
						cout<<"Enter Passenger's Name: ";
						cin>>bus[n].seat[seat/4][(seat%4)-1];
						break;
					}
					else
						cout<<"Seat already Reserved.\n";
				}
			}
			if(n>p)
			{
				cout<<"Enter Correct bus number.\n";
				goto top;
			}
	}
	//Make all seats empty
	void a::empty()
	{
		for(int i=0;i<8;i++)
		{
			for(int j=0;j<4;j++)
			{
				strcpy(bus[p].seat[i][j],"Empty");
			}
		}
	}
	
	//Allows to check vacant seats
	void a::showSeats()
	{
		//int n;
		char number[5];
		cout<<"Enter bus no: ";
		cin>>number;
		int n;
		//checks the bus number with the input.
		for( n=0;n<=p;n++)
		{
		
		if(strcmp(bus[n].busno,number)==0)
		
		break;
		}
		while(n<=p)
		{
			vline('*');
			cout<<"\nBus No: \t"<<bus[n].busno
			<<"\nDriver: \t"<<bus[n].driver
			<<"\nArrival Time: \t"<<bus[n].arrival
			<<"\nDepartue Time: "<<bus[n].departure
			<<"\nFrom: \t\t"<<bus[n].from
			<<"\t\tTo:  \t\t"<<bus[n].to<<"\n";
			vline('*');
			
			bus[0].showReservedSeats(n);
			
			int a=1;

  			for (int i=0; i<8; i++)
  			{
  				for(int j=0;j<4;j++)
  				{
  					a++;
  					if(strcmp(bus[n].seat[i][j],"Empty")!=0)
  					
  					cout<<"\nThe seat no"<<(a-1)<<" is reserved for "<<bus[n].seat[i][j]<<".";
  					
				  }
			  }
			  break;
		}
		if(n>p)
		cout<<"Enter Correct Bus No: ";
	}
	
	//Helps create a table output with seats empty and reserved seats with passenger name
	void a::showReservedSeats(int l)
	{

  int s=0,h=0;

  for (int i =0; i<8;i++)

  {

    cout<<"\n";

    for (int j = 0;j<4; j++)

    {

      s++;

      if(strcmp(bus[l].seat[i][j], "Empty")==0)

        {

          cout.width(5);

          cout.fill(' ');

          cout<<s<<".";

          cout.width(10);

          cout.fill(' ');

          cout<<bus[l].seat[i][j];

          h++;

        }

        else

        {

        cout.width(5);

        cout.fill(' ');

        cout<<s<<".";

        cout.width(10);

        cout.fill(' ');

        cout<<bus[l].seat[i][j];

        }

      }

    }

  cout<<"\n\nThere are "<<h<<" seats empty in Bus No: "<<bus[l].busno;

  }
  //Print all the buses added in the system
  void a::availBuses()
  {
  	for(int n=0;n<p;n++)
  
  	{
  	vline('*');
			cout<<"\nBus No: \t"<<bus[n].busno
			<<"\nDriver: \t"<<bus[n].driver
			<<"\t\tArrival Time: \t"<<bus[n].arrival
			<<"\tDepartue Time: \t"<<bus[n].departure
			<<"\nFrom: \t\t"<<bus[n].from
			<<"\t\tTo:  \t\t\t"<<bus[n].to<<"\n";
			vline('*');
			 vline('_');
  	}
  }
  
  //Main function.
  int main()
  
{

//system("cls");
  //Choice will be users input to use different functionality over system using switch 
  int choice;
  vline('-');
  cout<<"\t\t\t\t**** Bus Travel Agency****"<<endl<<endl;
  vline('-');
  while(1)
  {
 

    //system("cls");
  cout<<endl;
  vline('*');
  cout<<"\n\n";

  cout<<"\t\t\t1.Add new Bus Details:\n\t\t\t"

  <<"2.Reserve your seats:\n\t\t\t"

  <<"3.Show the available seats in a bus:\n\t\t\t"

  <<"4.Buses Available Now: \n\t\t\t"

  <<"5.Exit";
  cout<<endl;
  vline('*');
  cout<<"\n\t\t\tEnter your choice:-> ";

  cin>>choice;
  vline('*');

  switch(choice)

  {

    case 1:  bus[p].addNewBus();

      break;

    case 2:  bus[p].Allotment();

      break;

    case 3:  bus[0].showSeats();
      break;

    case 4:  bus[0].availBuses();

      break;

    case 5:  {
      cout<<"Successfully Logged out from the Application. Visit Again!"<<endl<<"<Thank You :)>"<<endl<<"Created By Hamdan Siddiqui"<<endl;
      exit(0);
    };

  }

}

return 0;

}
