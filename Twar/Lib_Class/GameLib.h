/**
* @file GameLib.h
* @brief  Facadeパターンのライブラリ作成
* @author haga
*/
#ifndef GAMELIB_H
#define GAMELIB_H

#include <windows.h>
#include <iostream>
#include "WindowCreator.h"	
#include "GraphicsDevice.h"
#include "InputDevice.h"
#include "InputKey.h"
#include "InputMouse.h"
#include "TextureManager.h"
#include "XFileManager.h"
#include "SoundFileManager.h"
#include "VertexManager.h"
#include "DebugFont.h"
#include "DebugTimer.h"
using namespace std;

/**
* ライブラリのクラス
*/
class GameLib
{
private:
	WindowCreator		m_windowCreator;
	GraphicsDevice*		m_pGraphicsDevice;
	InputDevice*		m_pInputDevice;
	SoundFileManager*   m_pSoundFileManager;
	InputKey*			m_pInputKey;
	InputMouse*			m_pInputMouse;
	TextureManager*     m_pTextureManager;
	XFileManager*		m_pXFileManager;
	VertexManager*		m_pVertexManager;
	DebugTimer*			m_pDebugTimer;
	int				    m_wWidth;			//!< ウインドウの幅
	int					m_wHeight;			//!< ウィンドウの高さ
	bool				m_releaseFlag;		//!< メモリ解放したかどうかのフラグ

public:
	/**
	* コンストラクタ.
	* @param[in] title  ウィンドウタイトル
	* @param[in] width  ウィンドウの横幅
	* @param[in] height ウインドウの縦幅
	*/
	GameLib(char* title, int width, int height);

	/**デストラクタ*/
	~GameLib();

