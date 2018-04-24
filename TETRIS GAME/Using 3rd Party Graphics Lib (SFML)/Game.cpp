/*=======================================================
name: Edward Koroteev
date: 2/16/2015
VISUAL STUDIOS 2012
purpose: Graphics for the tetris game. coloring the piece,
drawing the well, and the game display, and connecting
keys with movements
=======================================================*/
#include<iostream>
#include"Game.h"
#include"Well.h"
#include"Tetrimino.h"
#include<math.h>

using namespace std;

/*======================================================
Function Name: Game	(VOID)
Arguements: None
Return: None
Purpose: Draws the window and layout and title bar
========================================================*/
Game::Game()
{
	//initializing TetriminoInPlay pointer to NULL
	TetriminoInPlay = NULL;

	//initializing TetriminoOnDeck pointer to NULL
	TetriminoOnDeck = NULL;

	//initializing score
	Score = 0;

	//initializing Splash image
	if(!SplashScreenImage.loadFromFile("TetrisBackgroundSplashScreen.jpg"))
	{
		cout << "ERROR IMAGE LOADING" << endl;
	}

	//Initialize game over image
	if(!GameOverImage.loadFromFile("GameOverImage.jpg"))
	{
		cout << "ERROR GAME OVER IMAGE LOADING" << endl;
	}

	//initializing Font
	if(!MyFont.loadFromFile("Coda-Heavy.ttf"))
	{
		cout << "CAN'T FIND THE FONT";
	}

	//Loading arcade font
	if(!ArcadeFont.loadFromFile("ARCADECLASSIC.ttf"))
	{
		cout << "ERROR LOADING ARCADE FONT" << endl;
	}

	//loading halo font
	if(!HaloFont.loadFromFile("HALO____.ttf"))
	{
		cout << "ERROR LOADING HALO FONT" << endl;
	}

	//loading the rotation sound for the game
	if (!soundBuffer.loadFromFile("Rotation.wav"))
	{
		cout << "Can't find";
	}

	//loading music
	if (!Music.openFromFile("original tetris theme (tetris soundtrack).wav"))
	{
		cout << "Can't find";
	}
	Music.setLoop(true);
	Music.play();

	//create a window and set framerate
	Window.create(sf::VideoMode(LAYOUT_WINDOW_WIDTH,LAYOUT_WINDOW_HEIGHT),
		"Tetris 2015", sf::Style::Titlebar | sf::Style::Close);
	Window.setFramerateLimit(30);
}


/*======================================================
Function Name: PlayGame	(VOID)
Arguements: None
Return: None
Purpose: Checks for poll events and calls the proper 
functions assosiated with the event.
links rotation, up, down, left all sorts
of movements with the keys
========================================================*/
void Game::PlayGame()
{
	GameState GameStateVariable = TETRIS_SPLASH;
	//GameState GameStateVariable = TETRIS_GAME_OVER;
	//GameState GameStateVariable = TETRIS_HIGHSCORE;
	//GameState GameStateVariable = TETRIS_PLAY;

	while(Window.isOpen())
	{
		//If the tetris splash screen is open
		if(GameStateVariable == TETRIS_SPLASH)
		{
			if(ProcessSplashScreen() == TETRIS_PLAY)
			{
				GameStateVariable = TETRIS_PLAY;
			}
			if(ProcessSplashScreen()== TETRIS_HIGHSCORE)
			{
				GameStateVariable = TETRIS_HIGHSCORE;
			}

		}
		//if the play screen is open
		if(GameStateVariable == TETRIS_PLAY)
		{
			if(ProcessGameScreen()== TETRIS_GAME_OVER)
			{
				GameStateVariable = TETRIS_GAME_OVER;
			}
		}  
		//if game over
		if(GameStateVariable == TETRIS_GAME_OVER)
		{
			if(ProcessGameOverScreen() == TETRIS_SPLASH)
			{
				GameStateVariable = TETRIS_SPLASH;
			}

			if(ProcessGameOverScreen() == TETRIS_PLAY)
			{
				GameStateVariable = TETRIS_PLAY;
			}
		}
		//switch to highscore
		if(GameStateVariable == TETRIS_HIGHSCORE)
		{
			if(ProcessHighScoreScreen() == TETRIS_SPLASH)
			{
				GameStateVariable = TETRIS_SPLASH;
			}
		}
	}


}


