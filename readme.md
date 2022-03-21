-- Ergotonic F24（仮称)の初期リリース(基板リビジョン P01)向けの情報 --

# Ergotonic F-24



Ergotonic F-24(仮称)、[Ergotonic 48 Spilit of the Willow](https://github.com/hanachi-ap/ergotonic49_docs)の特徴をそのままに、分離変形機能を追加した自作向けメカニカルキーボードです。

変形ギミックが特徴的なキーボードですが、その変形機構は[PANGAEA Keyboard](https://github.com/e3w2q/Pangaea-keyboard)が発想の源となっています。

一体型、分離型のトランスフォームはWillow64を始めた頃からやりたかったことですが、やっとその目標を結実することができました。

変形機構の利用を快諾していただいたPANGAEAキーボードの開発陣に謝意を送ります。


## Ergotonic F-24の基本スペック
  - Willow配列、48キー、数字行レス
  - 一体型 / 分離型 兼用
  - 変形ギミック(後述)
  - 最大4個のロータリーエンコーダー
  - アンダーグローLED
  - Cherry MX互換メカニカルスイッチ、ソケット対応
  - ProMicroとQMK Firmware
  - VIA/Remap (公式未登録のため個別にjson指定)
  - 基板3層サンドイッチ構造
### 変形ギミック
  -  基本形
     -  Ergotonic49とほぼ同じサイズ、外形
  -  拡張形態
     -  左右に 最大30mm拡張
  -  前進翼形態
     -  あるいは翼を広げた鳥のようなシルエット
  -  後退翼形態
     -  または未来少年コナンに登場する飛行要塞ギガント
  -  分離形態
     -  普通にスプリットキーボード。Willow64の正当な後継の座を受け継げるか!?
  
### プロトタイプの試み
  - TRRSコードに代えて、ZHコネクタによる直接接続
  - アルミ素材のPCBプレート
  - 拡張機能のためのコネクタ(未テスト、実装バグあり)

## ビルドガイド

- [ビルドガイド 初期暫定版](docs/index.md)
### ベースとなったプロダクト
  - Ergotonic49 
    - Ergotonic F-24と同じ開発者による現行モデル
    -  ドキュメント https://hanachi-ap.github.io/ergotonic49_docs/
    -  紹介記事 https://coal.hatenablog.com/entry/2021/11/01/230327
  - PANGAEA Keyboard
    - 開発リソース https://github.com/e3w2q/Pangaea-keyboard
    - 開発陣 e3w2qさん、オタヒーのさめさん、k2さん
    - 変形機構のアイデアや実装を借用しています
    - PCB設計のための部品ライブラリを利用させてもらっています
    - その他、豊かな発想から開発の養分を得ています

### 権利関係など

まだ権利関係など明記していませんが基本的にGPL及びCreative Commonsを適用する計画です。

  - QMK Firmware -- GPL v2
  - PCB デザイン -- GPL v3
  - キー配列(Willow配列) -- Creative Commons(CC BY-SA 4.0 by Hanachi)

