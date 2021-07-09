#include <iostream>
#include <windows.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

using namespace std;

void gotoxy(int x, int y){
	HANDLE hCon;
	hCon=GetStdHandle(STD_OUTPUT_HANDLE);
	
	COORD dwPos;
	dwPos.X=x;
	dwPos.Y=y;
	SetConsoleCursorPosition(hCon,dwPos);
}
	
	class Snake{
	public:
		int x,y;
		int dx,dy;
		char body;
	};
	
	class Fruit{
	public:
		int x,y;
		char body='F';
	};
	
	class rock{
	public:
		int x,y;
		char body='X';
	};
	
	class breaker{
	public:
		int x=0;
		int y=0;
		char body='B';
	};
	
	
	class Game{
	public:
		void main();
	private:
		int score,speed;
		int level;
		int mapLevel=0;
		Snake snake[100];
		Fruit fruit;
		breaker breaker;
		rock  rock[1000];
		int bcounter=0;
		int rcounter=0;
		int size=1;
		int con=0;
		int gameMode;
		int height=21,widht=64;
		bool gameover=false;
		bool fruitstack =false;
		bool stonestack=false;
		bool breakstack=false;
		void board();
		void breakcheck(int c);
		void fruitcheck();
		void stonecheck(int c);
		void genFruit();
		void genSnake();
		void genRock();
		void genbreak();
		void loop();
		void key();
		void update();
		void print();
		void cfruit();
		void dead();
		void points();
		void cover();
		void dead2();
		void rockdespawn(int c);
		void menu();
		void mode();
		void levelMenu();
		void instruction();
		void map();
		
	};
	
	void Game::rockdespawn(int c){
		for (int i=0; i<1000;i++){
			rock[i].x=0;
			rock[i].y=0;
		}
		rcounter=0;
		return;
		
	}
	
	void Game::dead2(){
		system("cls");
		rockdespawn(rcounter);
		int height=24,widht=79,r;
		char key;
		char t='#';
		for(int i=0 ; i<widht ; i++){
			gotoxy(i,0);
			cout<<t;
			gotoxy(i,height);
			cout<<t;
		}
		for(int i=0 ; i<=height ; i++){
			gotoxy(0,i);
			cout<<t;
			gotoxy(widht,i);
			cout<<t;
		}
		
		
		string g4meover=
		  R"( 	                           __      
			---_ ...... _/_ -    
			/  .      ./ .'*\ \    
			: '         /__-'   \. 
			/                      )
			_/                  >   .' 
			/   '   .       _.-" /  .'   
			\           __/"     /.'    
			\ '--  .-" /     //'      
			 \|  \ | /     ///    
			     \:     ///
			   `\/     ///
			    \__`\/ //  
			      \_|/
				
			)";
		
		gotoxy(1,2);
		cout << g4meover;;
		
		gotoxy(25,15);
		string snkl =
			"                 _              \n"
			"#       	          ___ _ __   __  | | _____  ___  \n"
			"#      			/ __| '_ \\ / _` | |/ / _ \\/ __| \n"
			"#       		\\__ \\ | | | (_| |   <  __/\\__ \\ \n"
			"#       		|___/_| |_|\\__,_|_|\\_\\___||___/ \n";
		
		std::cout << snkl;
		
		r=22;
	
		
		gotoxy(33,r);
		cout<<"Score: "<<(score-1);
		r++;
		gotoxy(33,r);
		
		if(level==1){
			cout<<"Level: Easy";
		}else if(level==2){
			cout<<"Level: Medium";
		}else{
			cout<<"Level: Hard";
		}
		
		gotoxy(8,23);
		cout<<"Press ESC to exit or any other key to continue playing";
		key=getch();
		if(key==27)
			exit(1);
	}
	
	void Game::menu(){
		do
		{system("cls");
		int height=24,widht=79,r;
		char t='#';
		bcounter=0;
		gameMode =0;
		
		for(int i=0 ; i<widht ; i++){
			gotoxy(i,0);
			cout<<t;
			gotoxy(i,height);
			cout<<t;
		}
		for(int i=0 ; i<=height ; i++){
			gotoxy(0,i);
			cout<<t;
			gotoxy(widht,i);
			cout<<t;
		}
		
		
		/*std::string snkl =
			"                        _              \n"
			"        ___ _ __   __ _| | _____  ___  \n"
			"       / __| '_ \\ / _` | |/ / _ \\/ __| \n"
			"       \\__ \\ | | | (_| |   <  __/\\__ \\ \n"
			"       |___/_| |_|\\__,_|_|\\_\\___||___/ \n";
		
		std::cout << snkl;
		*/
		
		
		gotoxy(25,2);
		string snkl =
		"                 _              \n"
		"#       	          ___ _ __   __  | | _____  ___  \n"
		"#      			/ __| '_ \\ / _` | |/ / _ \\/ __| \n"
		"#       		\\__ \\ | | | (_| |   <  __/\\__ \\ \n"
		"#       		|___/_| |_|\\__,_|_|\\_\\___||___/ \n";
		
		std::cout << snkl;
		
		
		gotoxy(26,12);
		cout<<"Select a Game Mode\n";
		gotoxy(26,14);
		cout<<"1-Classic Mode\n";
		gotoxy(26,16);
		cout<<"2-Free Mode\n";
		
		cin.clear();
		gotoxy(26,23);
		cout<<"Choose a option:";
		cin>>gameMode;}
		while(gameMode>2 || gameMode <1 || cin.fail() );
		
		
		
		
	}
	
	void Game::levelMenu(){
		do{
		system("cls");
		int height=24,widht=79,r;
		char t='#';
		
		for(int i=0 ; i<widht ; i++){
			gotoxy(i,0);
			cout<<t;
			gotoxy(i,height);
			cout<<t;
		}
		for(int i=0 ; i<=height ; i++){
			gotoxy(0,i);
			cout<<t;
			gotoxy(widht,i);
			cout<<t;
		}
		
		
		/*string snkl[]={
			        "			    _        ",     
				"	    ___ _ __   __ _| | _____  ___  ",
				"	   / __| '_ \ / _` | |/ / _ \/ __| ",
				"	   \__ \ | | | (_| |   <  __/\__ \ ",
				"	   |___/_| |_|\__,_|_|\_\___||___/ " };
		
		r=2;
		for(int i=0;i<5;i++){
			gotoxy(25,r);
			r++;
			cout<<snkl[i]<<endl;
		} */
		
		gotoxy(25,2);
		string snkl =
			"                 _              \n"
			"#       	          ___ _ __   __  | | _____  ___  \n"
			"#      			/ __| '_ \\ / _` | |/ / _ \\/ __| \n"
			"#       		\\__ \\ | | | (_| |   <  __/\\__ \\ \n"
			"#       		|___/_| |_|\\__,_|_|\\_\\___||___/ \n";
		
		std::cout << snkl;
		
		
		gotoxy(26,8);
		cout<<"Select a difficulty level\n";
		gotoxy(26,10);
		cout<<"1-Easy\n";
		gotoxy(26,12);
		cout<<"2-Medium\n";
		gotoxy(26,14);
		cout<<"3-Hard\n";
		
		cin.clear();
		gotoxy(26,23);
		cout<<"Chose a option:";
		cin>>level;}
		while(level>3 || level <1 || cin.fail() );
		
	}
	
	
	void Game::cover(){
		system("cls");
		int height=24,widht=79,r;
		char t='#';
		char key;
		for(int i=0 ; i< widht; i++){
			gotoxy(i,0);
			cout<<t;
			gotoxy(i,height);
			cout<<t;
		}
		for(int i=0 ; i<=height ; i++){
			gotoxy(0,i);
			cout<<t;
			gotoxy(widht,i);
			cout<<t;
		}
		string snkd[]={
			"       ---_ ......._-_--.",
			"      (|\\ /      / /| \\  \\",
			"      /  /     .'  -=-'   `.",
			"     /  /    .'             )",
			"   _/  /   .'        _.)   /",
			"   / o   o        _.-' /  .'",
			"  \\          _.-'    / .'*|",
			"  \\______.-'//    .'.' \\*|",
			"   \\|  \\ | //   .'.' _ |*|",
			"     `   \\|//  .'.'_ _ _|*|",
			"      .  .// .'.' | _ _ \\*|",
			"      \\`-|\\_/ /    \\ _ _ \\*\\",
			"                     \\ _ _ \\*",
			"                      \\ _ _ \\ ",
			"                       \\_"};
		
		r=2;
		for(int i=0;i<14;i++){
			gotoxy(20,r);
			r++;
			cout<<snkd[i]<<endl;
		}
		
		/*string snkl[]={
				"						_        ",     
				"	    ___ _ __   __ _| | _____  ___  ",
				"	   / __| '_ \ / _` | |/ / _ \/ __| ",
				"	   \__ \ | | | (_| |   <  __/\__ \ ",
				"	   |___/_| |_|\__,_|_|\_\___||___/ "};
		for(int i=0;i<5;i++){
			gotoxy(22,r);
			r++;
			cout<<snkl[i]<<endl;
		}*/
		
		gotoxy(25,15);
		string snkl =
			"                 _              \n"
			"#       	          ___ _ __   __  | | _____  ___  \n"
			"#      			/ __| '_ \\ / _` | |/ / _ \\/ __| \n"
			"#       		\\__ \\ | | | (_| |   <  __/\\__ \\ \n"
			"#       		|___/_| |_|\\__,_|_|\\_\\___||___/ \n";
		
		std::cout << snkl;
		
		
		gotoxy(27,22);
		cout<<"Press ENTER to start";
		key=getch();
		if(key==27)
			exit(1);
		
		
	}
	
	void Game::map(){
		do{
		system("cls");
		int height=24,widht=79,r;
		char t='#';
		
		for(int i=0 ; i<widht ; i++){
			gotoxy(i,0);
			cout<<t;
			gotoxy(i,height);
			cout<<t;
		}
		for(int i=0 ; i<=height ; i++){
			gotoxy(0,i);
			cout<<t;
			gotoxy(widht,i);
			cout<<t;
		}
		cin.clear();
		gotoxy(26,8);
		cout<<"Choose a map\n";
		gotoxy(26,10);
		cout<<"1-Classic garden";
		gotoxy(26,12);
		cout<<"2-The world divided";
		gotoxy(26,14);
		cout<<"3-Death Oasis";
		gotoxy(26,16);
		cout<<"4-Titan's nest";
		
		gotoxy(26,23);
		cout<<"Chose a option:";
		cin>>mapLevel;}
		while (mapLevel<1 ||mapLevel >4 || cin.fail());
				
	}
	
	void Game::instruction(){
		system("cls");
		int height=24,widht=79,r;
		char t='#';
		char key;
		
		for(int i=0 ; i<widht ; i++){
			gotoxy(i,0);
			cout<<t;
			gotoxy(i,height);
			cout<<t;
		}
		for(int i=0 ; i<=height ; i++){
			gotoxy(0,i);
			cout<<t;
			gotoxy(widht,i);
			cout<<t;
		}
		
		gotoxy(25,2);
		string snkl =
			"                 _              \n"
			"#       	          ___ _ __   __  | | _____  ___  \n"
			"#      			/ __| '_ \\ / _` | |/ / _ \\/ __| \n"
			"#       		\\__ \\ | | | (_| |   <  __/\\__ \\ \n"
			"#       		|___/_| |_|\\__,_|_|\\_\\___||___/ \n";
		
		std::cout << snkl;
		
		
		gotoxy(15,8);
		cout<<" Bush can be traveled through in free mode\n";
		gotoxy(15,10);
		cout<<" Stone(X) will randomly spawns to kill the snake\n";
		gotoxy(15,12);
		cout<<" Butterfly(B) provides powerboost to break 3 stones\n";
		gotoxy(25,14);
		cout<<" Eat Fruit (F) to grow \n";
		gotoxy(25,16);
		cout<<"Press ENTER to start";
		key=getch();
		if(key==27)
			exit(1);
		
	}
	
	
	void Game::points(){
		gotoxy(widht+2,2);
		cout<<"Score: "<<(score-1);
		gotoxy(widht+2,4);
		cout<<"Level: "<<level;
		gotoxy(widht+2,6);
		cout<<"Length: "<<size;
		gotoxy(widht+2,8);
		cout<<"Butterfly: "<<bcounter;
		//gotoxy(widht+2,10);
		//cout<<"Rcounter: "<<rcounter;
		
	}
	void Game::board(){
		char t=178;
		rockdespawn(rcounter);
		rcounter=0;
		bcounter=0;
		for(int i=1 ; i<widht ; i++){
			gotoxy(i,1);
			cout<<t;
			gotoxy(i,height);
			cout<<t;
		}
		for(int i=1 ; i<=height ; i++){
			gotoxy(1,i);
			cout<<t;
			gotoxy(widht,i);
			cout<<t;
		}
		
		if (mapLevel == 2){
			gotoxy(32,3);
			for (int j=2;j<21;j++){
				if (j!=10){
					rock[rcounter].x=32;
					rock[rcounter].y=j;
					gotoxy(rock[rcounter].x,rock[rcounter].y);
					cout<<rock[rcounter].body;
					rcounter++;}
			}
		}
		else if (mapLevel==3){
			gotoxy(4,4);
			for (int k= 3;k<28;k++){
				rock[rcounter].x=k;
				rock[rcounter].y=4;
				gotoxy(rock[rcounter].x,rock[rcounter].y);
				cout<<rock[rcounter].body;
				rcounter++;}
			
			gotoxy(28,4);
			for (int k=4;k<9;k++){
				rock[rcounter].x=28;
				rock[rcounter].y=k;
				gotoxy(rock[rcounter].x,rock[rcounter].y);
				cout<<rock[rcounter].body;
				rcounter++;
			}
			
			gotoxy(37,4);
			for (int k= 37;k<63;k++){
				rock[rcounter].x=k;
				rock[rcounter].y=4;
				gotoxy(rock[rcounter].x,rock[rcounter].y);
				cout<<rock[rcounter].body;
				rcounter++;}
			
			gotoxy(36,4);
			for (int k=4;k<9;k++){
				rock[rcounter].x=36;
				rock[rcounter].y=k;
				gotoxy(rock[rcounter].x,rock[rcounter].y);
				cout<<rock[rcounter].body;
				rcounter++;
			}
			
			gotoxy(4,18);
			for ( int k= 3;k<28;k++){
					rock[rcounter].x=k;
					rock[rcounter].y=18;
					gotoxy(rock[rcounter].x,rock[rcounter].y);
					cout<<rock[rcounter].body;
					rcounter++;}
				
			gotoxy(28,18);
			for (int k=18;k>13;k--){
				rock[rcounter].x=28;
				rock[rcounter].y=k;
				gotoxy(rock[rcounter].x,rock[rcounter].y);
				cout<<rock[rcounter].body;
				rcounter++;
			}
			
			gotoxy(37,18);
			for ( int k= 37;k<63;k++){
					rock[rcounter].x=k;
					rock[rcounter].y=18;
					gotoxy(rock[rcounter].x,rock[rcounter].y);
					cout<<rock[rcounter].body;
					rcounter++;}
				
			gotoxy(36,18);
			for (int k=18;k>13;k--){
				rock[rcounter].x=36;
				rock[rcounter].y=k;
				gotoxy(rock[rcounter].x,rock[rcounter].y);
				cout<<rock[rcounter].body;
				rcounter++;
			}	
				
		}
		else if (mapLevel ==4){
			gotoxy(5,3);
			for (int k=5;k<60;k++){
				rock[rcounter].x=k;
				rock[rcounter].y=3;
				gotoxy(rock[rcounter].x,rock[rcounter].y);
				cout<<rock[rcounter].body;
				rcounter++;
			}
			
			gotoxy(5,4);
			for (int k=4;k<8;k++){
				rock[rcounter].x=5;
				rock[rcounter].y=k;
				gotoxy(rock[rcounter].x,rock[rcounter].y);
				cout<<rock[rcounter].body;
				rcounter++;
			}
			
			gotoxy(59,4);
			for (int k=4;k<8;k++){
				rock[rcounter].x=59;
				rock[rcounter].y=k;
				gotoxy(rock[rcounter].x,rock[rcounter].y);
				cout<<rock[rcounter].body;
				rcounter++;
			}
			
			
			gotoxy(5,18);
			for (int k=5;k<60;k++){
				rock[rcounter].x=k;
				rock[rcounter].y=18;
				gotoxy(rock[rcounter].x,rock[rcounter].y);
				cout<<rock[rcounter].body;
				rcounter++;
			}
			
			gotoxy(5,17);
			for (int k=17;k>13;k--){
				rock[rcounter].x=5;
				rock[rcounter].y=k;
				gotoxy(rock[rcounter].x,rock[rcounter].y);
				cout<<rock[rcounter].body;
				rcounter++;
			}
			
			gotoxy(59,17);
			for (int k=17;k>13;k--){
				rock[rcounter].x=59;
				rock[rcounter].y=k;
				gotoxy(rock[rcounter].x,rock[rcounter].y);
				cout<<rock[rcounter].body;
				rcounter++;
			}
			
			gotoxy(15,7);
			for (int k=15;k<30;k++){
				rock[rcounter].x=k;
				rock[rcounter].y=7;
				gotoxy(rock[rcounter].x,rock[rcounter].y);
				cout<<rock[rcounter].body;
				rcounter++;
			}
			
			gotoxy(15,7);
			for (int k=35;k<50;k++){
				rock[rcounter].x=k;
				rock[rcounter].y=7;
				gotoxy(rock[rcounter].x,rock[rcounter].y);
				cout<<rock[rcounter].body;
				rcounter++;
			}
			
			gotoxy(15,8);
			for (int k=8;k<14;k++){
				rock[rcounter].x=15;
				rock[rcounter].y=k;
				gotoxy(rock[rcounter].x,rock[rcounter].y);
				cout<<rock[rcounter].body;
				rcounter++;
			}
			
			gotoxy(15,14);
			for (int k=35;k<50;k++){
				rock[rcounter].x=k;
				rock[rcounter].y=14;
				gotoxy(rock[rcounter].x,rock[rcounter].y);
				cout<<rock[rcounter].body;
				rcounter++;
			}
			
			gotoxy(15,14);
			for (int k=15;k<30;k++){
				rock[rcounter].x=k;
				rock[rcounter].y=14;
				gotoxy(rock[rcounter].x,rock[rcounter].y);
				cout<<rock[rcounter].body;
				rcounter++;
			}
			
			gotoxy(50,7);
				for (int k=7;k<15;k++){
					rock[rcounter].x=50;
					rock[rcounter].y=k;
					gotoxy(rock[rcounter].x,rock[rcounter].y);
					cout<<rock[rcounter].body;
					rcounter++;
			}
		}
		
		
		
		
	}
	
	void Game::fruitcheck(){
		for (int i=0;i<1000;i++){
			if (fruit.x==rock[i].x && fruit.y== rock[i].y){
				fruitstack =true;
				return;
			}
		}
		
		if (fruit.x==breaker.x && fruit.y==breaker.y){
			fruitstack=true;
			return;
		} 
		
		for (int j=1;j<size;j++){
			if (fruit.x==snake[j].x && fruit.y==snake[j].y){
				fruitstack =true;
				return;
			}
		}
		
		fruitstack =false;
		return;
	}
	
	void Game::stonecheck(int c){
		if (rock[c].x==fruit.x && rock[c].y==fruit.y){
			stonestack=true;
			return;
		}
		
		if (rock[c].x==breaker.x && rock[c].y==breaker.y){
			stonestack=true;
			return;
		}
		for (int i=0;i<c;i++){
			if (rock[c].x==rock[i].x && rock[c].y==rock[i].y){
				stonestack = true;
				return;
			}
		}
		
		for (int j=1;j<size;j++){
			if (rock[c].x==snake[j].x && rock[c].y==snake[j].y){
				stonestack =true;
				return;
			}
		}
		
		stonestack=false;
		return;
	}
	
	void Game::breakcheck(int c){
		for (int i=0;i<1000;i++){
			if (breaker.x==rock[i].x && breaker.y== rock[i].y){
				breakstack =true;
				return;
			}
		}
		
		for (int j=1;j<size;j++){
			if (breaker.x==snake[j].x && breaker.y==snake[j].y){
				breakstack =true;
				return;
			}
		}
		
		if (breaker.x==fruit.x && breaker.y==fruit.y){
			breakstack=true;
			return;
		}
		
		breakstack =false;
		return;
	}
	void Game::genFruit(){
		
		fruit.x = 3+( rand() % (widht-3) );
		fruit.y = 3+(rand() % (height-3));
		fruitcheck();
		
		while (fruitstack==true){
			fruit.x = 3+( rand() % (widht-3) );
			fruit.y = 3+(rand() % (height-3));
			fruitcheck();
		}
		
		gotoxy(fruit.x,fruit.y);
		cout<<fruit.body;
		
	}
	
	void Game::genRock(){
		//static int counter=0;
		if(rcounter<1000){
		rock[rcounter].x = 3+( rand() % (widht-3) );
		rock[rcounter].y = 3+(rand() % (height-3));
		stonecheck(rcounter);
		
		while(stonestack==true){
			rock[rcounter].x = 3+( rand() % (widht-3) );
			rock[rcounter].y = 3+(rand() % (height-3));
			stonecheck(rcounter);
		}
		
		gotoxy(rock[rcounter].x,rock[rcounter].y);
		cout<<rock[rcounter].body;
		rcounter++;
		}
	}
	
	void Game::genbreak(){
		if (breaker.x==0 && breaker.y==0){
		breaker.x = 3+( rand() % (widht-3) );
		breaker.y = 3+(rand() % (height-3));
		breakcheck(rcounter);
		
		while (breakstack==true){
			breaker.x = 3+( rand() % (widht-3) );
			breaker.y = 3+(rand() % (height-3));
			breakcheck(rcounter);
		}
		
		gotoxy(breaker.x,breaker.y);
		cout<<breaker.body;
		}
		else{
			return;
		}
		
	}
	void Game::dead(){
		if(snake[0].x==1 || snake[0].x==widht || snake[0].y==1 || snake[0].y==height )
			gameover=true;

		for(int j=0;j<rcounter && gameover==false;j++){
			if(snake[0].x==rock[j].x && snake[0].y==rock[j].y){
				if (bcounter>0){
					bcounter=bcounter-1;
					rock[j].x=0;
					rock[j].y=0;
				}
				else{
				gameover=true;
				}
			}
		}		
		for(int i=1;i<size && gameover==false;i++){
			if(snake[0].x==snake[i].x && snake[0].y==snake[i].y){
				gameover=true;
			}
			
		}
	}
	
	void Game::mode(){
		char t=178;
		if(snake[0].x == 1 ){
			
			gotoxy(snake[0].x,snake[0].y);
			cout<<t;
			snake[0].x=widht-1;
		}
		
		if(snake[0].x==widht){

			gotoxy(snake[0].x,snake[0].y);
			cout<<t;
			snake[0].x=2;
	
		}
		
		if(snake[0].y == 1 ){
			gotoxy(snake[0].x,snake[0].y);
			cout<<t;
			snake[0].y=height-1;
		}
		
		if(snake[0].y==height){
			gotoxy(snake[0].x,snake[0].y);
			cout<<t;
			snake[0].y=2;
		}
		
		for(int i=1;i<size && gameover==false;i++){
			if(snake[0].x==snake[i].x && snake[0].y==snake[i].y){
				gameover=true;
			}
			
		}
		
		for(int j=0;j<rcounter && gameover==false;j++){
			if(snake[0].x==rock[j].x && snake[0].y==rock[j].y){
				if (bcounter>0){
					bcounter=bcounter-1;
					rock[j].x=0;
					rock[j].y=0;
				}
				else{
					gameover=true;
				}
			}
			
		}	
	}
	
	void Game::key(){
		int i;
		char key;
		
		if (!gameover){
			if (kbhit()==1){
				key=getch();
				
			}
			if((key==72) && snake[0].dy !=1){
				snake[0].dx=0;
				snake[0].dy=-1;
			}
			if((key==80) && snake[0].dy !=-1){
				snake[0].dx=0;
				snake[0].dy=1;
			}
			if((key==75) && snake[0].dx !=1){
				snake[0].dx=-1;
				snake[0].dy=0;
			}
			if((key==77) && snake[0].dx !=-1){
				snake[0].dx=1;
				snake[0].dy=0;
			}
		}
	}
	
	void Game::genSnake(){
		int i;
		snake[0].x=30;
		snake[0].y=10;
		snake[0].dx=1;
		snake[0].dy=0;
		//		snake[0].body=190;
		snake[0].body='O';
		
		
		
		for(i=1;i < size; i++){
			snake[i].x=snake[i-1].x-1;
			snake[i].y=snake[i-1].y;
			snake[i].body='o';
			
		}
		
		
		for(i=0; i<size; i++){
			gotoxy(snake[i].x,snake[i].y);
			cout<<snake[i].body;
		}
	}
	
	void Game::cfruit(){
		if(snake[0].x==breaker.x && snake[0].y==breaker.y){
			bcounter=bcounter+3;
			breaker.x=0;
			breaker.y=0;
		}
		
		if(snake[0].x==fruit.x && snake[0].y==fruit.y){
			con++;
			genFruit();
			
			
			if(level==1 && con==1){
				size+=1;
				con=0;
			}else if(level==2 && con==2){				
				size+=1;
				con=0;
			}else if(level==3 && con==3){
				size+=1;
				con=0;
			}
			
			if(level==1 && size%5==0){
				genRock();
			}else if(level==2 && size%3==0){				
				genRock();
			}else if(level==3){
				genRock();
			}
			
			if(score%5==0){
				genbreak();
			}
			
			snake[size-1].body='o';
			score+=1;
			
			
			if((score%10==0) && (speed >20)){
				if (level ==1){
					speed = speed- 15;}
				else if (level ==2){
					speed = speed - 15;}
				else {
					speed= speed - 10;}
			}
			
		}
	}
	
	void Game::update(){
		int i;
		gotoxy(snake[size-1].x,snake[size-1].y);
		cout<<" ";
		
		for (i= size; i>0; i--){
			snake[i].x=snake[i-1].x;
			snake[i].y=snake[i-1].y;
		}
		snake[0].x += snake[0].dx;
		snake[0].y += snake[0].dy;
		
	}
	
	void Game::print(){
		int i;
		for(i= size-1; i>=0; i--){
			gotoxy(snake[i].x,snake[i].y);
			cout<<snake[i].body;
		}
	}
	void Game::loop(){
		while(!gameover){
			cfruit();
			points();
			update();
			print();
			key();
			key();
			key();
			if(gameMode==1){
				dead();
			}else{
				mode();
			}			
			Sleep(speed);
		}
	}
	
	void Game::main(){
		system("color 0a");
		gameover=false;
		cover();
		system("cls");
		menu();
		system("cls");
		map();
		system("cls");
		levelMenu();
		system("cls");
		instruction();
		system("cls");
		bcounter=0;
		score=1;
		
		
		if (level ==1){
			speed=200;}
		else if (level ==2){
			speed=125;}
		else {
			speed=75;}
		size=3;
		con=0;
		board();
		srand(time(NULL));
		genSnake();
		genFruit();
		loop();
		dead2();
		main();
		
		
	}
	
	int main(){
		Game j;
		j.main();
	}
		
