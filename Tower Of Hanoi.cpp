#include <iostream>
#include <unistd.h>
using namespace std;

//A global integer variable for the number of discs
int no_of_discs;


void show_tower(int tower[][3])
{
	for (int i = 0; i < no_of_discs; i++)
	{
		for (int j = 0; j < 3; j++)
			cout << tower[i][j] << '\t';
		cout << '\n';
	}
	//waits for 2 sec before the next output
	sleep(2);
	cout <<'\n';
}


int Disc_position(int tower[][3], int p)
{
	int i = 0;
	for (i; i < no_of_discs; i++)
		if (tower[i][p] != 0)
			return i;
	return i;
}


int Disc_destiny(int tower[][3], int p)
{
	int i = 0;
	for (i = no_of_discs - 1; i >= 0; i--)
		if (tower[i][p] == 0)
			return i;
	return i;
}


void toh(int tower[][3], int n, int p1, int p2)
{
	int disc, position, destination;
	if (n > 0)
	{
		toh(tower, n - 1, p1, 6 - p1 - p2);
		show_tower(tower);
		cout << "Disc " << n << " from pole " << p1 << " to pole " << p2 << endl;
		position = Disc_position(tower, p1 - 1);
		disc = tower[position][p1 - 1];
		tower[position][p1 - 1] = 0;
		destination = Disc_destiny(tower, p2 - 1);
		tower[destination][p2 - 1] = disc;
		toh(tower, n - 1, 6 - p1 - p2, p2);
	}
}


int main()
{
	cout<<"*************************************************************************************************\n";
	cout<<"*                              WELCOME TO THE GAME TOWER OF HANOI!                              *\n";
	cout<<"*    PLEASE ENTER THE NUMBER OF DISCS YOU WANT TO PLAY WITH DOWN BELOW AND THEN PRESS ENTER     *\n";
	cout<<"*************************************************************************************************\n";
	cout<<"HERE: ";
	int n; cin>>n;

	cout<<"SOLVING..."<<endl<<endl;
	no_of_discs = n;

	int tower[n][3] = {0};


	for (int i = 0; i < n; i++)
		tower[i][0] = i + 1;

	toh(tower, n, 1, 3);

	show_tower(tower);
	cout<<"SOLVED!!\n";
	char c;
	cout<<"\nPRESS ANY KEY AND THEN PRESS ENTER TO EXIT.";
	cin>>c;
	return 0;
}