	/**
	* 初期化関数.
	* @param[in] hInstance	インスタンスハンドル
	* @param[in] Wndproc	ウィンドウプロシージャ関数
	* @param[in] windowType ウィンドウタイプ trueなら通常,falseならフルスクリーン
	*/
	void InitGameLib(HINSTANCE hInstance, LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp), bool windowType);

	/**メモリ開放関数*/
	void ReleaseGameLib();

	/**ウィンドウをフルスクリーンかウィンドウサイズに変える関数*/
	void ChangeWindowMode();			

	/**ウィンドウの横幅を取得する関数*/
	int GetWindowWidth(){ return m_wWidth; }	

	/**ウィンドウの縦幅を取得する関数*/
	int GetWindowHeight(){ return m_wHeight; }		

	//------------------------------------------------------------------------------------
	//									描画関連関数
	//------------------------------------------------------------------------------------
	/**デバイスを取得する関数*/
	const IDirect3DDevice9* GetDevice();					

	/**
	* 描画開始処理関数.
	* @param[in] FVF 頂点フォーマット
	*/
	void StartRender(DWORD FVF = D3DFVF_CUSTOMVERTEX);

	/**描画終了処理関数*/
	void EndRender();											

	/**
	* 頂点フォーマットを設定する関数
	* @param[in] FVF 頂点フォーマット
	*/
	void SetFVF(DWORD FVF);										

	//---------------------------------------------------------------------------------------
	//								テクスチャー関連関数
	//---------------------------------------------------------------------------------------
	/**
	* テクスチャーを読み込む関数.
	* @param[in] key		登録するキー、またはID(enumで作成を想定)
	* @param[in] filepath   ファイル名
	*/
	void LoadTex(int key, char* filePath);																	

	/**
	* テクスチャーを詳細設定して読み込む関数.
	* @param[in] key		登録するキー、またはID(enumで作成を想定)
	* @param[in] filepath   ファイル名
	* @param[in] a			アルファ値  0〜255
	* @param[in] r			色のR値 0〜255
	* @param[in] g			色のG値 0〜255
	* @param[in] b			色のB値 0〜255
	* @param[in] size		テクスチャーのサイズが２のべき乗ならtrue,違うならfalse
	*/
	void LoadTexEx(int key, char* filePath,int a, int r, int g, int b, bool size );				

	/**
	* バーテックスを作成する関数.
	* @param[in] key	登録するキー、またはID(enumで作成を想定)
	* @param[in] width	横幅(X軸)
	* @param[in] height 高さ(Y軸)
	* @param[in] depth  奥行(Z軸) デフォルト引数値は0.0f
	*/
	void CreateVtx(int key, float width, float height, float depth = 0.0f);									

	/**
	* バーテックスの変更を行う関数.
	* @param[in] key	登録したキー、またはID
	* @param[in] tuMin  tu値の最小値
	* @param[in] tuMax  tu値の最大値
	* @param[in] tvMin  tv値の最小値
	* @param[in] tvax	tv値の最大値
	* @param[in] color  色情報(ARGB) デフォルト引数値は0xFFFFFFFF
	*/
	void SetVtx(int key, float tuMin, float tuMax, float tvMin, float tvMax, DWORD color = 0xFFFFFFFF);		 

	/**
	* テクスチャーを(XY座標)において描画する関数
	* @param[in] key	登録したキー、またはID
	* @param[in] center 位置座標をテクスチャーの中心にするならtrue,違うならfalse
	* @param[in] posX	x座標
	* @param[in] posY   y座標
	*/
	void DrawXY(int key,bool center,float posX,float posY);													

	/**
	* テクスチャーをXZ座標で描画する関数
	* @param[in] key	登録したキー、またはID
	* @param[in] center 位置座標をテクスチャーの中心にするならtrue,違うならfalse
	* @param[in] posX	x座標
	* @param[in] posY   y座標
	* @param[in] posZ   z座標
	*/
	void DrawXZ(int key, bool center,float posX, float posY, float posZ);

	/**
	* テクスチャーを解放する関数
	* @param[in] AllFlag  全て解放するならture,特定のテクスチャーだけを解放するならfalseで第二引数を指定する
	* @param[in] key	登録したキー、またはID。デフォルト引数は666←登録されないだろう数値を代入している
	*/
	void ReleaseTex(bool AllFlag,int key = 666);

	//-------------------------------------------------------------------------------------
	//								Xファイル関連関数
	//-------------------------------------------------------------------------------------
	/**
	* Xファイルを読み込む関数.
	* @param[in] key		 登録するキー、またはID(enumで作成を想定)
	* @param[in] pFilepath   ファイル名
	*/
	void LoadXFile(int key, LPCTSTR pFilePath);					

	/**
	* Xファイルを描画する関数.
	* @param[in] key	登録したキー、またはID
	*/
	void DrawXFile(int key);				

	/**
	* Xファイルを解放する関数.
	* @param[in] AllFlag  全て解放するならture,特定のテクスチャーだけを解放するならfalseで第二引数を指定する
	* @param[in] key	登録したキー、またはID。デフォルト引数は666←登録されないだろう数値を代入している
	*/
	void ReleaseXFile(bool AllFlag,int key = 666);				

	//-----------------------------------------------------------------------------------------------------
	//									入力デバイス関連関数
	//-----------------------------------------------------------------------------------------------------

	/**ダイレクトインプットをアップデートする関数*/
	void UpDateDI();											

	/**
	* キーの状態を確認する関数.
	* @param[in] DIK      ダイレクトインプットキー DIK_
	* @param[in] keyName  キーの名前
	* @return ボタンの状態
	*/
	BUTTONSTATE CheckKey(int DIK, KEYKIND keyName);				

	/**
	* マウスのボタンの状態を取得する関数
	* @param[in] mouseButton マウスのボタンの種類
	* @return ボタンの状態
	*/
	BUTTONSTATE ChecKMouse(MOUSEBUTTON mouseButton);			

	/**
	* マウスのホイールの状態を取得する関数.
	* @return ホイールの状態
	*/
	WHEEL_STATE GetWheelState();								

	/**
	* マウスの座標を取得する関数.
	* @return マウスの座標
	*/
	D3DXVECTOR2 GetMousePos();									 

	//--------------------------------------------------------------------------
	//						サウンド関連関数
	//--------------------------------------------------------------------------
	/**
	* 音声を読み込む関数.
	* @param[in] filePath ファイル名
	*/
	void LoadSound(TCHAR* filePath);											

	/**
	* 音楽を鳴らす関数
	* @param[in] filePath ファイル名
	* @param[in] sMode   音楽の再生方法
	*/
	void PlayDSound(TCHAR* filePath, SOUND_MODE sMode);							

	//-------------------------------------------------------------------------------
	//								デバック機能
	//-------------------------------------------------------------------------------
	/**
	* 文字を表示させる関数.
	* @param[in] text 表示した文字
	* @param[in] posX x座標
	* @param[in] posY y座標
	*/
	void DrawFont(std::string text, float posX, float posY);						

	/**
	* 時間計測を開始する関数.
	* @param[in] timeName	計測したい時間の名前
	*/
	void StartTimer(std::string  timeName);											

	/**
	* 時間計測を終了する関数.
	* @param[in] timeName	計測を終えたい時間の名前
	*/
	void EndTimer(std::string  timeName);											

	/**
	* 計測結果を表示する関数.
	* @param[in] timeName	表示したい計測時間の名前
	* @param[in] posX x座標
	* @param[in] posY y座標
	*/
	void DrawResult(std::string  timeName,float posX,float posY);					

	/**
	* 計測結果を取得する関数.
	* @param[in] timeName	取得したい計測時間の名前
	*/
	DWORD GetResultTime(std::string  timeName);										

	/**
	* すべての時間結果とその合計時間を表示する関数.
	* @param[in] posX x座標
	* @param[in] posY y座標
	*/
	void DrawAllResult(float posX,float posY);										
 };

#endif	// GAMELIB_H

