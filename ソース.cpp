<<<<<<< HEAD:up/ã‚½ãƒ¼ã‚¹.cpp
#include "DxLib.h"
#include <stdio.h>
#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>
#include <wingdi.h>

#pragma warning(disable : 4244)
#pragma warning(disable : 26812)
#pragma warning(disable : 26451)

/********************************************************************
* —ñ‹“‘Ì‚ÌéŒ¾
********************************************************************/
enum GAME_MODE {
	GAME_TITLE,
	GAME_INIT,
	GAME_END,
	GAME_MAIN,
	GAME_RESULT,
	GAME_OVER,
	END = 99
};

/********************************************************************
* ’è”‚ÌéŒ¾
********************************************************************/

//‚¨[‚¢‚¨’ƒ


/********************************************************************
* •Ï”‚ÌéŒ¾
********************************************************************/
int g_OldKey;    // ‘O‰ñ‚Ì“ü—ÍƒL[
int g_NowKey;    // ¡‰ñ‚Ì“ü—ÍƒL[
int g_KeyFlg;    // “ü—ÍƒL[î•ñ

int g_MouseX;    // ƒ}ƒEƒX‚ÌXÀ•W
int g_MouseY;    // ƒ}ƒEƒX‚ÌYÀ•W

int g_GameState;



/*ƒTƒEƒ“ƒh*/


/********************************************************************
* \‘¢‘Ì‚ÌéŒ¾
********************************************************************/



/***********************************************
  * ŠÖ”‚Ìƒvƒƒgƒ^ƒCƒvéŒ¾
***********************************************/
// ƒQ[ƒ€‰Šú‰»ˆ—
void GameInit(void);
// ƒQ[ƒ€ƒƒCƒ“ˆ—
void GameMain(void);
// ƒQ[ƒ€ƒ^ƒCƒgƒ‹•`‰æˆ—
void DrawGameTitle(void);
// ƒGƒ“ƒh•`‰æˆ—
void DrawEnd(void);
// ƒQ[ƒ€ƒNƒŠƒA[‚Ìˆ—
void DrawGameResult(void);
// ƒQ[ƒ€ƒI[ƒo[•`‰æˆ—
void DrawGameOver(void);

// ‰æ‘œ“Ç‚İ‚İ
int LoadImages();

//ƒTƒEƒ“ƒh
int LoadSounds(void);

/*****************************************************
 * ƒvƒƒOƒ‰ƒ€‚ÌŠJn
 ****************************************************/
int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_
	HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd) {


	SetMainWindowText("Match 3"); // ƒ^ƒCƒgƒ‹‚ğİ’è

	ChangeWindowMode(TRUE);   // ƒEƒBƒ“ƒhƒEƒ‚[ƒh‚Å‹N“®


	if (DxLib_Init() == -1)   // DXƒ‰ƒCƒuƒ‰ƒŠ‚Ì‰Šú‰»ˆ—
		return -1;

	SetDrawScreen(DX_SCREEN_BACK); // •`‰ææ‰æ–Ê‚ğ— ‚É‚·‚é

	// ‰æ‘œ“Ç‚İ‚İ
	if (LoadImages() == -1)
		return -1;

	//ƒTƒEƒ“ƒh“Ç‚İ‚İ
	if (LoadSounds() == -1)
		return -1;

	// ƒQ[ƒ€ƒ‹[ƒv
	while (ProcessMessage() == 0 && g_GameState != END && !(g_KeyFlg & PAD_INPUT_START)) {


		// “ü—ÍƒL[æ“¾
		g_OldKey = g_NowKey;
		g_NowKey = GetMouseInput();
		g_KeyFlg = g_NowKey & ~g_OldKey;

		//ƒ}ƒEƒX‚ÌˆÊ’u‚ğæ“¾
		GetMousePoint(&g_MouseX, &g_MouseY);

		ClearDrawScreen();  // ‰æ–Ê‚Ì‰Šú‰»

		switch (g_GameState) {

		case GAME_TITLE:DrawGameTitle(); break;		 //ƒQ[ƒ€ƒ^ƒCƒgƒ‹ˆ—

		case GAME_INIT: GameInit();  break;			 //ƒQ[ƒ€‰Šúˆ—

		case GAME_END: DrawEnd();  break;			 //ƒ‰ƒ“ƒLƒ“ƒO•`‰æˆ—

		case GAME_MAIN: GameMain();  break;			 //ƒGƒ“ƒh•`‰æˆ—

		case GAME_RESULT:DrawGameResult(); break;		 //ƒQ[ƒ€ƒƒCƒ“ˆ—

		case GAME_OVER: DrawGameOver(); break;		 // ƒQ[ƒ€ƒI[ƒo[•`‰æˆ—

		}

		ScreenFlip();    // — ‰æ–Ê‚Ì“à—e‚ğ•\‰æ–Ê‚É”½‰f

	}

	DxLib_End(); // DXƒ‰ƒCƒuƒ‰ƒŠg—p‚ÌI—¹ˆ—

	return 0; // ƒ\ƒtƒg‚ÌI—¹
}