/*======================================================
Function Name: DrawWell	(VOID)
Arguements: MyWell	(WELL)
LocationTop	(INT)
LocationSide	(INT)
BlockPixel	(INT)
Return: None
Purpose: Draws the Well with the aprropriate sizes
and outline grids inside the well with the
peoper colors
========================================================*/
void Game::DrawWell(Well MyWell, int LocationTop, int LocationSide, int BlockPixel)
{
	//Variables
	char LocalWell[WELL_HEIGHT][WELL_WIDTH];
	MyWell.GetBoard(LocalWell);
	//sf::Color LocalColor;


	//Drawing Rectangle shape
	sf::RectangleShape MyWellSFML;

	////the size of one square in the array
	sf::RectangleShape MySquare;
	MyWellSFML.setSize(sf::Vector2f((WELL_WIDTH*BLOCK_SIZE_PIXEL),(WELL_HEIGHT*BLOCK_SIZE_PIXEL)));
	MyWellSFML.setOutlineThickness(1);
	MyWellSFML.setOutlineColor(sf::Color(0,0,255));
	MyWellSFML.setFillColor(sf::Color(0,124,111)); //Colorblue
	MyWellSFML.setPosition(LAYOUT_BOARD_LEFT,LAYOUT_BOARD_TOP);
	Window.draw(MyWellSFML);

	//My square
	MySquare.setSize(sf::Vector2f(BLOCK_SIZE_PIXEL,BLOCK_SIZE_PIXEL));
	MySquare.setOutlineThickness(2);
	MySquare.setOutlineColor(sf::Color(0,0,0,255));
	MySquare.setFillColor(sf::Color(45,45,45));

	//Loop through the 20x20 square and set the location
	for (int row = 0; row < WELL_HEIGHT; row++)
	{
		for (int col = 0; col < WELL_WIDTH; col++)
		{
			if(LocalWell[row][col] == ' ')
			{

				MySquare.setPosition(LocationSide + (col*BLOCK_SIZE_PIXEL), LocationTop + (row*BLOCK_SIZE_PIXEL));
				Window.draw(MySquare);
			}
		}
	}

	for(int row = 0; row< WELL_HEIGHT; row++)
	{
		for(int col = 0; col < WELL_WIDTH; col++)
		{
			if(LocalWell[row][col] != ' ')
			{
				MySquare.setFillColor(ConvertToSfmlColor(LocalWell[row][col]));
				MySquare.setPosition(LocationSide + (col*BLOCK_SIZE_PIXEL), LocationTop + (row*BLOCK_SIZE_PIXEL));
				Window.draw(MySquare);
			}
		}
	}
}


/*======================================================
Function Name: ConvertToSfmlColor	(SF::COLOR)
Arguements: TetriminoInPlay	(TETRIMINO)
Return: None
Purpose: Converts the previous character color codes
into actuall SFML color that can be called
to convert a current character color to actual
color.
========================================================*/
sf::Color Game::ConvertToSfmlColor(char Color)
{
	//variables
	sf::Color LocalColor;

	switch(Color)
	{
	case 'r':
		LocalColor = sf::Color(255,0,0); //red
		break;

	case 'y':
		LocalColor = sf::Color(255,255,0); //yellow
		break;

	case 't':
		LocalColor = sf::Color(0,255,255); //teal
		break;

	case 'b':
		LocalColor = sf::Color(0,0,255); //blue
		break;

	case 'o':
		LocalColor = sf::Color(255,128,0); //orange
		break;

	case 'g':
		LocalColor = sf::Color(1,223,1); //green
		break;

	case 'p':
		LocalColor = sf::Color(128,0,255); //purple
		break;
	}
	return LocalColor;
}

/*======================================================
Function Name: DrawTetrimino	(VOID)
Arguements: TetriminoInPlay	(TETRIMINO)
LocationTop	(INT)
LocationSide	(INT)
BlockPixel	(INT)
Return: None
Purpose: Draws the window and layout and title bar
========================================================*/
void Game::DrawTetrimino(Tetrimino TetriminoInPlay, int LocationTop, int LocationSide,int BlockPixel)
{
	//variables
	int LocalGrid[TETRIMINO_GRID_SIZE][TETRIMINO_GRID_SIZE];
	sf::RectangleShape MySquare;
	TetriminoInPlay.getGrid(LocalGrid);
	Location LocalLocation = TetriminoInPlay.getLocation();
	sf::Color SfLocalColor;

	for (int row = 0; row < TETRIMINO_GRID_SIZE; row++)
	{
		for (int col = 0; col < TETRIMINO_GRID_SIZE; col++)
		{
			if(LocalGrid[row][col] == 1)
			{
				MySquare.setSize(sf::Vector2f(BLOCK_SIZE_PIXEL,BLOCK_SIZE_PIXEL));
				MySquare.setOutlineThickness(2);
				MySquare.setOutlineColor(sf::Color(0,0,0,255));
				MySquare.setFillColor(ConvertToSfmlColor(TetriminoInPlay.getColor()));
				MySquare.setPosition(sf::Vector2f(LocationSide +(LocalLocation.col+ col)*BLOCK_SIZE_PIXEL , LocationTop +(LocalLocation.row+row)*BLOCK_SIZE_PIXEL));
				Window.draw(MySquare);
			}	
		}
	}

}


