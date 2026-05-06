*This project has been created as part of the 42 curriculum by kayoshid.*

# Libft

Part1

1 Byte = 8 bit

Q. なぜvoid *型をunsigned char型のポインタにキャストする必要があるのか？
C言語の企画上、メモリのバイト単位の操作にはunsigned charが最も安全で適しているから。
void *sはどんな型でも入るポインタだが、そのままでは*sのように中身を参照したり、s++のようにポインタを進められないため、キャストが必要である。
unsigned charは必ず1Byte（8bit）であることが保証されている。
intなどの方にキャストしてコピーしようとすると、メモリ上の整列の問題や型のサイズによる制約が発生し、未定義動作を引き起こす可能性がある。

Q. size_tとは？
符号なしの整数型（0または正の整数）
環境に依存し、処理系（32 bit/64 bit）環境がサポートする最大のオブジェクトサイズを格納できる十分な大きさを保証している。32 bit環境ではunsigned int、64 bitではunsigned long longなどになる。
<stddef.h>で定義されており、<stdio.h><stdlib.h><string.h>などをインクルードすれば使える。
負の数をsize_t型に代入すると、最大値（全ビット1）に変換されてしまう。

Q. unsigned intとsize_tの違いは？
size_tは「符号なし整数型（環境依存）」で、unsigned intは「符号なし32 bit整数」。あまり気にしなくていい。
size_tはメモリやサイズに関わる計算のときに使う。

Q. void *ポインタを引数に取る利点は？
型に依存せず、配列、構造体、バイナリデータなど、任意のデータを扱える。

Q. strchrやstrrchrなど、なぜ引数の文字はint型なのか？
- fgetc, getcharなどのint型を返す関数との互換性
- かつてのC言語（K&R時代）でchar型などがint型も自動的に格上げ（Default Argument Promotions）されていた名残

Q. 引数の文字列をconstにするのはなぜ？
memchrやmemcmpではメモリを比較するだけで変更しないので、安全性を高めるためである。

Q. str系とmem系の違い（strchr vs memchr, strcmp vs memcmp）
str系はヌル文字で処理を終了してしまうのに対して、
mem系は処理する長さを引数にし、ヌル文字にあたっても処理を継続する。
str系は文字列としての等価性を見るが、
mem系はメモリブロックとしての完全一致を調べる。
mem系はバイナリデータにも対応し、すべてのバイトを比較できる。

Q. mem系の利点は？
ヌル文字を含んでいても処理を継続できる。
そのため、画像データや構造体、ネットワークパケットなど、ヌル文字を含む可能性のあるバイナリデータの比較に適している。
また、長さが決まっているためCPUの最適化が効きやすく、高速で動作する。
あらかじめサイズを指定することで、予期せぬメモリ読み取りを防ぐ。

## ft_isalpha
アルファベット文字であるかどうかを調べる

## ft_isdigit
数字であるかどうかを調べる

## ft_isalnum
英数字であるかどうかを調べる

## ft_isascii
ASCII文字セットに収まる7bitのunsigned char値であるかどうかを調べる

## ft_isprint
印刷可能文字（スペースを含む）であるかどうかを調べる

## ft_strlen
`size_t	ft_strlen(const char *str)`
sが指す文字列の長さ（バイト数）を、終端のヌル文字を除いて計算する

## ft_memset
`void *memset(void *s, int c, size_t n)`
機能: sが指すメモリ領域の先頭からnバイト分を文字cで埋める関数
用途: bzeroと同じように、メモリの情報を削除（ゼロでクリア）するときなどに使われる
※バイト単位での書き込みのため、cを1(0xFF)とすると、バイト値が11111111(2進数)=-1(16進数)になる
実装のポイント: 
- sの位置を返すので、ptrに代入することでsの位置をずらさない

## ft_bzero
`void explicit_bzero(void *s, size_t n)`
機能: メモリ領域の先頭から0で埋める
用途: メモリの情報を削除（クリア）するとき
memsetと同様にバイト単位でゼロを書き込む。
ゼロクリアが目的の関数のため、ポインタを返す必要がない。
そのため、入力されたメモリ領域をunsigned char型にキャストしてから0を代入することで、
バイト値を0に、ビット値（バイナリ値）を00000000にセットする。

# ft_memcpy
`void *memcpy(void *dest, const void *src, size_t n)`
メモリ領域srcのブロックをdestにコピーする。
変更されることのないコピー元のsrcはconstにすることで安全性を高めている。
コピー領域が重なる場合は動作が保証されないため、その場合はmemmoveを使用する。
srcのメモリ位置がdestよりも小さかった場合、srcがコピー操作で上書きされてしまうことがある。

# ft_memmove
`void *memmove(void *dest, const void *src, size_t n)`
メモリ領域srcのブロックをdestにコピーする。
srcとdestが指すメモリ領域が重なり合う場合も正しくコピーされる。
srcのメモリ位置がdestよりも小さかった場合、n進んで、逆順からコピーする。
自分自身へのコピーと、コピーする長さが0だった場合は、コピーする必要がないのでdestをそのまま返す。

# ft_strlcpy
`size_t strlcpy(char *dst, const char *src, size_t size)`
コピーしたい長さを受け取り、実際コピーする予定のsrcの長さを返す。
memcpyとの違いは、文字列の操作に特化している点。
終端に必ずヌル文字を格納する。

