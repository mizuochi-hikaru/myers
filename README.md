# myers
マイヤーズの三角形問題を実装したやつです。

## クイックスタート
```
$ git clone コレ
$ cd cloneしたところ
$ make
$ ./bin/myers (辺A) (辺B) (辺C)
```
※makeのターゲット
- `make all`: プログラム本体とテスト(ターゲットがブランクならコチラ)
- `make myers`: プログラム本体
- `make test`: テスト
- `make clean`: 今あるもの削除

## 単体テスト
`myers.test.c`にテスト内容を記載(ハードコード)し、実施します。<br>
`make test`の前に`make (myers)`してあれば、コンパイルしてある`myerslib.o`を使用するはずです。
```
$ cd cloneしたところ
$ make test
$ ./bin/myers.test
```
