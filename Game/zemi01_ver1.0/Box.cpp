#include"DxLib.h"
#include"Box.h"
#include"Define.h"
#include"Enum.h"
#include"Hit.h"
#include"Player.h"

// �\���̃I�u�W�F�N�g�̐���
struct Box box[10];

// �摜�n���h��
int BoxImage;

// �i�{�[���̐������Ɏg�p����ϐ�
int SpawnCnt;   // �i�{�[���o���܂ł̃J�E���g
int TakeCnt;    // ���ݎ����Ă��鐔
int DeliveryNum;// �[�i���������i�[����ϐ�

// �}�E�X�̏�Ԃ��i�[����ϐ�
int Mouse_Input;

/***************************************
�@�\�@�F�i�{�[���֘A�̏�����
�����@�FNone
�Ԃ�l�FNone
***************************************/
void BoxInitialize() {

	// �ϐ��Ȃǂ̏�����
	for (int i = 0; i < BOX_LENGTH; i++) {
		box[i].mLivingFlg = false;
		box[i].mTakeFlg = false;
		box[i].mX = 250;
		box[i].mY = -50;
		box[i].mCenterX = box[i].mX + (BOX_WIDTH / 2);
		box[i].mCenterY = box[i].mY + (BOX_HEIGHT / 2);
	}
	InitBoxHitFlg();
	SpawnCnt = 0;
	TakeCnt = 0;
	DeliveryNum = 0;
	// �摜�̃��[�h
	BoxImage = LoadGraph("img/Box.png");
}

/***************************************
�@�\�@�F�i�{�[���̕`��
�����@�FNone
�Ԃ�l�FNone
***************************************/
void BoxView() {


	// �`��
	for (int i = 0; i < BOX_LENGTH; i++) {

		// �i�{�[�������݂���Ȃ�
		if (box[i].mLivingFlg == true) {

			// �i�{�[�����v���C���[�Ɏ�����Ă��Ȃ��Ȃ�
			if (box[i].mTakeFlg == false) {
				DrawGraph(box[i].mX, box[i].mY, BoxImage, TRUE);
			}
			// �i�{�[�����v���C���[�Ɏ�����Ă���Ȃ�
			else {
				// �v���C���[�̒��Sx���W - �v���C���[�̉��� / 4,
				// �v���C���[�̒��Sy���W - ((�v���C���[�̏c�� / 4) + ((�����Ă��鐔 - 1) * �i�{�[���̏c��)),
				// �ȏ�̍��W�ɕ`��
				DrawGraph(box[i].mX, box[i].mY, BoxImage, TRUE);
			}
		}
	}

}

