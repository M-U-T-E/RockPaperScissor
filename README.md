# Rock Paper Scissor
<p align="center">
    <img src="https://github.com/M-U-T-E/RockPaperScissor/blob/main/assets/Intro.gif?raw=true" alt="Intro.gif" width="1000"/>
</p>
A classic command-line implementation of the Rock Paper Scissor game. Challenge the computer to a single, instant match to see who comes out on top!

---
## 🎮 How to Play

The rules are simple:

* **Rock** beats **Scissor**
* **Scissor** beats **Paper**
* **Paper** beats **Rock**

To play, you must pass your choice (rock, paper, or scissor) as a command-line argument when running the executable. The game will instantly show the result of the single round.

<img src="https://github.com/M-U-T-E/RockPaperScissor/blob/main/assets/Demo.gif?raw=true" alt="Demo.gif" width="600"/>

---

## ⚙️ Command-line Arguments

You must use one of the following arguments to play a single round.

| Argument(s)                                    | Description                                        |
| :--------------------------------------------- | :------------------------------------------------- |
| `r`, `-r`, `rock`, `-rock`, `--rock`           | Selects **"rock"** for your move.        |
| `p`, `-p`, `paper`, `-paper`, `--paper`        | Selects **"paper"** for your move.       |
| `s`, `-s`, `scissor`, `-scissor`, `--scissor` | Selects **"scissor"** for your move. |
| `--help`, `-h`                                 | Displays the help message and exits.               |
| `--version`                                    | Outputs version information and exits.             |

---

## 💾 Installation from Release

For most users, the easiest way to install the game is to download a pre-built package from the **[Releases page](https://github.com/M-U-T-E/RockPaperScissor/releases)**.

### Windows 🪟

1.  Download the installer file, which will be named something like `RockPaperScissor-1.2.1-windows-latest.exe`.
2.  Run the installer and follow the on-screen instructions.

    > **Important**: During installation, make sure to check the box that says **"Add to environment variable PATH"**. This allows you to run the game from any folder in your terminal (Command Prompt, PowerShell, etc.) by simply typing `rpsg --rock`.

### Debian/Ubuntu (`.deb`)

1.  Download the `.deb` file, which will be named something like `RockPaperScissor-1.2.1-ubuntu-latest.deb`.
2.  Install it using your package manager. From the terminal, you can run:
    ```bash
    sudo dpkg -i RockPaperScissor-*-ubuntu-latest.deb
    ```

### Red Hat/Fedora/CentOS (`.rpm`)

1.  Download the `.rpm` file, which will be named something like `RockPaperScissor-1.2.1-redhat-latest.rpm`.
2.  Install it using your package manager. From the terminal, you can run:
    ```bash
    sudo rpm -i RockPaperScissor-*-redhat-latest.rpm
    ```

---
## 🚀 Getting Started (from Source)

These instructions are for developers who want to compile the game from the source code. To compile the game, you'll need **CMake** and the **GCC compiler toolchain**. Other compilers like Clang or MSVC are not supported.

### On Linux or macOS (with GCC)

1.  **Clone the repository:**
    ```bash
    git clone [https://github.com/M-U-T-E/RockPaperScissor.git](https://github.com/M-U-T-E/RockPaperScissor.git)
    cd RockPaperScissor
    ```

2.  **Configure and build the project:**
    ```bash
    mkdir build
    cmake -S . -B build -G "Unix Makefiles"
    cmake --build build --config Release
    ```

3.  **Run the game:**
    ```bash
    ./build/rpsg --rock
    ```

### On Windows (with MinGW)

1.  **Clone the repository:**
    ```bash
    git clone [https://github.com/M-U-T-E/RockPaperScissor.git](https://github.com/M-U-T-E/RockPaperScissor.git)
    cd RockPaperScissor
    ```

2.  **Build the project:**
    ```bash
    mkdir build && cd build
    cmake -G "MinGW Makefiles" ..
    mingw32-make
    ```

3.  **Run the game:**
    ```bash
    ./rpsg.exe --paper
    ```

---
## 📦 Compiling and Packaging (from Source)

This project uses CPack to create the distributable packages found on the releases page. The GCC compiler toolchain is required for all packaging operations (GCC for Linux, MinGW for Windows).

Convenient scripts for these operations are available in the root **[makefile](https://github.com/M-U-T-E/RockPaperScissor/blob/main/makefile)**. The following commands should be run from the root directory of the project.

### For Debian (`.deb`)

To create a `.deb` package, simply run:
```bash
make pkgdeb
```
### For Red Hat / Fedora (`.rpm`)

To create an .rpm package, simply run:
```bash
make pkgrpm
```
### For Windows (NSIS Installer)

To create a Windows installer, you'll need MinGW and NSIS. Simply run:
```bash
make pkgwin
```
If you do not have make installed on Windows, you can run the commands manually. These can be found in the [makefile](https://github.com/M-U-T-E/RockPaperScissor/blob/main/makefile) on [this line](https://github.com/M-U-T-E/RockPaperScissor/blob/df37c14098c835c5d733674c4b3c2bba9b8b467a/makefile#L25) till the end.

**Note:** For more detail on the automated build and packaging process, you can inspect the [GitHub Actions workflow files](https://github.com/M-U-T-E/RockPaperScissor/tree/main/.github/workflows) in this repository.