/********************************************************************
* ƒQ[ƒ€ƒ^ƒCƒgƒ‹•`‰æˆ—(ƒƒjƒ…[‰æ–Ê)
********************************************************************/
void DrawGameTitle(void) {

}

/********************************************************************
* ƒQ[ƒ€‰Šú‰»ˆ—
********************************************************************/
void GameInit(void) {

}


/********************************************************************
* ƒQ[ƒ€ƒGƒ“ƒh•`‰æˆ—
********************************************************************/
void DrawEnd(void) {

}

/********************************************************************
* ƒQ[ƒ€ƒƒCƒ“
********************************************************************/
void GameMain(void) {

}

/********************************************************************
* ƒQ[ƒ€ƒNƒŠƒA•`‰æˆ—
********************************************************************/
void DrawGameResult(void) {

}

/********************************************************************
* ƒQ[ƒ€ƒI[ƒo[•`‰æˆ—
********************************************************************/
void DrawGameOver(void) {


}


/********************************************************************
* ‰æ‘œ“Ç‚İ‚İ
********************************************************************/
int LoadImages() {

	//// ƒ^ƒCƒgƒ‹
	//if ((g_TitleImage = LoadGraph("images/title.png")) == -1)return -1;

	////ƒXƒe[ƒW
	//if ((g_StageImage = LoadGraph("images/stage.png")) == -1)return -1;

	////ƒQ[ƒ€ƒNƒŠƒA
	//if ((g_GameClearImage = LoadGraph("images/gameclear.png")) == -1)return -1;

	////ƒQ[ƒ€ƒI[ƒo[
	//if ((g_GameOverImage = LoadGraph("images/gameover.png")) == -1)return -1;

	////ƒuƒƒbƒN‰æ‘œ
	//if (LoadDivGraph("images/block.png", 10, 10, 1, 48, 48, g_BlockImage) == -1)return -1;

	////ƒiƒ“ƒo[‰æ‘œ‚Ì“Ç‚İ‚İ
	//if (LoadDivGraph("images/number.png", 10, 10, 1, 60, 120, g_NumberImage) == -1)return -1;

	return 0;
}

/********************************************************************
* ƒTƒEƒ“ƒh“Ç‚İ‚İ
********************************************************************/
int LoadSounds(void) {

	////ƒ^ƒCƒgƒ‹
	//if ((g_TitleBGM = LoadSoundMem("sounds/muci_hono_r01.mp3")) == -1)return -1;
	////ƒNƒŠƒA
	//if ((g_GameClearSE = LoadSoundMem("sounds/muci_fan_06.mp3")) == -1)return -1;
	////ƒI[ƒo[
	//if ((g_GameOverSE = LoadSoundMem("sounds/muci_bara_07.mp3")) == -1)return -1;
	////ƒ}ƒEƒXƒNƒŠƒbƒN
	//if ((g_ClickSE = LoadSoundMem("sounds/ta_ta_warekie02.mp3")) == -1)return -1;
	////ƒuƒƒbƒNÁ‹
	//if ((g_TitleBGM = LoadSoundMem("sounds/ani_ta_biyon02.mp3")) == -1)return -1;
	////ƒuƒƒbƒNˆÚ“®
	//if ((g_TitleBGM = LoadSoundMem("sounds/ta_ta_doron01.mp3")) == -1)return -1;



	return 0;
}
=======
#include "DxLib.h"
#include <stdio.h>
#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>
#include <wingdi.h>

#pragma warning(disable : 4244)
#pragma warning(disable : 26812)
#pragma warning(disable : 26451)

/********************************************************************
* åˆ—æŒ™ä½“ã®å®£è¨€
********************************************************************/
enum GAME_MODE {
	GAME_TITLE,
	GAME_INIT,
	GAME_END,
	GAME_MAIN,
	GAME_RESULT,
	GAME_OVER,
	END = 99
};

/********************************************************************
* å®šæ•°ã®å®£è¨€
********************************************************************/




