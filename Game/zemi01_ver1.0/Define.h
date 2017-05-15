#define PLAYER_WIDTH 128      // プレイヤーの横幅
#define PLAYER_HEIGHT 128     // プレイヤーの縦幅
#define PLAYER_HIT_CEIL 353   // プレイヤーの当たり判定の一番上
#define PLAYER_HIT_FLOOR 417  // プレイヤーの当たり判定の一番下
#define PLAYER_MAX_SPEED 7    // プレイヤーの最高速度
#define ANIMATION_SPEED 30    // アニメーションの速度

#define STAGE_FLOOR 576       // ステージの一番下
#define STAGE_LEFT 230        // ステージの左端
#define STAGE_RIGHT 650       // ステージの右端

#define BOX_SPEED 3           // 段ボールの動く速さ
#define BOX_WIDTH 64          // 段ボールの横幅
#define BOX_HEIGHT 64         // 段ボールの縦幅
#define BOX_LENGTH 10         // 段ボールの構造体の配列の要素数 
#define BOX_SPAWN_TIME 60     // 段ボールの出現する時間
#define BOX_TAKE_LIMIT 5      // 段ボールを１度に持てる数の限界

/* サウンド系 */
#define BACK_BGN "sound/BGM.mp3"      // 共有BGM
#define GAME_BGM "sound/Game.mp3"     // ゲームBGM
#define AITEM_SE "sound/Aitem.mp3"   // アイテム系SE
#define DAMAGE_SE "sound/Damage.mp3" // 接触時SE
#define SELECT_SE "sound/Select.mp3" // 選択時SE