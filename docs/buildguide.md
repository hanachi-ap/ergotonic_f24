# Ergotonic F-24 ビルドガイド(暫定版)

## はんだ付けの難易度について
  - 本キットは、ご自身ではんだ付けを行って頂く必要があります。
  - ダイオード、LED、及び 左右を結合するケーブルソケットは表面実装部品を採用しています。
  一般的な電子工作で用いるようなスルーホールに足を差し込んではんだ付けする部品に比べて難易度が高くなっていますのでご留意ください。
  

### 組み立て手順概要
0. 部品を揃える
1. パーツを分離する
2. はんだ付け
3. 組み立て

## 部品そ揃える

## 部品
  必要な部品はすべて国内キーボード通販ショップで簡単にオーダーできるので並行して入手するようにお願いします。

- キットに同梱される部品(基本部)
  - PCB 右	 x 1
  - PCB 左	 x 1
  - トッププレート	x 2
  - ボトムプレート	x 2
  - ネジ M2/3.0mm  x 40
  - スペーサー M2/3.5mm	x 4
  - スペーサー M2/7.0mm	x 16
- キットに同梱される部品(ジョイント機構部)		
  -	ジョイントパーツ	x 2
  - スペーサー M2/3.5mm	 x 8
  - ネジ M2/5.0mm 	x 16
  - 基板用コネクタ4P x 2
  - コネクタ付コード4P x1

- 別途調達が必要な部品
   
   必要な部品はすべて国内キーボード通販ショップで簡単にオーダーできます。
  
  - ProMicro	x 2  (Type-C版も可)
  - コンスルー	 x 4  (入手困難な場合は、ProMicro同梱ピンヘッダを使って直接んだ付けも可)
  - ダイオード(1N4148W) x 48
  - TRRSジャック x 2
  - クッションゴム x 8
  - タクトスイッチ(2ピン3.5x6.0x4.3mm) x 2
  - MXスイッチソケット x 48
  - キースイッチ(Cherry MX互換) x 48
  - キーキャップ(1U) x 48
  - TRRS(またはTRS)ケーブル	x 1 (40cm以上を推奨)
  - アンダーグロー用LED(SK6812MINI-E)  x 16
  - ロータリーエンコーダ(EC12またはEC11互換)  x 0～4 





## 1．パーツを分離
  
- 各パーツを分離してバリ取りしてください。

[<img src="fig/fig00.jpg" alt="fig00" title="fig/fig00.jpg" width=600>](fig/fig00.jpg)

## 2．はんだ付け

### 表面に取り付けるもの
  - ProMicro
  - RGB LED (発光面を下向きに)
  - TRRSコネクタ
  - リセット用スイッチ

### 裏面に取り付けるもの
  - ダイオード
  - スイッチソケット

## 3． 組み立て

基本的には Ergotonic49と同じような感じで組み立てます。

- トッププレートとPCBを、M2 3.5mm スペーサー 2個を使って合体する。

- PCBとカバープレートを、M2 7mmスペーサー3個を使って合体する。

- それとボトムプレートを、M2 7mmスペーサー 3個を使って合体する。

  - その時、内側 2箇所にM2 3.5mmスペーサーを埋め込んで上下から軽くM2 3.5mmネジで止めておく

- 上記を左右について実施する

- 中央プレートとジョイントプレートをM2 3.5mmスペーサーを使って仮組みする

- 本体とジョイントプレートを結合してネジ止めする


下記の写真を参考にして下さい


[<img src="fig/fig01.jpg" alt="fig01" title="fig/fig01.jpg" width=600>](fig/fig01.jpg)

[<img src="fig/fig02.jpg" alt="fig02" title="fig/fig02.jpg" width=600>](fig/fig02.jpg)
  
[<img src="fig/fig03.jpg" alt="fig03" title="fig/fig03.jpg" width=600>](fig/fig03.jpg)
  
[<img src="fig/fig04.jpg" alt="fig04" title="fig/fig04.jpg" width=600>](fig/fig04.jpg)
  
[<img src="fig/fig05.jpg" alt="fig05" title="fig/fig05.jpg" width=600>](fig/fig05.jpg)
  
[<img src="fig/fig06.jpg" alt="fig06" title="fig/fig06.jpg" width=600>](fig/fig06.jpg)
  
[<img src="fig/fig07.jpg" alt="fig07" title="fig/fig07.jpg" width=600>](fig/fig07.jpg)
  


以上