/********************************************************************
* å¤‰æ•°ã®å®£è¨€
********************************************************************/
int g_OldKey;    // å‰å›ã®å…¥åŠ›ã‚­ãƒ¼
int g_NowKey;    // ä»Šå›ã®å…¥åŠ›ã‚­ãƒ¼
int g_KeyFlg;    // å…¥åŠ›ã‚­ãƒ¼æƒ…å ±

int g_MouseX;    // ãƒã‚¦ã‚¹ã®Xåº§æ¨™
int g_MouseY;    // ãƒã‚¦ã‚¹ã®Yåº§æ¨™

int g_GameState;



/*ã‚µã‚¦ãƒ³ãƒ‰*/


/********************************************************************
* æ§‹é€ ä½“ã®å®£è¨€
********************************************************************/



/***********************************************
  * é–¢æ•°ã®ãƒ—ãƒ­ãƒˆã‚¿ã‚¤ãƒ—å®£è¨€
***********************************************/
// ã‚²ãƒ¼ãƒ åˆæœŸåŒ–å‡¦ç†
void GameInit(void);
// ã‚²ãƒ¼ãƒ ãƒ¡ã‚¤ãƒ³å‡¦ç†
void GameMain(void);
// ã‚²ãƒ¼ãƒ ã‚¿ã‚¤ãƒˆãƒ«æç”»å‡¦ç†
void DrawGameTitle(void);
// ã‚¨ãƒ³ãƒ‰æç”»å‡¦ç†
void DrawEnd(void);
// ã‚²ãƒ¼ãƒ ã‚¯ãƒªã‚¢ãƒ¼ã®å‡¦ç†
void DrawGameResult(void);
// ã‚²ãƒ¼ãƒ ã‚ªãƒ¼ãƒãƒ¼æç”»å‡¦ç†
void DrawGameOver(void);

// ç”»åƒèª­ã¿è¾¼ã¿
int LoadImages();

//ã‚µã‚¦ãƒ³ãƒ‰
int LoadSounds(void);

/*****************************************************
 * ãƒ—ãƒ­ã‚°ãƒ©ãƒ ã®é–‹å§‹
 ****************************************************/
int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_
	HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd) {


	SetMainWindowText("Match 3"); // ã‚¿ã‚¤ãƒˆãƒ«ã‚’è¨­å®š

	ChangeWindowMode(TRUE);   // ã‚¦ã‚£ãƒ³ãƒ‰ã‚¦ãƒ¢ãƒ¼ãƒ‰ã§èµ·å‹•


	if (DxLib_Init() == -1)   // DXãƒ©ã‚¤ãƒ–ãƒ©ãƒªã®åˆæœŸåŒ–å‡¦ç†
		return -1;

	SetDrawScreen(DX_SCREEN_BACK); // æç”»å…ˆç”»é¢ã‚’è£ã«ã™ã‚‹

	// ç”»åƒèª­ã¿è¾¼ã¿
	if (LoadImages() == -1)
		return -1;

	//ã‚µã‚¦ãƒ³ãƒ‰èª­ã¿è¾¼ã¿
	if (LoadSounds() == -1)
		return -1;

	// ã‚²ãƒ¼ãƒ ãƒ«ãƒ¼ãƒ—
	while (ProcessMessage() == 0 && g_GameState != END && !(g_KeyFlg & PAD_INPUT_START)) {


		// å…¥åŠ›ã‚­ãƒ¼å–å¾—
		g_OldKey = g_NowKey;
		g_NowKey = GetMouseInput();
		g_KeyFlg = g_NowKey & ~g_OldKey;

		//ãƒã‚¦ã‚¹ã®ä½ç½®ã‚’å–å¾—
		GetMousePoint(&g_MouseX, &g_MouseY);

		ClearDrawScreen();  // ç”»é¢ã®åˆæœŸåŒ–

		switch (g_GameState) {

		case GAME_TITLE:DrawGameTitle(); break;		 //ã‚²ãƒ¼ãƒ ã‚¿ã‚¤ãƒˆãƒ«å‡¦ç†

		case GAME_INIT: GameInit();  break;			 //ã‚²ãƒ¼ãƒ åˆæœŸå‡¦ç†

		case GAME_END: DrawEnd();  break;			 //ãƒ©ãƒ³ã‚­ãƒ³ã‚°æç”»å‡¦ç†

		case GAME_MAIN: GameMain();  break;			 //ã‚¨ãƒ³ãƒ‰æç”»å‡¦ç†

		case GAME_RESULT:DrawGameResult(); break;		 //ã‚²ãƒ¼ãƒ ãƒ¡ã‚¤ãƒ³å‡¦ç†

		case GAME_OVER: DrawGameOver(); break;		 // ã‚²ãƒ¼ãƒ ã‚ªãƒ¼ãƒãƒ¼æç”»å‡¦ç†

		}

		ScreenFlip();    // è£ç”»é¢ã®å†…å®¹ã‚’è¡¨ç”»é¢ã«åæ˜ 

	}

	DxLib_End(); // DXãƒ©ã‚¤ãƒ–ãƒ©ãƒªä½¿ç”¨ã®çµ‚äº†å‡¦ç†

	return 0; // ã‚½ãƒ•ãƒˆã®çµ‚äº†
}

