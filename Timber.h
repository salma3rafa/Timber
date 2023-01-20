#ifndef TIMBER_H
#define TIMBER_H
#include <iostream>
#include <sstream>
#include "Animate.h"
#include "Message.h"

const int CLOUDS = 3;
const int XRES = 1920;//the resolution of the screen
const int YRES = 1080;
const float TIME = 6.f;//time life
const float TIMEBARWIDTH = 400.f;//the size of the time line
const float TIMEBARHEIGHT = 80.f;
const float LOGSPEEDY = -1500.f;//the speed of the LOG u cut
const int NUM_BRANCHES = 6;//the Number of branches that shows up
const float AXE_POSITION_LEFT = 700;//the position of the AXE
const float AXE_POSITION_RIGHT = 1075;

typedef map<int, Animate*> Animap;//for maping the screen
typedef map<int, Animate*>::iterator AniIt;

enum class side { LEFT, RIGHT, NONE };//the directions of the Charachter


class Timper
{
public:
	Timper();
	void initialiseSprites();//function for setting the Graphics
	void initialiseMessages();//Function to show the Messages to the Screen
	void initialiseTime();//function to set the Time
	void Start();//function to Start the game
	void CutTree(side aSide);
	//precondition this function takes 1 argument which is the direction of cutting
	//postcondition the log had been cut in the specific dir
	void Draw(bool aPaused);//this functioin to Draw the Graphics
	void UpdateSprites(bool& aPaused, bool& aAcceptInput);
	//preconditioin  takes 2 bool arguments 
	//postcondition the screen had been updated
	void updateBranches(int seed);
	//precondition takes 1 agument which is the new seed for the random branches
	//postcondition a new positioin for the branches had been generated
	void hideBranches();//function to hide the Branches the reaches to the ground

	//all these pointers for sprites
	Animate* m_pPlayer;//to set the Charachter
	Animate* m_pBG;//to set the back ground
	Animate* m_pTree;//to set the tree
	Animate* m_pBee;//to set the bee
	Animate* m_pRIP;//to set the Rip Stone
	Animate* m_pAxe;//to set the Axe
	Animate* m_pLog;//to set the log
	Message* m_pMessage;//to set the Messages to the screen
	Message* m_pScore;// to set the score 
	Message* m_pFPS;//to show the frames
	Sound m_Alarm;// to set the alarm sound
	Sprite m_Branches[NUM_BRANCHES];//to set the branches
	side m_BranchPositions[NUM_BRANCHES];//to set the branch position
	RectangleShape m_TimeBar;//shape of time bar
	Animap m_mClouds;//to map the clouds
	RenderWindow* m_pWindow;//to open window
	float m_LogSpeedX{ 0.0f };//the speed of the cut log
private:
	float m_TimeBarDelta{ 0.0f };
	int m_Score{ 0 };
	float m_TimeRemaining{ TIME };
	side m_PlayerSide{ side::LEFT };
	Texture m_BranchTexture;
	Clock m_Clock;
	Time m_dt;
};
#endif // !TIMBER_H