# ft_strlcat
`size_t	ft_strlcat(char *dst, const char *src, size_t size)`

# ft_strchr
`char *strchr(const char *s, int c)`
文字列sから文字cを探し、最初に見つかった場所の位置を返す。
見つかった場合はその位置へのポインタを、ない場合はNULLを返す。
ヌル文字を探したい場合だけ最後に特別に扱い、sがヌル文字になるまでwhileループをまわしているのでそのあとでsの位置を返す。

# ft_strrchr
`char *strrchr(const char *s, int c)`
文字列sから文字cを探し、最後に現れる位置へのポインタを返す。
終端文字までループを回し、見つかるたびに目印の位置を更新。

# ft_strncmp
` int strncmp(const char *s1, const char *s2, size_t n)`
文字列s1とs2の先頭nバイトを比較し、s1-s2の値を返す。

## ft_memchr
`void *memchr(const void *s, int c, size_t n)`
メモリブロックの先頭nバイトから特定の文字cを検索する。
strchrと違って、ヌル文字を含むデータやバイナリデータも検索可能。

## ft_memcmp
`int memcmp(const void *s1, const void *s2, size_t n)`
2つのメモリブロックの先頭最大nバイトをバイト単位で比較する。
一致で0、s1>s2で正、s1<s2で負
strcmpと異なり、ヌル文字があっても比較を終了せず、指定されたバイト数まで強制的に比較する。

## ft_strnstr
`char *strnstr(const char *big, const char *little, size_t len)`
文字列 big の中から、文字列 little の最初の出現箇所を検索する。

## ft_calloc (contiguous allocation/clear allocation)
malloc (memory acllocation)関数で確保した領域を0で初期化する。
引数
count: 要素数
size: 要素1つ分の大きさ

Q. freeはしないのか？
calloc内では行わず、呼び出し元で行う。
callocはメモリを確保して返す必要があるため。
使用例: void *ptr = ft_calloc(10, sizeof(int));のあとで、free(ptr);


ft_strdup (string duplicate)
mallocで確保した領域に、引数で渡された文字列をコピーして、新しい文字列を複製する。
strcpyと異なり、コピー先のメモリ確保を自動で行う。

Q. mallocするサイズについて、なぜft_strlen(s)に+1をしている？
末尾にヌル文字を入れるため。


Part2
Part 2 で必要な実装（代表的なもの）
1. 文字列・メモリ操作の補助
•	ft_substr: 文字列の特定範囲を切り出して新しい文字列を作る。
•	ft_strjoin: 2つの文字列を結合して新しい文字列を作る。
•	ft_strtrim: 文字列の先頭と末尾から指定した文字を取り除く。
•	ft_split: 区切り文字（delimiter）を使って文字列を配列に分割する。
•	ft_strmapi: 文字列の各文字に対して関数を適用する。
2. 数値と文字列の変換
•	ft_itoa: 整数（int）を文字列（char *）に変換する。
3. 標準出力への出力（FD: ファイルディスクリプタ操作）
•	ft_putchar_fd: 指定したファイルディスクリプタに1文字書き出す。
•	ft_putstr_fd: 指定したファイルディスクリプタに文字列を書き出す。
•	ft_putendl_fd: 文字列を出力し、最後に改行を追加する。
•	ft_putnbr_fd: 数値を文字として指定したファイルディスクリプタに出力する。


ft_substr
文字列sの中で開始位置startから始まる、長さlen分の範囲をコピーした新しい文字列destをつくり、その位置を返す。


ft_strjoin
文字列s1と文字列s2を結合した文字列を返す。
s1とs2の長さ+1のぶんmallocする。


ft_strmapi (String Map Index)
文字列sの各文字に対して「指定した関数」を適用し、その結果を使って新しい文字列を作成する。文字列全体を一括で加工したいときに便利。
引数
s: 対象となる文字列
f: 各文字に適用する関数へのポインタ。この関数は文字のインデックス（unsigned int）とその文字（char）を引数として受け取り、加工後の文字を返す。


ft_striteri (String Iterate Index)
文字列sの各文字に対して「指定した関数」を適用し、元の文字列をその結果で置き換える。


Part3
t_list（構造体）
•	void *型のcontent: 保持するデータ
•	s_list型のnext: 次の要素を指すポインタ。リストの最後はNULLを指す。

ft_lstnew
contentの値をもつ、新しいノードをつくる（リストの最後？？）。


ft_lstadd_front
リストの先頭に新しい要素newを追加する。lstがリストの先頭を表す。
newの次にもともとの先頭lstをつなぎ、
lstの値をnewの値で置き換える。


ft_lstsize
リストに含まれる要素の数をカウントする。
与えられたリストの先頭の場所からひとつずつnextをたどり、同時にcountをインクリメントする。


ft_lstlast
リストの先頭が与えられ、リストの末尾の位置を返す。


ｆｔ_lstadd_back
リストの末尾に新しい要素を追加する。
もしリストの先頭がNULL=リストが空だった場合、リストの先頭であるlstにnewを代入。


ft_lstdelone
特定の要素を削除・開放する。


ft_lstclear
リスト全体を削除・開放する。


ft_lstiter
リストの各要素に対して特定の関数を適用する。


ft_lstmap
リストの各要素を関数で加工し、新しいリストを作成する。
