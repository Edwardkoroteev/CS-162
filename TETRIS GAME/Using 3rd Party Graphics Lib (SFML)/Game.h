#ifndef GAME
#define GAME
#include <SFML/Graphics.hpp> 
#include"Well.h"
#include"Tetrimino.h"
#include<fstream>
#include<SFML/Audio.hpp>

enum GameState {TETRIS_SPLASH,TETRIS_PLAY,TETRIS_GAME_OVER,TETRIS_HIGHSCORE};

const int LAYOUT_WINDOW_WIDTH = 800;
const int LAYOUT_WINDOW_HEIGHT = 650;
const int LAYOUT_BOARD_TOP = 30;
const int LAYOUT_BOARD_LEFT = 50;
const int BLOCK_SIZE_PIXEL = 25;
const int HIGHSCORE_ARRAY_SIZE = 10;
//==============================temp==================================
const int BLOCK = 50;
//====================================================================

class Game
{
private:
	sf::Text HighScoreBoard;
	int HighScoreArray[HIGHSCORE_ARRAY_SIZE];
	sf::RenderWindow Window;
	Well *MyWell;
	Tetrimino* TetriminoInPlay;
	Tetrimino *TetriminoOnDeck;
	//==============================
	//Image
	//splash screen
	sf::Texture SplashScreenImage;
	sf::Sprite SpriteImage;
	//game over screen
	sf::Texture GameOverImage;
	sf::Sprite SpriteGameOverImage;
	//==============================
	//font
	sf::Font MyFont;
	sf::Font ArcadeFont;
	sf::Font HaloFont;
	//=========================
	//sound Or Music
	sf::Sound sound;
	sf::SoundBuffer soundBuffer;
	sf::Music Music;
	//========================
	sf::Event event;
	int Score;
	GameState ProcessGameScreen();
	GameState ProcessSplashScreen();
	GameState ProcessGameOverScreen();
	GameState ProcessHighScoreScreen();
	void DrawWell(Well MyWell, int LocationTop, int LocationSide, int BlockPixel);
	sf::Color ConvertToSfmlColor(char Color);
	void DrawTetrimino(Tetrimino TetriminoInPlay, int LocationTop, int LocationSide,int BlockPixel);
	void IfstreamHighscore();
	void TempHighScoreOutput();
	void DetermineHighScore();
	void DisplayScoreToSFML(int x, int y);
public:

	//constructor 
	Game();
	void PlayGame();
};

#endif