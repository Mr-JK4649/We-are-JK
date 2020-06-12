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
* �񋓑̂̐錾
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
* �萔�̐錾
********************************************************************/




/********************************************************************
* �ϐ��̐錾
********************************************************************/
int g_OldKey;    // �O��̓��̓L�[
int g_NowKey;    // ����̓��̓L�[
int g_KeyFlg;    // ���̓L�[���

int g_MouseX;    // �}�E�X��X���W
int g_MouseY;    // �}�E�X��Y���W

int g_GameState;



/*�T�E���h*/


/********************************************************************
* �\���̂̐錾
********************************************************************/



/***********************************************
  * �֐��̃v���g�^�C�v�錾
***********************************************/
// �Q�[������������
void GameInit(void);
// �Q�[�����C������
void GameMain(void);
// �Q�[���^�C�g���`�揈��
void DrawGameTitle(void);
// �G���h�`�揈��
void DrawEnd(void);
// �Q�[���N���A�[�̏���
void DrawGameResult(void);
// �Q�[���I�[�o�[�`�揈��
void DrawGameOver(void);

// �摜�ǂݍ���
int LoadImages();

//�T�E���h
int LoadSounds(void);

/*****************************************************
 * �v���O�����̊J�n
 ****************************************************/
int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_
	HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd) {


	SetMainWindowText("Match 3"); // �^�C�g����ݒ�

	ChangeWindowMode(TRUE);   // �E�B���h�E���[�h�ŋN��


	if (DxLib_Init() == -1)   // DX���C�u�����̏���������
		return -1;

	SetDrawScreen(DX_SCREEN_BACK); // �`����ʂ𗠂ɂ���

	// �摜�ǂݍ���
	if (LoadImages() == -1)
		return -1;

	//�T�E���h�ǂݍ���
	if (LoadSounds() == -1)
		return -1;

	// �Q�[�����[�v
	while (ProcessMessage() == 0 && g_GameState != END && !(g_KeyFlg & PAD_INPUT_START)) {


		// ���̓L�[�擾
		g_OldKey = g_NowKey;
		g_NowKey = GetMouseInput();
		g_KeyFlg = g_NowKey & ~g_OldKey;

		//�}�E�X�̈ʒu���擾
		GetMousePoint(&g_MouseX, &g_MouseY);

		ClearDrawScreen();  // ��ʂ̏�����

		switch (g_GameState) {

		case GAME_TITLE:DrawGameTitle(); break;		 //�Q�[���^�C�g������

		case GAME_INIT: GameInit();  break;			 //�Q�[����������

		case GAME_END: DrawEnd();  break;			 //�����L���O�`�揈��

		case GAME_MAIN: GameMain();  break;			 //�G���h�`�揈��

		case GAME_RESULT:DrawGameResult(); break;		 //�Q�[�����C������

		case GAME_OVER: DrawGameOver(); break;		 // �Q�[���I�[�o�[�`�揈��

		}

		ScreenFlip();    // ����ʂ̓��e��\��ʂɔ��f

	}

	DxLib_End(); // DX���C�u�����g�p�̏I������

	return 0; // �\�t�g�̏I��
}

/********************************************************************
* �Q�[���^�C�g���`�揈��(���j���[���)
********************************************************************/
void DrawGameTitle(void) {

}

/********************************************************************
* �Q�[������������
********************************************************************/
void GameInit(void) {

}


/********************************************************************
* �Q�[���G���h�`�揈��
********************************************************************/
void DrawEnd(void) {

}

/********************************************************************
* �Q�[�����C��
********************************************************************/
void GameMain(void) {

}

/********************************************************************
* �Q�[���N���A�`�揈��
********************************************************************/
void DrawGameResult(void) {

}

/********************************************************************
* �Q�[���I�[�o�[�`�揈��
********************************************************************/
void DrawGameOver(void) {


}


/********************************************************************
* �摜�ǂݍ���
********************************************************************/
int LoadImages() {

	//// �^�C�g��
	//if ((g_TitleImage = LoadGraph("images/title.png")) == -1)return -1;

	////�X�e�[�W
	//if ((g_StageImage = LoadGraph("images/stage.png")) == -1)return -1;

	////�Q�[���N���A
	//if ((g_GameClearImage = LoadGraph("images/gameclear.png")) == -1)return -1;

	////�Q�[���I�[�o�[
	//if ((g_GameOverImage = LoadGraph("images/gameover.png")) == -1)return -1;

	////�u���b�N�摜
	//if (LoadDivGraph("images/block.png", 10, 10, 1, 48, 48, g_BlockImage) == -1)return -1;

	////�i���o�[�摜�̓ǂݍ���
	//if (LoadDivGraph("images/number.png", 10, 10, 1, 60, 120, g_NumberImage) == -1)return -1;

	return 0;
}

/********************************************************************
* �T�E���h�ǂݍ���
********************************************************************/
int LoadSounds(void) {

	////�^�C�g��
	//if ((g_TitleBGM = LoadSoundMem("sounds/muci_hono_r01.mp3")) == -1)return -1;
	////�N���A
	//if ((g_GameClearSE = LoadSoundMem("sounds/muci_fan_06.mp3")) == -1)return -1;
	////�I�[�o�[
	//if ((g_GameOverSE = LoadSoundMem("sounds/muci_bara_07.mp3")) == -1)return -1;
	////�}�E�X�N���b�N
	//if ((g_ClickSE = LoadSoundMem("sounds/ta_ta_warekie02.mp3")) == -1)return -1;
	////�u���b�N����
	//if ((g_TitleBGM = LoadSoundMem("sounds/ani_ta_biyon02.mp3")) == -1)return -1;
	////�u���b�N�ړ�
	//if ((g_TitleBGM = LoadSoundMem("sounds/ta_ta_doron01.mp3")) == -1)return -1;



	return 0;
}