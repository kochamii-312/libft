*This project has been created as part of the 42 curriculum by kayoshid.*

# Libft

## Description

Libft は、C言語の標準ライブラリ関数を自前で再実装するプロジェクトです。  
libc の基本関数（文字列操作・メモリ操作）を `ft_` プレフィックス付きで実装し、さらに独自の便利関数と連結リスト操作関数を加えた、汎用 C ライブラリ `libft.a` を作成します。

このライブラリは今後の 42 カリキュラム全体で再利用可能なツールセットとなります。

---

## Instructions

### コンパイル

```bash
# libft.a をビルド
make

# オブジェクトファイルを削除
make clean

# libft.a とオブジェクトファイルを削除
make fclean

# 再ビルド
make re
```
<!-- 
### 自プロジェクトへの組み込み

```bash
# コンパイル時に libft.a をリンク
cc -Wall -Wextra -Werror main.c -L. -lft -o program
```

### テスト（任意）

```bash
# テスト用プログラムを別途作成してコンパイルする例
cc -Wall -Wextra -Werror test.c -L. -lft -o test && ./test
```

> **注意:** `strlcpy`・`strlcat`・`bzero` は glibc に含まれないため、Linux 環境でシステム実装と比較テストをする場合は `<bsd/string.h>` をインクルードし `-lbsd` フラグを使用してください。 -->

---

## Library Overview

### Part 1 — Libc 関数の再実装

libc の標準関数を `ft_` プレフィックスを付けて再実装したものです。外部関数には一切依存しません。

#### 文字分類

| 関数 | 説明 |
|------|------|
| `ft_isalpha` | アルファベット文字かどうかを判定する |
| `ft_isdigit` | 数字かどうかを判定する |
| `ft_isalnum` | 英数字かどうかを判定する |
| `ft_isascii` | ASCII 文字（0〜127）かどうかを判定する |
| `ft_isprint` | 印刷可能文字（スペース含む）かどうかを判定する |
| `ft_toupper` | 小文字を大文字に変換する |
| `ft_tolower` | 大文字を小文字に変換する |

> 文字分類関数の戻り値: 条件を満たす場合は `1`、満たさない場合は `0`

#### 文字列操作

| 関数 | プロトタイプ | 説明 |
|------|-------------|------|
| `ft_strlen` | `size_t ft_strlen(const char *s)` | ヌル文字を除いた文字列の長さを返す |
| `ft_strlcpy` | `size_t ft_strlcpy(char *dst, const char *src, size_t size)` | 安全な文字列コピー。必ずヌル終端する |
| `ft_strlcat` | `size_t ft_strlcat(char *dst, const char *src, size_t size)` | 安全な文字列連結。必ずヌル終端する |
| `ft_strchr` | `char *ft_strchr(const char *s, int c)` | 文字列から文字 `c` の最初の出現位置を返す |
| `ft_strrchr` | `char *ft_strrchr(const char *s, int c)` | 文字列から文字 `c` の最後の出現位置を返す |
| `ft_strncmp` | `int ft_strncmp(const char *s1, const char *s2, size_t n)` | 文字列の先頭 `n` バイトを比較する |
| `ft_strnstr` | `char *ft_strnstr(const char *big, const char *little, size_t len)` | 文字列 `big` の先頭 `len` バイト内で `little` を検索する |
| `ft_atoi` | `int ft_atoi(const char *nptr)` | 文字列を整数に変換する |

#### メモリ操作

| 関数 | プロトタイプ | 説明 |
|------|-------------|------|
| `ft_memset` | `void *ft_memset(void *s, int c, size_t n)` | メモリ領域の先頭 `n` バイトを文字 `c` で埋める |
| `ft_bzero` | `void ft_bzero(void *s, size_t n)` | メモリ領域の先頭 `n` バイトを 0 で埋める |
| `ft_memcpy` | `void *ft_memcpy(void *dest, const void *src, size_t n)` | メモリ領域をコピーする（重複不可） |
| `ft_memmove` | `void *ft_memmove(void *dest, const void *src, size_t n)` | メモリ領域をコピーする（重複対応） |
| `ft_memchr` | `void *ft_memchr(const void *s, int c, size_t n)` | メモリブロックの先頭 `n` バイトから文字 `c` を検索する |
| `ft_memcmp` | `int ft_memcmp(const void *s1, const void *s2, size_t n)` | 2 つのメモリブロックを先頭 `n` バイト比較する |

#### メモリ確保

| 関数 | プロトタイプ | 説明 |
|------|-------------|------|
| `ft_calloc` | `void *ft_calloc(size_t nmemb, size_t size)` | `nmemb × size` バイトを確保し、0 で初期化する |
| `ft_strdup` | `char *ft_strdup(const char *s)` | 文字列を複製した新しい文字列を返す |

---

### Part 2 — 追加関数

libc に含まれないか、異なる形で存在する独自の便利関数です。

#### 文字列操作

| 関数 | プロトタイプ | 説明 |
|------|-------------|------|
| `ft_substr` | `char *ft_substr(char const *s, unsigned int start, size_t len)` | 文字列 `s` の `start` 番目から最大 `len` 文字の部分文字列を返す |
| `ft_strjoin` | `char *ft_strjoin(char const *s1, char const *s2)` | `s1` と `s2` を連結した新しい文字列を返す |
| `ft_strtrim` | `char *ft_strtrim(char const *s1, char const *set)` | `s1` の先頭と末尾から `set` に含まれる文字を取り除いた文字列を返す |
| `ft_split` | `char **ft_split(char const *s, char c)` | 区切り文字 `c` で文字列 `s` を分割した文字列配列を返す（NULL 終端） |
| `ft_strmapi` | `char *ft_strmapi(char const *s, char (*f)(unsigned int, char))` | 文字列の各文字に関数 `f` を適用した新しい文字列を返す |
| `ft_striteri` | `void ft_striteri(char *s, void (*f)(unsigned int, char*))` | 文字列の各文字に関数 `f` を適用し、元の文字列を書き換える |