/*=====================================================
Function Name: ProcessSplashScreen	(GameState)
Arguements: NONE
Return: TETRIS_PLAY OR TETRIS_HIGHSCORE
Purpose: Draws a splash screen for the tetris game
and checks if user wants to play the game or
close window or see the highscore board
======================================================*/
GameState Game::ProcessSplashScreen()
{
	IfstreamHighscore();
	//TempHighScoreOutput();
	//variables
	sf::Text PressSpaceText;
	sf::Text SpaceText;
	sf::Text text;
	sf::Text SplashScreenHighScoreButton1;
	sf::Text SplashScreenHighScoreButton2;
	//displaying the image
	SpriteImage.setTexture(SplashScreenImage);

	//First Text
	text.setFont(MyFont);
	text.setColor(sf::Color::Black);
	text.setString("Welcome To Tetris!");
	text.setStyle(sf::Text::Underlined);
	text.setCharacterSize(60);
	text.setPosition(60,50);

	//Press Space To Play
	PressSpaceText.setFont(MyFont);
	PressSpaceText.setColor(sf::Color(0,0,0,255));
	PressSpaceText.setString("  Press \n      For Game Play");
	PressSpaceText.setCharacterSize(30);
	PressSpaceText.setPosition(50,500);

	//Space text
	SpaceText.setFont(ArcadeFont);
	SpaceText.setStyle(sf::Text::Italic);
	SpaceText.setColor(sf::Color(255,0,0));
	SpaceText.setString("SPACE");
	SpaceText.setCharacterSize(50);
	SpaceText.setPosition(170,485);


	//h to switch to highscore text
	SplashScreenHighScoreButton1.setFont(MyFont);
	SplashScreenHighScoreButton1.setColor(sf::Color(0,0,0,255));
	SplashScreenHighScoreButton1.setString("                  Press \n For High Score Board");
	SplashScreenHighScoreButton1.setCharacterSize(30);
	SplashScreenHighScoreButton1.setPosition(45,300);

	// H text
	SplashScreenHighScoreButton2.setFont(ArcadeFont);
	SplashScreenHighScoreButton2.setColor(sf::Color(255,0,0));
	SplashScreenHighScoreButton2.setString("H");
	SplashScreenHighScoreButton2.setCharacterSize(40);
	SplashScreenHighScoreButton2.setPosition(290,290);

	//while window open
	while (Window.isOpen())
	{
		while(Window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				Window.close();
			}

			//switch to the game
			if(event.type == sf::Event::KeyPressed 
				&& event.key.code == sf::Keyboard::Space)
			{
				return TETRIS_PLAY;
			}

			//switch to highscore menu
			if(event.type == sf::Event::KeyPressed 
				&& event.key.code == sf::Keyboard::H)
			{
				return TETRIS_HIGHSCORE;
			}
		}
		Window.clear();
		Window.draw(SpriteImage);
		Window.draw(text);
		Window.draw(PressSpaceText);
		Window.draw(SplashScreenHighScoreButton1);
		Window.draw(SplashScreenHighScoreButton2);
		Window.draw(SpaceText);
		Window.display();
	}




}