/***************************************
�@�\�@�F�i�{�[���̓���
�����@�FNone
�Ԃ�l�FNone
***************************************/
void BoxMove() {

	// �i�{�[���𓮂���
	for (int i = 0; i < BOX_LENGTH; i++) {

		// �i�{�[�������݂��Ă��Ȃ��Ȃ�
		if (box[i].mLivingFlg == false) {

			// �J�E���g���������鎞�ԂɂȂ�����
			if (SpawnCnt == BOX_SPAWN_TIME) {
				box[i].mLivingFlg = true;
				SpawnCnt = 0;
			}
		}

		// �i�{�[�������݂���Ȃ�
		if (box[i].mLivingFlg == true) {

			// �i�{�[����������Ă��Ȃ��Ȃ�
			if (box[i].mTakeFlg == false) {
				box[i].mY += BOX_SPEED;
				box[i].mCenterY = box[i].mY + (BOX_HEIGHT / 2);

				// �v���C���[�̂��鍂���ɒi�{�[��������Ȃ�
				if ((box[i].mY + BOX_HEIGHT) >= PLAYER_HIT_CEIL &&
					box[i].mY <= PLAYER_HIT_FLOOR) {

					// �����蔻����s��
					BoxAndPlayerHit(ReturnPlayerRight(), ReturnPlayerLeft(),
						box[i].mCenterX + (PLAYER_WIDTH / 2), box[i].mCenterX - (BOX_WIDTH / 2));
				}
				// �i�{�[�����v���C���[�ɐG�ꂽ�Ȃ�
				if (ReturnBoxHitFlg() == PLAYER) {

					// �����Ă���i�{�[�����T�ȉ��Ȃ�
					if (TakeCnt < BOX_TAKE_LIMIT) {

						// �����Ă��鐔�����Z����
						TakeCnt++;

						// �擾��SE�̍Đ�
						PlaySoundFile(AITEM_SE, DX_PLAYTYPE_BACK);

						// �i�{�[����������Ă����Ԃɂ���
						box[i].mTakeFlg = true;

						// ���W���ړ�(���W�̏ڍׂ͕`�敔���ɃR�����g)
						box[i].mX = ReturnPlayerCenterX() - (PLAYER_WIDTH / 4);
						box[i].mY = ReturnPlayerCenterY() - ((PLAYER_HEIGHT / 4) + ((TakeCnt - 1) * BOX_HEIGHT));
					}

					// �����蔻��̏�����
					InitBoxHitFlg();
				}

			}
			// ������Ă���Ȃ�
			else {
				// �v���C���[�ɂ��Ă�������
				box[i].mX = ReturnPlayerCenterX() - (PLAYER_WIDTH / 4);
			}
		}

		// ��ʊO������
		BoxMoveLimit(i);
	}
	// �����J�E���g�̉��Z
    SpawnCnt++;

	// �}�E�X�̏�Ԃ��擾
	Mouse_Input = GetMouseInput();

	// ���N���b�N���ꂽ��
	if (Mouse_Input & MOUSE_INPUT_LEFT) {
		for (int i = 0; i < BOX_LENGTH; i++) {
			// ������Ă���ו�������Ȃ�
			if (box[i].mTakeFlg == true) {

				// SE�̍Đ�
				PlaySoundFile(AITEM_SE, DX_PLAYTYPE_BACK);

				// �i�{�[���̏�����
				box[i].mTakeFlg = false;
				box[i].mLivingFlg = false;
				box[i].mX = 250;
				box[i].mY = -50;
				box[i].mCenterX = box[i].mX + (BOX_WIDTH / 2);
				box[i].mCenterY = box[i].mY + (BOX_HEIGHT / 2);
				TakeCnt--;
				DeliveryNum++;
			}
		}
	}
}

/***************************************
�@�\�@�F�i�{�[���̓����̐���
�����@�FNone
�Ԃ�l�FNone
***************************************/
void BoxMoveLimit(int number) {

	// ��ʉ��ɏo����
	if (box[number].mY > STAGE_FLOOR) {
		// �i�{�[���̏�����
		box[number].mLivingFlg = false;
		box[number].mX = 250;
		box[number].mY = -50;
		box[number].mCenterX = box[number].mX + (BOX_WIDTH / 2);
		box[number].mCenterY = box[number].mY + (BOX_HEIGHT / 2);

	}

	
}

/****************************************
�@�\�@�F�i�{�[���̓����蔻��̉E�[��Ԃ�
�����@�F�\���̂̔z��̕����ԍ�
�Ԃ�l�F�i�{�[���̓����蔻��̉E�[
*****************************************/
int ReturnBoxRight(int number) {

	return box[number].mCenterX + (PLAYER_WIDTH / 2);

}

/****************************************
�@�\�@�F�i�{�[���̓����蔻��̍��[��Ԃ�
�����@�F�\���̂̔z��̕����ԍ�
�Ԃ�l�F�i�{�[���̓����蔻��̍��[
*****************************************/
int ReturnBoxLeft(int number) {

	return box[number].mCenterX - (BOX_WIDTH / 2);

}

/****************************************
�@�\�@�F�i�{�[���̎�����Ă���t���O��Ԃ�
�����@�F�\���̂̔z��̕����ԍ�
�Ԃ�l�Fbox.mTakeFlg
*****************************************/
int ReturnBoxTakeFlg(int number) {

	return box[number].mTakeFlg;

}

/****************************************
�@�\�@�F�i�{�[���̔[�i�������̍��v��Ԃ�
�����@�FNone
�Ԃ�l�FTakeCnt
*****************************************/
int ReturnDeliveryNum() {

	return DeliveryNum;

}