#### 数値変換

| 関数 | プロトタイプ | 説明 |
|------|-------------|------|
| `ft_itoa` | `char *ft_itoa(int n)` | 整数を文字列に変換する（負数対応） |

#### ファイルディスクリプタへの出力

| 関数 | プロトタイプ | 説明 |
|------|-------------|------|
| `ft_putchar_fd` | `void ft_putchar_fd(char c, int fd)` | 文字 `c` を指定した fd に出力する |
| `ft_putstr_fd` | `void ft_putstr_fd(char *s, int fd)` | 文字列 `s` を指定した fd に出力する |
| `ft_putendl_fd` | `void ft_putendl_fd(char *s, int fd)` | 文字列 `s` を指定した fd に出力し、改行を追加する |
| `ft_putnbr_fd` | `void ft_putnbr_fd(int n, int fd)` | 整数 `n` を指定した fd に出力する |

> fd の例: `1` = 標準出力、`2` = 標準エラー出力

---

### Part 3 — 連結リスト

`t_list` 構造体を使った連結リスト操作関数です。`libft.h` に以下の構造体が定義されています。

```c
typedef struct s_list
{
    void            *content;  // ノードが保持するデータ（任意の型）
    struct s_list   *next;     // 次のノードへのポインタ（末尾は NULL）
}   t_list;
```

| 関数 | プロトタイプ | 説明 |
|------|-------------|------|
| `ft_lstnew` | `t_list *ft_lstnew(void *content)` | 新しいノードを作成する（`next` は NULL） |
| `ft_lstadd_front` | `void ft_lstadd_front(t_list **lst, t_list *new)` | リストの先頭に新しいノードを追加する |
| `ft_lstsize` | `int ft_lstsize(t_list *lst)` | リストのノード数を返す |
| `ft_lstlast` | `t_list *ft_lstlast(t_list *lst)` | リストの最後のノードを返す |
| `ft_lstadd_back` | `void ft_lstadd_back(t_list **lst, t_list *new)` | リストの末尾に新しいノードを追加する |
| `ft_lstdelone` | `void ft_lstdelone(t_list *lst, void (*del)(void *))` | ノード 1 つを削除・解放する（次のノードは解放しない） |
| `ft_lstclear` | `void ft_lstclear(t_list **lst, void (*del)(void *))` | リスト全体を削除・解放し、ポインタを NULL に設定する |
| `ft_lstiter` | `void ft_lstiter(t_list *lst, void (*f)(void *))` | リストの各ノードのコンテンツに関数 `f` を適用する |
| `ft_lstmap` | `t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))` | 各ノードに関数 `f` を適用した新しいリストを作成する |

---

## Key Concepts

**`size_t` とは？**  
符号なしの整数型（0または正の整数）
環境に依存し、処理系（32 bit/64 bit）環境がサポートする最大のオブジェクトサイズを格納できる十分な大きさを保証している。32 bit環境ではunsigned int、64 bitではunsigned long longなどになる。
`<stddef.h>` で定義されており、`<stdio.h><stdlib.h><string.h>` などをインクルードすれば使える。
負の数を `size_t` 型に代入すると、最大値（全ビット1）に変換されてしまう。

**`unsigned int` と `size_t` の違いは？**  
size_tは「符号なし整数型（環境依存）」で、`unsigned int` は「符号なし32 bit整数」。
`size_t` はメモリやサイズに関わる計算のときに使う。

**なぜ `void *` を `unsigned char *` にキャストするのか？**  
C 言語の規格上、バイト単位のメモリ操作には `unsigned char` が最も安全で適しているから。`void *s` はどんな型でも入るポインタだが、そのままでは `*s` のように中身を参照したり、`s++` のようにポインタを進められないため、キャストが必要である。`unsigned char` は必ず 1 バイト(8 bit)であることが保証されている。`int` などの型にキャストしてコピーしようとすると、メモリ上の整列の問題や型のサイズによる制約が発生し、未定義動作を引き起こす可能性がある。

**`str` 系と `mem` 系の違い**  
`str` 系はヌル文字で処理を終了しますが、`mem` 系は指定バイト数まで処理を継続します。そのため `mem` 系は画像データや構造体などのバイナリデータの操作に適しています。

**`memcpy` と `memmove` の違い**  
コピー元とコピー先のメモリ領域が重なる場合、`memcpy` は動作が保証されません。重複する可能性がある場合は `memmove` を使用します。

**`mem`系の利点は？**  
ヌル文字を含んでいても処理を継続できる。
そのため、画像データや構造体、ネットワークパケットなど、ヌル文字を含む可能性のあるバイナリデータの比較に適している。
また、長さが決まっているためCPUの最適化が効きやすく、高速で動作する。
あらかじめサイズを指定することで、予期せぬメモリ読み取りを防ぐ。

---

## Resources

### 参考資料

- [C 言語 man ページ (Linux man-pages)](https://man7.org/linux/man-pages/)
- [cppreference.com — C 標準ライブラリ](https://en.cppreference.com/w/c)
- [42 Norm v3](https://github.com/42School/norminette)
- [glibc と BSD libc の違いについて](https://www.gnu.org/software/libc/manual/)

### AI の使用について

本プロジェクトでは、以下の用途に Claude, GitHub Copilot, Gemini を使用しました。

- 各関数の動作・仕様の概念理解
- 各関数の記述の改善
- README の構成・記述の改善