/*=====================================================
Function Name: ProcessGameScreen	(GameState)
Arguements: NONE
Return: TETRIS_GAMEOVER
Purpose: the main window where you play the game
======================================================*/
GameState Game::ProcessGameScreen()
{
	TetriminoInPlay = new Tetrimino;
	TetriminoOnDeck = new Tetrimino;
	MyWell = new Well;
	int Counter = 0;

	TetriminoInPlay->setLocation(-1,6);

	//variables
	sf::RectangleShape NextSquare;
	sf::RectangleShape ScoreSquare;
	sf::RectangleShape ControlSquare;
	sf::Text text;
	sf::Text MyText2;
	sf::Text MyName;
	sf::Text CreatedByText;
	sf::Text ControlTextTitle;
	sf::Text ScoreSFML;
	sf::Text RotationsText;
	sf::Text ZText;
	sf::Text XText;
	sf::Text RightArrowText;
	sf::Text LeftArrowText;
	sf::Text DashText1;
	sf::Text DashText2;
	sf::Text DashText3;
	sf::Text DashText4;
	int ScoreRows;

	//Score Text
	text.setFont(MyFont);
	text.setColor(sf::Color::Black);
	text.setString("Score");
	text.setCharacterSize(50);
	text.setPosition(520,160);

	//Score Square drawing
	ScoreSquare.setSize(sf::Vector2f(200,75));
	ScoreSquare.setOutlineThickness(2);
	ScoreSquare.setOutlineColor(sf::Color(0,0,0,255));
	ScoreSquare.setFillColor(sf::Color(45,45,45));
	ScoreSquare.setPosition(505,220);

	//Next Text
	MyText2.setFont(MyFont);
	MyText2.setColor(sf::Color::Black);
	MyText2.setString("Next");
	MyText2.setCharacterSize(30);
	MyText2.setPosition(480,20);

	//Score Square Drawing
	NextSquare.setSize(sf::Vector2f(125,100));
	NextSquare.setOutlineThickness(2);
	NextSquare.setOutlineColor(sf::Color(0,0,0,255));
	NextSquare.setFillColor(sf::Color(45,45,45));
	NextSquare.setPosition(460,60);

	//MyName Text
	MyName.setFont(MyFont);
	MyName.setColor(sf::Color(0,0,0,255));
	MyName.setString("Edward Koroteev");
	MyName.setCharacterSize(20);
	MyName.setPosition(600,625);

	//Created By text
	CreatedByText.setFont(MyFont);
	CreatedByText.setColor(sf::Color(0,0,0,255));
	CreatedByText.setString("Created By");
	CreatedByText.setCharacterSize(10);
	CreatedByText.setPosition(525,635);

	//create text for controls
	ControlTextTitle.setFont(MyFont);
	ControlTextTitle.setColor(sf::Color(0,0,0,255));
	ControlTextTitle.setString("Controls");
	ControlTextTitle.setCharacterSize(30);
	ControlTextTitle.setPosition(530,325);

	//Control box inside text
	RotationsText.setFont(MyFont);
	RotationsText.setColor(sf::Color(0,0,0,255));
	RotationsText.setString("\t Press \n To Rotate Right \n\t Press \n To Rotate Left \n\t Press \n To Move Left \n\t Press \n To Move Right");
	RotationsText.setCharacterSize(22);
	RotationsText.setPosition(480,365);

	//x text inside the control box
	XText.setFont(ArcadeFont);
	XText.setColor(sf::Color(255,0,0));
	XText.setString("X");
	XText.setCharacterSize(33);
	XText.setPosition(595,356);

	//z text inside the control box
	ZText.setFont(ArcadeFont);
	ZText.setColor(sf::Color(255,0,0));
	ZText.setString("Z");
	ZText.setCharacterSize(33);
	ZText.setPosition(595,419);

	//left arrow text inside control box
	LeftArrowText.setFont(ArcadeFont);
	LeftArrowText.setColor(sf::Color(255,0,0));
	LeftArrowText.setString("Left Arrow");
	LeftArrowText.setCharacterSize(27);
	LeftArrowText.setPosition(595,485);

	//right arrow text inside control box
	RightArrowText.setFont(ArcadeFont);
	RightArrowText.setColor(sf::Color(255,0,0));
	RightArrowText.setString("Right Arrow");
	RightArrowText.setCharacterSize(27);
	RightArrowText.setPosition(595,547);

	//dash bullitin inside control box
	DashText1.setFont(MyFont);
	DashText1.setColor(sf::Color(255,0,0));
	DashText1.setString("-");
	DashText1.setCharacterSize(30);
	DashText1.setPosition(460,358);

	//dash 2 inside control box
	DashText2.setFont(MyFont);
	DashText2.setColor(sf::Color(255,0,0));
	DashText2.setString("-");
	DashText2.setCharacterSize(30);
	DashText2.setPosition(460,420);

	//dash 3 inside control box
	DashText3.setFont(MyFont);
	DashText3.setColor(sf::Color(255,0,0));
	DashText3.setString("-");
	DashText3.setCharacterSize(30);
	DashText3.setPosition(460,482);

	//dash 4 inside control box
	DashText4.setFont(MyFont);
	DashText4.setColor(sf::Color(255,0,0));
	DashText4.setString("-");
	DashText4.setCharacterSize(30);
	DashText4.setPosition(460,544);

	//draw control box
	ControlSquare.setSize(sf::Vector2f(325,260));
	ControlSquare.setOutlineThickness(2);
	ControlSquare.setOutlineColor(sf::Color(0,0,0,255));
	ControlSquare.setFillColor(sf::Color(45,45,45));
	ControlSquare.setPosition(450,360);

	//Draw score
	ScoreSFML.setFont(MyFont);
	ScoreSFML.setColor(sf::Color(255,0,0));
	ScoreSFML.setCharacterSize(30);
	ScoreSFML.setPosition(600,240);

	while(Window.isOpen())
	{
		while(Window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				Window.close();
			}

			//Left arrow pressed moce left
			if(event.type == sf::Event::KeyPressed 
				&& event.key.code == sf::Keyboard::Left)
			{
				cout << "Left Arrow" << endl;
				TetriminoInPlay->moveLeft();

				//test if tetrimino fits
				if(MyWell->TetriminoFit(*TetriminoInPlay) == false)
				{
					TetriminoInPlay->moveRight();
				}

				//sound play
				sound.setBuffer(soundBuffer);
				sound.play();
			}

			//Right arrow pressed move right
			if(event.type==sf::Event::KeyPressed
				&& event.key.code == sf::Keyboard::Right)
			{
				cout << "Right Arrow" << endl;
				TetriminoInPlay->moveRight();

				//test if tetrimino fits
				if(MyWell->TetriminoFit(*TetriminoInPlay) == false)
				{
					TetriminoInPlay->moveLeft();
				}

				//sound play
				sound.setBuffer(soundBuffer);
				sound.play();
			}

			//Z pressed rotate left
			if(event.type==sf::Event::KeyPressed 
				&& event.key.code == sf::Keyboard::Z)
			{
				cout << "Z pressed (rotate Left)" << endl;
				TetriminoInPlay->rotateLeft();

				//check if tetrimino fits
				if(MyWell->TetriminoFit(*TetriminoInPlay) == false)
				{
					TetriminoInPlay->rotateRight();
				}
				sound.setBuffer(soundBuffer);
				sound.play();
			}

			//X pressed rotate right
			if(event.type==sf::Event::KeyPressed
				&& event.key.code == sf::Keyboard::X)
			{
				cout << "X pressed (rotate right)" << endl;
				TetriminoInPlay->rotateRight();

				//check if tetrimino fits
				if(MyWell->TetriminoFit(*TetriminoInPlay) == false)
				{
					TetriminoInPlay->rotateLeft();
				}

				//Sound effects
				sound.setBuffer(soundBuffer);
				sound.play();
			}

			//Down arrow pressed move down
			if(event.type ==sf::Event::KeyPressed
				&& event.key.code ==sf::Keyboard::Down)
			{
				cout << "Down Arrow" << endl;
				TetriminoInPlay->moveDown();

				//check if tetrimino fits
				if (MyWell->TetriminoFit(*TetriminoInPlay) == false)
				{
					TetriminoInPlay->moveUp();
				}

				//sound play
				sound.setBuffer(soundBuffer);
				sound.play();
			}

			//Up arrow pressed
			if(event.type == sf::Event::KeyPressed
				&& event.key.code == sf::Keyboard::Up)
			{
				cout << "Up Arrow (rotate right)" << endl;
				TetriminoInPlay->rotateRight();

				//check if tetrimino fits
				if(MyWell->TetriminoFit(*TetriminoInPlay) == false)
				{
					TetriminoInPlay->rotateLeft();
				}

				//sound play
				sound.setBuffer(soundBuffer);
				sound.play();
			}
		}

		Counter++;
		if(Counter == 15)
		{
			TetriminoInPlay->moveDown();
			Counter = 0;
		}

		ScoreSFML.setString(to_string(Score));

		if (MyWell->TetriminoFit(*TetriminoInPlay)==false)
		{
			TetriminoInPlay->moveUp();
			MyWell->AddTetriminoToWell(*TetriminoInPlay);
			delete TetriminoInPlay;
			TetriminoInPlay = TetriminoOnDeck;
			TetriminoOnDeck = new Tetrimino;
			TetriminoInPlay->setLocation(-1,6);

			ScoreRows = MyWell->ClearFullRows();

			if(ScoreRows > 0)
			{
				Score +=  pow(4,(ScoreRows));
				//draw score to well
				ScoreSFML.setString(to_string(Score));
			}
		}

		if(MyWell->TopReached())
		{
			delete MyWell;
			return TETRIS_GAME_OVER;
		}

		//Draw new Frame
		Window.clear(sf::Color(0,91,82));
		DrawWell(*MyWell,LAYOUT_BOARD_TOP,LAYOUT_BOARD_LEFT,BLOCK_SIZE_PIXEL);
		Window.draw(text);
		Window.draw(MyText2);
		Window.draw(NextSquare);
		Window.draw(ScoreSquare);
		Window.draw(ScoreSFML);
		Window.draw(MyName);
		Window.draw(CreatedByText);
		Window.draw(ControlSquare);
		Window.draw(RotationsText);
		Window.draw(XText);
		Window.draw(ZText);
		Window.draw(RightArrowText);
		Window.draw(LeftArrowText);
		Window.draw(DashText1);
		Window.draw(DashText2);
		Window.draw(DashText3);
		Window.draw(DashText4);
		Window.draw(ControlTextTitle);
		DrawTetrimino(*TetriminoInPlay,LAYOUT_BOARD_TOP,LAYOUT_BOARD_LEFT,BLOCK_SIZE_PIXEL);
		DrawTetrimino(*TetriminoOnDeck,LAYOUT_BOARD_TOP,LAYOUT_BOARD_LEFT,BLOCK_SIZE_PIXEL);
		Window.display();
	}
}


