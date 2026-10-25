*This project has been created as part of the 42 curriculum by thaga.*

# Libft

## Description

Libft は、C 言語の標準ライブラリの関数や、日常的に使う関数を実装し、`libft.a`にまとめるプロジェクトです。

**目的**

- 標準関数の仕組みを、実装を通して理解する。
- メモリ管理(`malloc` / `free`)、ポインタ、文字列操作を基礎から身につける。
- 今後の課題で使い回せる、自分専用のライブラリを作る。

**概要**

ライブラリは 3 つのパートで構成されています。

1. **Part 1 - libc の再実装**:`ft_` を頭に付けた、標準関数と同じ挙動の関数群
2. **Part 2 - 追加関数**:文字列の加工、分割、数値変換、ファイルディスクリプタへの出力など
3. **Part 3 - 連結リスト**:`t_list` 構造体と、それを操作する関数群

## Instructions

### コンパイル

リポジトリのルートで次のコマンドを実行します。

```bash
make
```

`cc` と `-Wall -Wextra -Werror` でコンパイルされ、ルートに `libft.a` が生成されます。

| コマンド | 内容 |
|---|---|
| `make` / `make all` | `libft.a` を作成する |
| `make clean` | オブジェクトファイル(`.o`)を削除する |
| `make fclean` | オブジェクトファイルと `libft.a` を削除する |
| `make re` | `fclean` した後に再ビルドする |

### 自分のプログラムで使う

`libft.h` をインクルードし、`libft.a` をリンクします。

```c
#include "libft.h"

int main(void)
{
    ft_putendl_fd("Hello, libft!", 1);
    return (0);
}
```

```bash
cc -Wall -Wextra -Werror main.c -L. -lft -o a.out
```

(`main.c` が別のフォルダにある場合は、`-L` と `-I` でそれぞれ `libft.a` と `libft.h` の場所を指定してください。)

## ライブラリの詳細

作成したライブラリは `libft.a` として提供され、関数は `libft.h` で宣言されています。

### ファイル構造
```
/common-core/Libft
|--ft_atoi.c
|--ft_bzero.c
|--ft_calloc.c
|--ft_isalnum.c
|--ft_isalpha.c
|--ft_isascii.c
|--ft_isdigit.c
|--ft_isprint.c
|--ft_itoa.c
|--ft_lstadd_back.c
|--ft_lstadd_front.c
|--ft_lstclear.c
|--ft_lstdelone.c
|--ft_lstiter.c
|--ft_lstlast.c
|--ft_lstmap.c
|--ft_lstnew.c
|--ft_lstsize.c
|--ft_memchr.c
|--ft_memcmp.c
|--ft_memcpy.c
|--ft_memmove.c
|--ft_memset.c
|--ft_putchar_fd.c
|--ft_putendl_fd.c
|--ft_putnbr_fd.c
|--ft_putstr_fd.c
|--ft_split.c
|--ft_strchr.c
|--ft_strdup.c
|--ft_striteri.c
|--ft_strjoin.c
|--ft_strlcat.c
|--ft_strlcpy.c
|--ft_strlen.c
|--ft_strmapi.c
|--ft_strncmp.c
|--ft_strnstr.c
|--ft_strrchr.c
|--ft_strtrim.c
|--ft_substr.c
|--ft_tolower.c
|--ft_toupper.c
|--libft.h
|--Makefile
|--README.md
```

### Part 1 - libc の再実装

標準関数と同じプロトタイプ・挙動で、名前の頭に `ft_` が付きます。

| 分類 | 関数 |
|---|---|
| 文字判定・変換 | `ft_isalpha`, `ft_isdigit`, `ft_isalnum`, `ft_isascii`, `ft_isprint`, `ft_toupper`, `ft_tolower` |
| 文字列 | `ft_strlen`, `ft_strlcpy`, `ft_strlcat`, `ft_strchr`, `ft_strrchr`, `ft_strncmp`, `ft_strnstr`, `ft_strdup` |
| メモリ | `ft_memset`, `ft_bzero`, `ft_memcpy`, `ft_memmove`, `ft_memchr`, `ft_memcmp`, `ft_calloc` |
| 変換 | `ft_atoi` |

### Part 2 - 追加関数