/********************************************************************
* ã‚²ãƒ¼ãƒ ã‚¿ã‚¤ãƒˆãƒ«æç”»å‡¦ç†(ãƒ¡ãƒ‹ãƒ¥ãƒ¼ç”»é¢)
********************************************************************/
void DrawGameTitle(void) {

}

/********************************************************************
* ã‚²ãƒ¼ãƒ åˆæœŸåŒ–å‡¦ç†
********************************************************************/
void GameInit(void) {

}


/********************************************************************
* ã‚²ãƒ¼ãƒ ã‚¨ãƒ³ãƒ‰æç”»å‡¦ç†
********************************************************************/
void DrawEnd(void) {

}

/********************************************************************
* ã‚²ãƒ¼ãƒ ãƒ¡ã‚¤ãƒ³
********************************************************************/
void GameMain(void) {

}

/********************************************************************
* ã‚²ãƒ¼ãƒ ã‚¯ãƒªã‚¢æç”»å‡¦ç†
********************************************************************/
void DrawGameResult(void) {

}

/********************************************************************
* ã‚²ãƒ¼ãƒ ã‚ªãƒ¼ãƒãƒ¼æç”»å‡¦ç†
********************************************************************/
void DrawGameOver(void) {


}


/********************************************************************
* ç”»åƒèª­ã¿è¾¼ã¿
********************************************************************/
int LoadImages() {

	//// ã‚¿ã‚¤ãƒˆãƒ«
	//if ((g_TitleImage = LoadGraph("images/title.png")) == -1)return -1;

	////ã‚¹ãƒ†ãƒ¼ã‚¸
	//if ((g_StageImage = LoadGraph("images/stage.png")) == -1)return -1;

	////ã‚²ãƒ¼ãƒ ã‚¯ãƒªã‚¢
	//if ((g_GameClearImage = LoadGraph("images/gameclear.png")) == -1)return -1;

	////ã‚²ãƒ¼ãƒ ã‚ªãƒ¼ãƒãƒ¼
	//if ((g_GameOverImage = LoadGraph("images/gameover.png")) == -1)return -1;

	////ãƒ–ãƒ­ãƒƒã‚¯ç”»åƒ
	//if (LoadDivGraph("images/block.png", 10, 10, 1, 48, 48, g_BlockImage) == -1)return -1;

	////ãƒŠãƒ³ãƒãƒ¼ç”»åƒã®èª­ã¿è¾¼ã¿
	//if (LoadDivGraph("images/number.png", 10, 10, 1, 60, 120, g_NumberImage) == -1)return -1;

	return 0;
}

/********************************************************************
* ã‚µã‚¦ãƒ³ãƒ‰èª­ã¿è¾¼ã¿
********************************************************************/
int LoadSounds(void) {

	////ã‚¿ã‚¤ãƒˆãƒ«
	//if ((g_TitleBGM = LoadSoundMem("sounds/muci_hono_r01.mp3")) == -1)return -1;
	////ã‚¯ãƒªã‚¢
	//if ((g_GameClearSE = LoadSoundMem("sounds/muci_fan_06.mp3")) == -1)return -1;
	////ã‚ªãƒ¼ãƒãƒ¼
	//if ((g_GameOverSE = LoadSoundMem("sounds/muci_bara_07.mp3")) == -1)return -1;
	////ãƒã‚¦ã‚¹ã‚¯ãƒªãƒƒã‚¯
	//if ((g_ClickSE = LoadSoundMem("sounds/ta_ta_warekie02.mp3")) == -1)return -1;
	////ãƒ–ãƒ­ãƒƒã‚¯æ¶ˆå»
	//if ((g_TitleBGM = LoadSoundMem("sounds/ani_ta_biyon02.mp3")) == -1)return -1;
	////ãƒ–ãƒ­ãƒƒã‚¯ç§»å‹•
	//if ((g_TitleBGM = LoadSoundMem("sounds/ta_ta_doron01.mp3")) == -1)return -1;



	return 0;
}

>>>>>>> master:ã‚½ãƒ¼ã‚¹.cpp