/*=====================================================
Function Name: ProcessGameOverScreen	(GameState)
Arguements: NONE
Return: returns TETRIS_SPLASH OR TETRIS_PLAY
Purpose: Prompts the game over screen when you loose the
game
======================================================*/
GameState Game::ProcessGameOverScreen()
{
	DetermineHighScore();

	//variables
	sf::Text HighScoreBoard;
	sf::Text TransferToMenuText1;
	sf::Text TransferToMenuText2;
	sf::Text ReplayGameText1;
	sf::Text ReplayGameText2;
	sf::Text GameOverTextWord1;
	sf::Text GameOverTextWord2;
	sf::Text GameOverScoreText;
	sf::RectangleShape TopLine;
	sf::RectangleShape LeftLine;
	sf::RectangleShape RightLine;
	sf::RectangleShape BottomLine;
	int Counter = 0;
	int HighScorePosition;
	int x = 365;
	int y = 140;

	//Loading Image
	SpriteGameOverImage.setTexture(GameOverImage);

	//drawing Line top line
	TopLine.setSize(sf::Vector2f(400,4));
	TopLine.setFillColor(sf::Color(0,0,0,255));
	TopLine.setPosition(200,100);

	//drawing bottom line
	BottomLine.setSize(sf::Vector2f(400,4));
	BottomLine.setFillColor(sf::Color(0,0,0,255));
	BottomLine.setPosition(200,615);

	//drawing Right line
	RightLine.setSize(sf::Vector2f(4,519));
	RightLine.setFillColor(sf::Color(0,0,0,255));
	RightLine.setPosition(600,100);

	//drawing left line
	LeftLine.setSize(sf::Vector2f(4,519));
	LeftLine.setFillColor(sf::Color(0,0,0,255));
	LeftLine.setPosition(200,100);

	//Game text above box
	GameOverTextWord1.setFont(MyFont);
	GameOverTextWord1.setColor(sf::Color(0,0,0,255));
	GameOverTextWord1.setCharacterSize(50);
	GameOverTextWord1.setString("Game");
	GameOverTextWord1.setPosition(230,45);

	//Over text above box
	GameOverTextWord2.setFont(ArcadeFont);
	GameOverTextWord2.setColor(sf::Color(255,0,0));
	GameOverTextWord2.setCharacterSize(70);
	GameOverTextWord2.setString("Over");
	GameOverTextWord2.setPosition(420,30);

	//score Text inside box
	GameOverScoreText.setFont(MyFont);
	GameOverScoreText.setColor(sf::Color(0,0,255));
	GameOverScoreText.setCharacterSize(50);
	GameOverScoreText.setStyle(sf::Text::Underlined);
	GameOverScoreText.setString("SCORE");
	GameOverScoreText.setPosition(310,105);

	//transfer to menu in game over
	TransferToMenuText1.setFont(MyFont);
	TransferToMenuText1.setColor(sf::Color(0,0,0,255));
	TransferToMenuText1.setCharacterSize(30);
	TransferToMenuText1.setString("Press \n For Menu");
	TransferToMenuText1.setPosition(20,150);

	//m to manu text
	TransferToMenuText2.setFont(ArcadeFont);
	TransferToMenuText2.setColor(sf::Color(255,0,0));
	TransferToMenuText2.setCharacterSize(47);
	TransferToMenuText2.setString("M");
	TransferToMenuText2.setPosition(145,138);

	//reply the game text
	ReplayGameText1.setFont(MyFont);
	ReplayGameText1.setColor(sf::Color(0,0,0,255));
	ReplayGameText1.setCharacterSize(30);
	ReplayGameText1.setString("Press \n To Replay");
	ReplayGameText1.setPosition(610,400);

	//p text for reply
	ReplayGameText2.setFont(ArcadeFont);
	ReplayGameText2.setColor(sf::Color(255,0,0));
	ReplayGameText2.setCharacterSize(47);
	ReplayGameText2.setString("P");
	ReplayGameText2.setPosition(727,387);

	//HighScore
	HighScoreBoard.setFont(MyFont);
	HighScoreBoard.setColor(sf::Color(0,0,0,255));
	HighScoreBoard.setCharacterSize(40);

	while(Window.isOpen())
	{
		while(Window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				Window.close();
			}

			//if space
			if(event.type == sf::Event::KeyPressed
				&& event.key.code == sf::Keyboard::P)
			{
				Score = 0;
				return TETRIS_PLAY;
			}
			if(event.type == sf::Event::KeyPressed
				&& event.key.code == sf::Keyboard::M)
			{
				Score = 0;
				return TETRIS_SPLASH;
			}
		}
		Window.clear(sf::Color::White);
		Window.draw(SpriteGameOverImage);
		Window.draw(RightLine);
		Window.draw(GameOverTextWord2);
		Window.draw(GameOverScoreText);
		Window.draw(GameOverTextWord1);
		Window.draw(TransferToMenuText1);
		Window.draw(TransferToMenuText2);
		Window.draw(ReplayGameText1);
		Window.draw(ReplayGameText2);
		Window.draw(TopLine);
		Window.draw(LeftLine);

		//if(Counter == 0)
		//{
			for (int i = 0; i < HIGHSCORE_ARRAY_SIZE; i++)
			{
				y += 40;
				HighScoreBoard.setPosition(x,y);
				HighScoreBoard.setString(to_string (HighScoreArray[i]));
				Window.draw(HighScoreBoard);
				cout << HighScoreArray[i];
			}
			Counter++;
		//}
		//Window.draw(HighScoreArray);
		Window.draw(BottomLine);
		Window.display();
	}
}


