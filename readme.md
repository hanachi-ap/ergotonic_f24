# Ergotonic F24


Ergotonic F24（仮称)の初期限定リソースです。

変形ギミックが特徴的なキーボードですが、その変形機構は[PANGAEA Keyboard](https://github.com/e3w2q/Pangaea-keyboard)が発想の源となっています。

一体型、分離型のトランスフォームはWillow64を始めた頃からやりたかったことですが、ここで結実することができました。

変形機構の利用を快諾していただいたPANGAEAキーボードの開発陣に謝意を送ります。


## Ergotonic F24の基本スペック
  - Willow配列、48キー、数字行レス
  - 一体型 / 分離型 兼用
  - 変形ギミック(後述)
  - ProMicroとQMK Firmware
  - VIA/Remap (公式未登録のため個別にjson指定)
  - 最大4個のロータリーエンコーダー
  - アンダーグローLED

### 変形ギミック
  -  基本形
     -  Ergotonic49とほぼ同じサイズ、外形
  -  拡張形態
     -  左右に 最大30mm拡張
  -  前進翼形態
     -  あるいは翼を広げた鳥のような
  -  後退翼形態
     -  または未来少年コナンに登場するギガント?
  -  分離形態
     -  普通にスプリットキーボード。Willow64の正当な後継の座を受け継げるか
  
### プロトタイプの試み
  - TRRSコードに代えて、ZHコネクタによる直接接続
  - アルミ素材のPCBプレート
  - 拡張機能のためのコネクタ(未テスト、実装バグあり)

### ベースとなったプロダクト
  - Ergotonic49 
    - by Hanachi-ap

  - PANGAEA Keyboard
    - 開発陣 @e3w2q , @otahinosame , @k2___________ 
    - 変形機構のアイデアや実装を借用しています
    - PCBのfootprintを利用させてもらっています
    - その他、豊かな発想から開発の養分を得ています

### 権利関係など
   - まだ権利関係など明記していませんが基本的にGPL及びCreative Commonsを適用する計画です。

  - QMK Firmware -- GPL v2
  - PCB デザイン -- GPL v3
  - キー配列(Willow配列) -- Creative Commons(CC BY-SA 4.0 by Hanachi)

