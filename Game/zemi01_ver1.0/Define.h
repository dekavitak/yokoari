/* Player*/
#define PLAYER_WIDTH 128      // �v���C���[�̉���
#define PLAYER_HEIGHT 128     // �v���C���[�̏c��
#define PLAYER_HIT_CEIL 353   // �v���C���[�̓����蔻��̈�ԏ�
#define PLAYER_HIT_FLOOR 417  // �v���C���[�̓����蔻��̈�ԉ�
#define PLAYER_MAX_SPEED 7    // �v���C���[�̍ō����x
#define ANIMATION_SPEED 30    // �A�j���[�V�����̑��x

/* Enemy */
#define ENEMY_MAX_CREATE 10   // �G�̐����ł���ő吔
#define ENEMY_RIGHT 0         // �G���E�������Ă�����
#define ENEMY_LEFT  1		  // �G�����������Ă�����
#define ENEMY_WIDTH 64        // �G�̉���
#define ENEMY_HEIGHT 64       // �G�̏c��

/* �X�e�[�W�͈� */
#define STAGE_FLOOR 576       // �X�e�[�W�̈�ԉ�
#define STAGE_LEFT 410        // �X�e�[�W�̍��[
#define STAGE_RIGHT 780       // �X�e�[�W�̉E�[

/* Box */
#define BOX_SPEED 3           // �i�{�[���̓�������
#define BOX_WIDTH 64          // �i�{�[���̉���
#define BOX_HEIGHT 64         // �i�{�[���̏c��
#define BOX_LENGTH 10         // �i�{�[���̍\���̂̔z��̗v�f�� 
#define BOX_SPAWN_TIME 60     // �i�{�[���̏o�����鎞��
#define BOX_TAKE_LIMIT 5      // �i�{�[�����P�x�Ɏ��Ă鐔�̌��E
#define GOAL 20               // �ڕW�[�i��

/* Truck */
#define TRUCK_WIDTH 50       // �g���b�N�̉���
#define TRUCK_HEIGHT 128      // �g���b�N�̏c��
#define TRUCK_MOVE_HEIGHT 1000 // �g���b�N����������
#define TRUCK_SPAWN_RIGHT 900 // �g���b�N�̏o������ꏊ
#define TRUCK_SPAWN_LEFT 350  // �g���b�N�̏o������ꏊ


/* Time */
#define MAX_TIME 180          // ��������
#define DELI_GET_TIME 15       // �[�i�҂�����܂ł̎���
#define DELI_PASS_TIME 10      // �[�i�҂��ʂ�߂���܂ł̎���
#define MAX_TIME 3000          // ��������


/* �T�E���h�n */
#define BACK_BGN "sound/BGM.mp3"      // ���LBGM
#define GAME_BGM "sound/Game.mp3"     // �Q�[��BGM
#define AITEM_SE "sound/Aitem.mp3"   // �A�C�e���nSE
#define DAMAGE_SE "sound/Damage.mp3" // �ڐG��SE
#define SELECT_SE "sound/Select.mp3" // �I����SE

/* �摜�n */
#define ADULT_ENEMY "img/enemy/Adult.png"      // ��l
#define KIDS_ENEMY "img/enemy/Kids.png"        // �q��
#define WATER_ENEMY "img/enemy/water.png"      // ��
#define TRUCK_OBJECT "img/Player/truck.png"    // �g���b�N
#define TITLE_PIC "img/stage/title.png"        // �^�C�g���摜
#define SCENE_PIC "img/stage/scene.png"        // �V�[���摜
#define TUTORIAL_PIC "img/stage/tutorial.png"  // �`���[�g���A���摜
#define STAGE_PIC "img/stage/stage.png"        // ��
#define BACK_GROUND "img/stage/backGround.png" // �w�i�摜

/* UI */
#define MENU_BUTTON "img/menuButton.png"             // ���j���[�{�^��
#define START_BUTTON "img/startButton.png"       // �X�^�[�g�{�^��
#define TUTORIAL_BUTTON "img/tutorialButton.png" // �`���[�g���A���{�^��