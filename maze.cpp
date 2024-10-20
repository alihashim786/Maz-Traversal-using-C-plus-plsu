// Muhammad Haris 
// 22i-2479  SE-A

#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;

void printMaze(char **maze, int i, int j, int rows) {
    if (i == rows) {
        return;
    }

    cout <<setw(3)<<maze[i][j];

    if (j == 11) {
        cout << endl;
        printMaze(maze, i+1, 0, rows);
    } else {
        printMaze(maze, i, j+1, rows);
    }
}





bool mazeSolver( char **maze, int nrows, int ncols, int px/*starting row */, int py /*starting column*/,int cx,int cy){

char mouseshape = 'X';
char wallshape = '#';

maze [px][py] = mouseshape;	

cout<<"Control the mouse by using WASD \n\n";

printMaze(maze, 0, 0, nrows);   //printing maze


char action;
cout<<endl;

cout<<"Action : ";
cin>>action;

int oldpx=px;
int oldpy=py;



switch (action)
{
	case 'w' :
		
		if (maze [px-1][py] == wallshape)	//  moving upward means we have moved to lower row index in a same column. so to check the pont where we moved is wall pr not we will put condition of [px-1] because we moving to low row index and [py] means in the same column
		{
			cout << "You cannot go through the walls \n"; 
		}
		else
		{	
		px--;
		maze [oldpx][oldpy] = 'X'; 	
		
		}
//	system ("CLS");
	break;
	
	case 'a' :
	
		if (maze [px][py-1] == wallshape )
		{
			cout << "You cannot go through the walls \n"; 
		}
		else
		{	
		py--;
		maze [oldpx][oldpy] = 'X'; 	
		
		}
//	system ("CLS");
	break;

	case 'd':
	
		if (maze [px][py+1] == wallshape)
		{
			cout << "You cannot go through the walls \n";
		}
		else
		{	
		py++;
		maze [oldpx][oldpy] ='X'; 	
		
		}
//	system ("CLS");
	break;
	
	case 's':
	
		if (maze [px+1][py] == wallshape)
		{
			cout << "You cannot go through the walls \n";
		}
		else
		{	
		px++;
		maze [oldpx][oldpy] = 'X'; 	
		
		}
//	system ("CLS");
	break;
	
	default :
		
		cout<<"Invalid Action \n";
				
			break;
}

maze[px][py] = mouseshape;


system ("cls");


if (maze [cx][cy] != mouseshape){   //recursice call.
return mazeSolver(maze, nrows, ncols, px, py,cx,cy);	
}

	if (maze [cx][cy] == mouseshape)   //if X reached to exit point //base condition
	{ 	
	printMaze(maze, 0, 0, nrows);   //printing maze
	      
		 system ("CLS");
		 cout<< "Congratulation you have reached to the EXIT point :)\n\n";
	return true;
	}

}




	

int main(){

cout<<setw(50)<<"Maze Traversal\n";
cout<<"Hashes represents the walls and dots represents the path where you can move. You will be moving as X and also you can backward too\n\n";


char rows = 12;	
char columns = 12;


int px;
cout<<"Enter starting row : *must be between 0 and 11* : ";
menu:
cin>>px;
if(px>11){
cout<<"Invalid Input. Enter again : ";
goto menu;
}
int py=11;  //starting column is set to 11 so that user always enters from the rightous side.

srand(time(0));        //generate new number everytime
int cx=rand()%10+1;   //generating a random number from 0 to 10 for the exiting row index because at we can't reach to index 11 in any way
int cy=0;            //exit column is set to zero index for always



char** ptr = new char*[12]; // Allocate memory for 3 rows
    for (int i = 0; i < 12; i++) {
        ptr[i] = new char[12]; // Allocate memory for 12 columns in each row
    }

	
char arr[rows][columns]= {	
{'#','#','#','#','#','#','#','#','#','#','#','#'},
{'#','.','.','.','#','.','.','.','.','.','.','#'},
{'#','.','#','.','#','.','#','#','#','#','.','#'},
{'#','#','#','.','#','.','.','.','.','#','.','#'},
{'#','.','.','.','.','#','#','#','.','#','.','#'},
{'#','#','#','#','.','#','.','#','.','#','.','#'},
{'#','.','.','#','.','#','.','#','.','#','.','#'},
{'#','#','.','#','.','#','.','#','.','#','.','#'},
{'#','.','.','.','.','.','.','.','.','#','.','#'},
{'#','#','#','#','#','#','.','#','#','#','.','#'},
{'#','.','.','.','.','.','.','#','.','.','.','#'},
{'#','#','#','#','#','#','#','#','#','#','#','#'}};


//Copying array to the pointer
for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            ptr[i][j] = arr[i][j];
        }
    }
    
//Putting dot in entering point    
ptr[px][py]='.';
ptr[cx][cy]='.';

//Printing maze
/*for (int i=0; i<rows; i++)
{
	for (int j=0; j<columns; j++)
	{
		cout<<setw(3)<<(char)ptr[i][j];
	}
	cout<<endl;
}*/
printMaze(ptr, 0, 0, rows);

cout<<"\n\n*Do Your First Move. The EXIT point is generated automatically*\n";

mazeSolver(ptr, rows, columns,px,py,cx,cy);


return 0;	
}


