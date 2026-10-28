<div align="center">

# CChess

[![Release](https://img.shields.io/github/v/release/KR4DE/cchess?style=for-the-badge&labelColor=222222&logo=github&logoColor=white&color=1f6feb)](https://github.com/KR4DE/cchess/releases/latest)
![License](https://img.shields.io/github/license/KR4DE/cchess?style=for-the-badge&labelColor=222222&logo=gitbook&logoColor=white&color=db6d28)
[![CI](https://img.shields.io/github/actions/workflow/status/KR4DE/cchess/ci.yml?branch=main&style=for-the-badge&label=CI&labelColor=222222&logo=githubactions&logoColor=white)](https://github.com/KR4DE/cchess/actions/workflows/ci.yml)

### Terminal-based chess written in C

</div>

```text

      CChess
      +------------------------+
    8 | r  .  b  q  k  b  n  r |
    7 | p  p  p  p  .  p  p  p |
    6 | .  .  n  .  .  .  .  . |
    5 | .  .  .  .  p  .  .  . |
    4 | .  .  .  .  P  .  .  . |
    3 | .  .  .  .  .  N  .  . |
    2 | P  P  P  P  .  P  P  P |
    1 | R  N  B  Q  K  B  .  R |
      +------------------------+
        a  b  c  d  e  f  g  h

    > f1b5

```

## Installation

Prebuilt binaries for Linux, macOS, and Windows are available on the
[Releases](https://github.com/KR4DE/cchess/releases) page. Download the archive
for your platform, extract it, and run `cchess` from a terminal. To check the
download first, see [Verifying downloads](#verifying-downloads-optional).

**Linux**

```bash
tar -xzf cchess-linux-x86_64.tar.gz
cd cchess-linux-x86_64
./cchess
```

**macOS**

The `xattr` command is needed to remove the quarantine flag macOS adds to
`cchess` when it's downloaded, which would otherwise stop it from running.
If it fails, you can ignore it and run the next command to start the game.

```zsh
tar -xzf cchess-macos-universal.tar.gz
cd cchess-macos-universal
xattr -d com.apple.quarantine cchess
./cchess
```

**Windows**

```powershell
tar -xf cchess-windows-x86_64.zip
cd cchess-windows-x86_64
.\cchess.exe
```

### Verifying downloads (optional)

If you want to cryptographically verify that a downloaded archive was built
by this repository's [release workflow](.github/workflows/release.yml), you
can run this [GitHub CLI](https://cli.github.com/) command on the archive
before extracting it, replacing the filename with yours:

```bash
gh attestation verify cchess-linux-x86_64.tar.gz --repo KR4DE/cchess --signer-workflow KR4DE/cchess/.github/workflows/release.yml
```

## How to play

On the board, uppercase letters are White's pieces and lowercase are
Black's (e.g., `K`ing, `Q`ueen, `R`ook, `B`ishop, k`N`ight, `P`awn).
Empty squares are shown as dots (`.`).

To move a piece, enter the move in UCI-style long algebraic notation
(LAN), which is the piece's square followed by the destination square:

```text
> e2e4
```

Moving a piece onto an occupied square captures whatever is there.

To promote, add the letter of the new piece (`q`, `r`, `b`, or `n`)
to the end of the move:

```text
> e7e8q
```

To quit, enter `quit` instead of a move.

### Special moves

There are no turns, so either player can enter several moves in a row.

- **Castling:** move the king, then move the rook. For example, to castle
  kingside as White, enter `e1g1`, then `h1f1`.
- **En passant:** first capture the pawn on the square it's actually
  standing on, then move your pawn to the square *behind* it. For example,
  with a white pawn on e5 and a black pawn that just moved to d5, enter
  `e5d5`, then `d5d6`.

## Limitations

CChess is in early development. Currently:

- It's a two-player game on one computer, with no AI opponent.
- Moves are **not checked for legality**. The game moves pieces
  wherever you tell it to.
- The game does not track whose turn it is.
- There is no check, checkmate, or stalemate detection.

Note that in spite of these limitations, you are still able to play
a full, legal game of chess (see [Special moves](#special-moves)).

## Building from source

Requirements:

- A C compiler (e.g., GCC, Clang, Apple Clang, or MSVC)
- [CMake](https://cmake.org/download/) 3.26 or later

From the root of the source tree, run:

```bash
cmake -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build --config Release
```

The executable is then written to `build/`, or to `build/Release/` with
multi-config generators such as Visual Studio (the default on Windows).
