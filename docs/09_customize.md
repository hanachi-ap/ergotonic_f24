# キーボードをカスタマイズする

##  標準キーマップ
標準ファームウェアでは0から4までの5つのレイヤーが定義されています。

 - レイヤー0  : 基本のアルファベット
 - レイヤー1  : 未定義
 - レイヤー2  : 数字、記号
 - レイヤー3  : カーソル移動、ファンクションキー
 - レイヤー4  : LED操作などキーボードシステム設定

Erogotonic49には物理的な数字キーはありませんが、レイヤー変更キーを押しながらQを押すと1が入力されるというような動作が可能です。

また レイヤー1 はなにもキーコードが定義されていない状態になっています。これはWindowsとMacの使い分け、オフィス作業とゲーム操作の使い分け、特定のアプリのショートカットなど自由に定義できるレイヤーとして使って下さい。

その他にも色々な機能があるので、 チートシート [keymap_cheatsheet_ergotonic_49.pdf](img/keymap_cheatsheet_ergotonic_49.pdf)を参照して確認してみて下さい。

----
自分が使いやすいと思うように自由にカスタマイズすることは自作キーボードの楽しみの一つなので、標準キーマップにとらわれず色々と試してみるのが良いと思います。

Ergotonic49をカスタマイズする方法は、大きく次の2つの方法があります。
  1. [REMAP](https://remap-keys.app/)を用いて、直感的にキーマップを変更する方法
  2. [QMK Firmware](https://docs.qmk.fm/)を編集して詳細なカスタマイズを行う方法

## 1. REAMPをつかう

キー配列を変更したり、LEDの点灯を変更したりするにはREMAPがあれば十分だと思います。

キーボードとPCをつないだ状態でChromeブラウザで[https://remap-keys.app/](https://remap-keys.app/)にアクセスして下さい。

サイトは英語表記だけですが、操作方法は直感的なので特に説明が無くても解ると思います。アカウント登録するとキーマップを保存したり読み込んだりできるので便利です。

## 2. QMK Firmwareを編集する

Ergotonic49は[QMK Firmware](https://docs.qmk.fm/)というオープンソースとして開発されているファームウェアを利用しいています。

ロータリーエンコーダーの動作やCAPS LOCKやNUM LOCKの状態でLEDの表示を変更するような独自の動きはQMKの中で定義しています。


QMKにはとても沢山の機能が用意されていて、より自由な設定を行うことができます。
しかしそのためにはプログラミング言語(C言語)やPC上での黒い画面(コンソール)でコマンドを使ったコンパイル操作を行う必要があります。

Ergotonic49のファームウェアは [ここ](https://github.com/hanachi-ap/qmk_firmware/tree/ergotonic49/keyboards/ergotonic49)から参照できます。

注目ポイントは [このファイル](https://github.com/hanachi-ap/qmk_firmware/blob/ergotonic49/keyboards/ergotonic49/keymaps/default/keymap.c)です。
もしこれを見て行けそうだ! と感じたらぜひQMK Firmwareのカスタマイズに挑戦してみて下さい。


----
 [Index](index.md)