/*=====================================================
Function Name: ProcessHighScoreScreen	(GameState)
Arguements: NONE
Return: returns TETRIS_SPLASH
Purpose: prompts the highscore manu from the splash
======================================================*/
GameState Game::ProcessHighScoreScreen()
{
	// variables 
	sf::RectangleShape TTetrimino1;
	sf::RectangleShape TTetrimino2;
	sf::RectangleShape TTetrimino3;
	sf::RectangleShape TTetrimino4;
	sf::RectangleShape TopLine;
	sf::RectangleShape LeftLine;
	sf::RectangleShape RightLine;
	sf::RectangleShape BottomLine;
	sf::Text GameOverTextWord1;
	sf::Text GameOverTextWord2;
	sf::Text PressBackspaceText;
	sf::Text HighScoreText1;
	sf::Text HighScoreText2;
	sf::Text BackspaceText;
	//Loading Image
	SpriteGameOverImage.setTexture(GameOverImage);

	//drawing Line top line
	TopLine.setSize(sf::Vector2f(400,4));
	TopLine.setFillColor(sf::Color(0,0,0,255));
	TopLine.setPosition(350,100);

	//drawing bottom line
	BottomLine.setSize(sf::Vector2f(400,4));
	BottomLine.setFillColor(sf::Color(0,0,0,255));
	BottomLine.setPosition(351,615);

	//drawing Right line
	RightLine.setSize(sf::Vector2f(4,519));
	RightLine.setFillColor(sf::Color(0,0,0,255));
	RightLine.setPosition(750,100);

	//drawing left line
	LeftLine.setSize(sf::Vector2f(4,519));
	LeftLine.setFillColor(sf::Color(0,0,0,255));
	LeftLine.setPosition(350,100);

	//High text above box
	HighScoreText1.setFont(MyFont);
	HighScoreText1.setColor(sf::Color(0,0,0,255));
	HighScoreText1.setCharacterSize(50);
	HighScoreText1.setString("HIGH");
	HighScoreText1.setPosition(388,43);

	//Score text above box
	HighScoreText2.setFont(ArcadeFont);
	HighScoreText2.setColor(sf::Color(255,0,0));
	HighScoreText2.setCharacterSize(70);
	HighScoreText2.setString("SCORE");
	HighScoreText2.setPosition(540,27);

	//go back to manu text
	PressBackspaceText.setFont(MyFont);
	PressBackspaceText.setColor(sf::Color(0,0,0,255));
	PressBackspaceText.setCharacterSize(30);
	PressBackspaceText.setString("Press \n             For Menu");
	PressBackspaceText.setPosition(25,400);

	//Backspace Text
	BackspaceText.setFont(ArcadeFont);
	BackspaceText.setColor(sf::Color(255,0,0));
	BackspaceText.setCharacterSize(43);
	BackspaceText.setString("Backspace");
	BackspaceText.setPosition(129,391);

	//draw tetrimino piece
	TTetrimino1.setSize(sf::Vector2f(BLOCK,BLOCK));
	TTetrimino1.setOutlineThickness(2);
	TTetrimino1.setOutlineColor(sf::Color(0,0,0,255));
	TTetrimino1.setFillColor(sf::Color(0,255,0));
	TTetrimino1.setPosition(150,100);

	//draw block 2
	TTetrimino2.setSize(sf::Vector2f(BLOCK,BLOCK));
	TTetrimino2.setOutlineThickness(2);
	TTetrimino2.setOutlineColor(sf::Color(0,0,0,255));
	TTetrimino2.setFillColor(sf::Color(0,255,0));
	TTetrimino2.setPosition(150,(100+BLOCK));

	//draw block 3
	TTetrimino3.setSize(sf::Vector2f(BLOCK,BLOCK));
	TTetrimino3.setOutlineThickness(2);
	TTetrimino3.setOutlineColor(sf::Color(0,0,0,255));
	TTetrimino3.setFillColor(sf::Color(0,255,0));
	TTetrimino3.setPosition((152+BLOCK),(100+BLOCK));

	//draw block 4
	TTetrimino4.setSize(sf::Vector2f(BLOCK,BLOCK));
	TTetrimino4.setOutlineThickness(2);
	TTetrimino4.setOutlineColor(sf::Color(0,0,0,255));
	TTetrimino4.setFillColor(sf::Color(0,255,0));
	TTetrimino4.setPosition((148-BLOCK),(100+BLOCK));
	//===================================================================================
	while(Window.isOpen())
	{
		while(Window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				Window.close();
			}

			if(event.type == sf::Event::KeyPressed
				&& event.key.code == sf::Keyboard::BackSpace)
			{
				return TETRIS_SPLASH;
			}

		}
		Window.clear(sf::Color::White);
		Window.draw(SpriteGameOverImage);
		Window.draw(TopLine);
		Window.draw(RightLine);
		Window.draw(LeftLine);
		Window.draw(HighScoreText1);
		Window.draw(HighScoreText2);
		Window.draw(BottomLine);
		Window.draw(BackspaceText);
		Window.draw(PressBackspaceText);
		DisplayScoreToSFML(500,130);
		Window.draw(TTetrimino1);
		Window.draw(TTetrimino2);
		Window.draw(TTetrimino3);
		Window.draw(TTetrimino4);
		Window.display();
	}
}