| 関数 | 内容 |
|---|---|
| `ft_substr` | 文字列から部分文字列を切り出して返す |
| `ft_strjoin` | 2 つの文字列を連結した新しい文字列を返す |
| `ft_strtrim` | 文字列の前後から指定した文字集合を取り除く |
| `ft_split` | 区切り文字で分割し、NULL 終端の文字列配列を返す |
| `ft_itoa` | 整数を文字列に変換する(負数に対応) |
| `ft_strmapi` | 各文字に関数を適用して新しい文字列を作る |
| `ft_striteri` | 各文字に関数を適用する(文字を直接変更できる) |
| `ft_putchar_fd` | 文字を指定の fd に出力する |
| `ft_putstr_fd` | 文字列を指定の fd に出力する |
| `ft_putendl_fd` | 文字列と改行を指定の fd に出力する |
| `ft_putnbr_fd` | 整数を指定の fd に出力する |

### Part 3 - 連結リスト

次の構造体を使用します。

```c
typedef struct s_list
{
    void            *content;
    struct s_list   *next;
}   t_list;
```

| 関数 | 内容 |
|---|---|
| `ft_lstnew` | 新しいノードを作る |
| `ft_lstadd_front` | リストの先頭にノードを追加する |
| `ft_lstsize` | ノード数を数える |
| `ft_lstlast` | 最後のノードを返す |
| `ft_lstadd_back` | リストの末尾にノードを追加する |
| `ft_lstdelone` | 1 つのノードを解放する |
| `ft_lstclear` | ノードとそれ以降をすべて解放し、ポインタを NULL にする |
| `ft_lstiter` | 各ノードの content に関数を適用する |
| `ft_lstmap` | 各 content に関数を適用した新しいリストを作る |

## Resources

### AI の利用について

- READMEの雛形を生成してもらい、構成の理解と作成の補助に使用した。
- `const` を引数に取る場合の扱い方とキャストについて質問した。
- 連結リストのテストケースの作り方が分からなかったため、考え方のヒントと使用例を教えてもらった。
- `size_t` と `unsigned int` の使い分けについて質問した。
- `calloc` と `malloc` の使い分けと使いどころについて質問した。
- `ft_memmove` のバグ解消に時間がかかったため、考慮漏れを指摘してもらった。コードは自分で実装した。
- Makefileの書き方について質問し、完成後のチェックをしてもらった。
- `ar` の使い方と `.o` ファイルの扱いについて説明を受けた。各行の意味は自分で調べ、自分で記述した。
- ヘッダファイルに `#include` をまとめて書くことの是非について質問した。
- `isascii` のテストで、1バイトずつテストする方法を教えてもらった。
- Gitで誤ってpushしたファイルを外す方法について質問した。
- READMEの一部文章の添削に仕様した。
- 連結リストのテストコードで、`main` の終了前に解放漏れを直す方法を教えてもらった。
- ダングリングポインタと、`free` 後のNULL代入の必要性について質問した。
- `ft_memcpy` の引数のNULLチェックの要否について質問した。

### 参考資料

- [man ページ](https://man7.org/linux/man-pages/):各 libc 関数の仕様の確認
- [ascii表](https://www3.nit.ac.jp/~tamura/ex2/ascii.html):アスキーコードの確認。表示可能文字などの確認。
- [memset](https://cgengo.sakura.ne.jp/memset.html): memsetの仕様理解。
- [memcpy](https://cgengo.sakura.ne.jp/memcpy.html):memcpyの仕様理解。
- [memmove](https://cgengo.sakura.ne.jp/memmove.html):memmoveの仕様理解。
- [strchr](https://cgengo.sakura.ne.jp/strchr.html) :strchrの仕様理解。
- [strrchr](https://cgengo.sakura.ne.jp/strrchr.html) :strrchrの仕様理解。
- [連結リスト](https://zenn.dev/tn_a/articles/9807f616316daa) : 連結リストのノードの返し方、追加の方法などを学習。
- [Libtools](https://www.klab.com/jp/blog/tech/2015/1047107113.html) :Libtoolとは？
- [C99規格](https://ja.wikipedia.org/wiki/C99) :C99規格の理解。
- [restrict修飾](https://ja.cppreference.com/c/language/restrict) :restrict修飾の大枠の理解。
- [void *](https://qiita.com/mizcii/items/38aa405122542771a23f) : 汎用ポインタ（void *）とは。
- [memcpyとmemmove](https://hiroyukichishiro.com/memcpy-and-memmove-functions-in-c-language/#memcpymemmove-3) :memcpy, memmove関数の詳細説明。