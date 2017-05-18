/* Player*/
#define PLAYER_WIDTH 128      // プレイヤーの横幅
#define PLAYER_HEIGHT 128     // プレイヤーの縦幅
#define PLAYER_HIT_CEIL 353   // プレイヤーの当たり判定の一番上
#define PLAYER_HIT_FLOOR 417  // プレイヤーの当たり判定の一番下
#define PLAYER_MAX_SPEED 7    // プレイヤーの最高速度
#define ANIMATION_SPEED 30    // アニメーションの速度

/* Enemy */
#define ENEMY_MAX_CREATE 10   // 敵の生成できる最大数
#define ENEMY_RIGHT 0         // 敵が右を向いている情報
#define ENEMY_LEFT  1		  // 敵が左を向いている情報
#define ENEMY_WIDTH 64        // 敵の横幅
#define ENEMY_HEIGHT 64       // 敵の縦幅

/* ステージ範囲 */
#define STAGE_FLOOR 576       // ステージの一番下
#define STAGE_LEFT 410        // ステージの左端
#define STAGE_RIGHT 780       // ステージの右端

/* Box */
#define BOX_SPEED 3           // 段ボールの動く速さ
#define BOX_WIDTH 64          // 段ボールの横幅
#define BOX_HEIGHT 64         // 段ボールの縦幅
#define BOX_LENGTH 10         // 段ボールの構造体の配列の要素数 
#define BOX_SPAWN_TIME 60     // 段ボールの出現する時間
#define BOX_TAKE_LIMIT 5      // 段ボールを１度に持てる数の限界
#define GOAL 20               // 目標納品数

/* Truck */
#define TRUCK_WIDTH 50       // トラックの横幅
#define TRUCK_HEIGHT 128      // トラックの縦幅
#define TRUCK_MOVE_HEIGHT 1000 // トラックが動く横幅
#define TRUCK_SPAWN_RIGHT 900 // トラックの出現する場所
#define TRUCK_SPAWN_LEFT 350  // トラックの出現する場所


/* Time */
#define MAX_TIME 180          // 制限時間
#define DELI_GET_TIME 15       // 納品者が来るまでの時間
#define DELI_PASS_TIME 10      // 納品者が通り過ぎるまでの時間
#define MAX_TIME 3000          // 制限時間


/* サウンド系 */
#define BACK_BGN "sound/BGM.mp3"      // 共有BGM
#define GAME_BGM "sound/Game.mp3"     // ゲームBGM
#define AITEM_SE "sound/Aitem.mp3"   // アイテム系SE
#define DAMAGE_SE "sound/Damage.mp3" // 接触時SE
#define SELECT_SE "sound/Select.mp3" // 選択時SE

/* 画像系 */
#define ADULT_ENEMY "img/enemy/Adult.png"      // 大人
#define KIDS_ENEMY "img/enemy/Kids.png"        // 子供
#define WATER_ENEMY "img/enemy/water.png"      // 水
#define TRUCK_OBJECT "img/Player/truck.png"    // トラック
#define TITLE_PIC "img/stage/title.png"        // タイトル画像
#define SCENE_PIC "img/stage/scene.png"        // シーン画像
#define TUTORIAL_PIC "img/stage/tutorial.png"  // チュートリアル画像
#define STAGE_PIC "img/stage/stage.png"        // 道
#define BACK_GROUND "img/stage/backGround.png" // 背景画像

/* UI */
#define MENU_BUTTON "img/menuButton.png"             // メニューボタン
#define START_BUTTON "img/startButton.png"       // スタートボタン
#define TUTORIAL_BUTTON "img/tutorialButton.png" // チュートリアルボタン