/*=====================================================================
Function Name: IfstreamHighscore	(VOID)
Arguements: NONE
Return: VOID
Purpose: Stores Whatever is in the HighScore
txt file and stores it into the HighScoreArray[HIGHSCORE_ARRAY_SIZE]
======================================================================*/
void Game::IfstreamHighscore()
{
	ifstream HighScoreInput;
	//string HighScoreInputName[HIGHSCORE_ARRAY_SIZE];
	HighScoreInput.open("HighScore.txt", ios::out);

	for(int i = 0; i < HIGHSCORE_ARRAY_SIZE; i++)
	{
		HighScoreInput >> HighScoreArray[i];
	}
	HighScoreInput.close();
}


/*=====================================================
Function Name: DetermineHighScore	(VOID)
Arguements: NONE
Return: VOID
Purpose: Calls the IfstreamHighscore so the 
HighScoreArray[HIGHSCORE_ARRAY_SIZE] is populated with
the right highscore, then determines wheather the
current score earned is good enough to be added to the 
array. If yes, It will rearrange the array and put
all the scores into the proper position
======================================================*/
void Game::DetermineHighScore()
{
	IfstreamHighscore();

	if(HighScoreArray[9] < Score)
	{
		HighScoreArray[9] = Score;

		for (int i = 8; i >= 0; i--)
		{
			if(HighScoreArray[i] < Score)
			{
				HighScoreArray[i+1]= HighScoreArray[i];
				HighScoreArray[i] = Score;
			}
		}
	}

	ofstream Output;
	Output.open("HighScore.txt", ofstream::out);
	for (int i = 0; i < HIGHSCORE_ARRAY_SIZE; i++)
	{
		Output << HighScoreArray[i] << endl;
	}
	Output.close();
}


/*===========================================================
Function Name: DisplayScoreToSFML	(VOID)
Arguements: int x, int y,
Return: VOID
Purpose: prompts the highscore to SFML. Call this Funcion
and pass the position of the Highscore array wherever
you want to display the score to SFML
============================================================*/
void Game::DisplayScoreToSFML(int x, int y)
{
	//variables
	DetermineHighScore();

	int HighScorePosition;

	for (int i = 0; i < HIGHSCORE_ARRAY_SIZE; i++)
	{
		y += 40;
		HighScoreBoard.setPosition(x,y);
		HighScoreBoard.setString(to_string (HighScoreArray[i]));
		Window.draw(HighScoreBoard);
		cout << HighScoreArray[i];
	}
}


void main()
{
	Game game;
	game.PlayGame();

	cin.get();
	cin.ignore();
}